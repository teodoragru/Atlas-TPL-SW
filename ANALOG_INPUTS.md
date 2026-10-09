# AD4130-8 — analogni ulazi (Atlas TPL / NanoPi)

Beleške sa testiranja analognih ulaza preko AD4130-8 (program `ad4130_test.c`):
PT100 ulazi, naponski ulazi i strujni ulazi.

---

## 1. Program `ad4130_test`

```bash
make ad4130_test            # arm-linux-gnueabihf-gcc, staticki
scp ad4130_test root@10.1.49.18:/root/
./ad4130_test -h
```

| Opcija   | Namena                                                        |
|----------|---------------------------------------------------------------|
| `-p N`   | AINP (AIN0..AIN15)                                            |
| `-m N`   | AINM (0..15 ili `avss` = single-ended)                        |
| `-b`     | bipolarno kodiranje (offset binary)                           |
| `-k F`   | faktor za prikaz napona na konektoru (za Vin kanale 4.3)      |
| `-t N`   | PT100 kanal 1..4 (4-žično ratiometrijski)                     |
| `-B N`   | burnout test (provera prekinutog ulaza)                       |
| `-d`     | dijagnostika: (AVDD − AVSS)/6                                 |
| `-n N`   | broj uzoraka (0 = do Ctrl+C)                                  |

Unipolarno vs bipolarno: vidi §2.4 (važi za sve ulaze).

---

## 2. PT100 ulazi

Test kanala 2 (2026-10-09). Umesto PT100 sonde na ulaz je vezan običan
otpornik ~100 Ω, da se proveri merni lanac
(IOUT → otpornik → Rref → REFIN1, ratiometrijsko merenje).

### 2.1. Postavka

Program: `ad4130_test.c`, opcija `-t N` (PT100 kanal N, 4-žično ratiometrijski).

| Parametar          | Vrednost                                                |
|--------------------|---------------------------------------------------------|
| Ekscitacija        | IOUT0 = 200 µA                                          |
| Referenca          | REFIN1 = napon na Rref (R25 4k99 0.1 %), bafer uključen |
| Gain               | 8 → pun opseg = Rref / 8 ≈ 624 Ω                        |
| Filter             | sinc3, FS = 48 → 50 SPS                                 |
| Formula            | `R = kod / 2^24 * Rref / gain` (struja se skraćuje)     |

Mapiranje kanala: IIN = AIN(3N−3), VOUTP = AIN(3N−2), VOUTN = AIN(3N−1).
Za **kanal 2** (`-t 2`), LFCSP pinovi AD4130:

| Signal     | AIN  | Pin AD4130 |
|------------|------|-----------:|
| IOUT (IIN) | AIN3 | 7          |
| VINP       | AIN4 | 8          |
| VINN       | AIN5 | 9          |
| povratak   | IREF → Rref → REFIN1 | 12/13 (preko 4k99) |

#### Povezivanje otpornika

- **kraj A**: IOUT (pin 7) **i** VINP (pin 8)
- **kraj B**: VINN (pin 9) **i** REF (povratak struje)

VINP mora biti na strani gde struja **ulazi** (IOUT), VINN na strani gde
**izlazi** (REF). U suprotnom je AIN4 − AIN5 negativno.

```bash
./ad4130_test -t 2 -n 20        # unipolarno (podrazumevano)
./ad4130_test -t 2 -b -n 20     # bipolarno, vidi se i znak
```

---

### 2.2. Rezultati

Konfiguracija u svim pokretanjima OK: ID = 0x05, CONFIG_0 = 0x18C6,
CHANNEL_0 = 0x808503, FILTER_0 = 0x002030, MCLK ≈ 77.0 kHz.

#### 2.2.1 Pogrešno povezano (VINP/VINN zamenjeni), unipolarno

```
kod = 0 (0x000000)  R = 0.0000 ohm  T = -242.021 C
[ERROR registar] 0x0080: ADC_ERR(klipovanje/saturacija)
```

Napon AIN4 − AIN5 je negativan (≈ −19.7 mV), unipolarni kod ne može ispod 0
→ klipuje na 0 i postavlja ADC_ERR.

#### 2.2.2 Pogrešno povezano, bipolarno (`-b`)

```
kod = 7063188 (0x6BC694)  R = -98.5540 ohm
STATISTIKA (20): R = -98.5558 ohm, p-p = 8.6 mohm, sigma = 2.8 mohm (~7.3 mC)
```

Kod < 0x800000 → negativan napon. Apsolutna vrednost ~98.6 Ω: struja teče,
referenca radi, samo je znak obrnut. Rešenje: zameniti žice VINP i VINN.

#### 2.2.3 Ispravno povezano, unipolarno — 20 uzoraka

```
kod = 2653328 (0x287C90)  R = 98.6465 ohm  T = -3.461 C
STATISTIKA (20): R = 98.6477 ohm (T = -3.458 C), min = 98.6444, max = 98.6523
                 p-p = 7.9 mohm, sigma = 2.4 mohm (~6.0 mC)
```

#### 2.2.4 Ispravno povezano, unipolarno — 2000 uzoraka (~40 s)

```
STATISTIKA (2000): R = 98.6684 ohm (T = -3.405 C), min = 98.6545, max = 98.6779
                   p-p = 23.5 mohm, sigma = 4.3 mohm (~10.9 mC)
```

| Merenje           | R srednje  | sigma            | p-p                  |
|-------------------|------------|------------------|----------------------|
| 20 uz. (0.4 s)    | 98.6477 Ω  | 2.4 mΩ (~6 mK)   | 7.9 mΩ               |
| 2000 uz. (40 s)   | 98.6684 Ω  | 4.3 mΩ (~11 mK)  | 23.5 mΩ (~0.06 °C)   |

---

### 2.3. Zaključci

- **Merni lanac PT100_2 radi.** Konfiguracija, ekscitacija, referenca i
  ratiometrijski proračun su ispravni.
- **Kratkoročni šum ≈ 2.4 mΩ** (≈ 0.5 µV na ulazu, ~6 mK) — odlično za PT100.
- **Na 40 s postoji spori drift ~+20 mΩ** (srednja vrednost 98.648 → 98.668 Ω,
  poslednji uzorci ~98.673 Ω). Nije šum ADC-a; verovatni uzroci:
  1. temperatura samog otpornika (običan otpornik 50–200 ppm/K, 20 mΩ ≈ 200 ppm;
     zagrejan rukom pri prevezivanju),
  2. termo-EMF na spojevima (20 mΩ × 200 µA = 4 µV),
  3. zagrevanje ploče / tempko Rref posle uključenja.
  Samozagrevanje strujom je zanemarljivo (200 µA² × 100 Ω = 4 µW).
- Ceo opseg kolebanja (~0.06 °C) je ispod tačnosti PT100 klase A (±0.15 °C na 0 °C).
- Razlika 98.556 Ω (obrnuto) vs 98.648 Ω (ispravno) ≈ 0.09 Ω — promena mesta
  kontakta pri prevezivanju, ne greška ADC-a.
- Vrednost otpornika (98.65 Ω) treba potvrditi multimetrom.

---

### 2.4. Unipolarno vs bipolarno

ADC uvek meri isti diferencijalni napon **AINP − AINM** (ovde AIN4 − AIN5) kroz
PGA. Režim menja samo kodovanje rezultata i opseg koji kodovi pokrivaju.
Ovde je V_REF = 200 µA × 4990 Ω ≈ 1.0 V, pun opseg sa gain 8 ≈ 125 mV.

|                   | Unipolarno (straight binary) | Bipolarno (offset binary)      |
|-------------------|------------------------------|--------------------------------|
| Opseg             | 0 … +V_REF/gain              | −V_REF/gain … +V_REF/gain      |
| 0 V               | 0x000000                     | 0x800000                       |
| Negativan napon   | klipuje na 0 + ADC_ERR       | vidi se sa znakom              |
| LSB               | 125 mV / 2^24 ≈ 7.4 nV       | 250 mV / 2^24 ≈ 14.9 nV        |

Za PT100 su oba režima upotrebljiva (LSB je daleko ispod šuma ~0.5 µV).
Unipolarno je prirodno jer je napon na RTD-u uvek pozitivan; bipolarno je
korisno za dijagnostiku — obrnuto povezivanje se odmah vidi kao negativan R.

---

### 2.5. Sledeći koraci

- Izmeriti otpornik multimetrom i uporediti sa 98.65 Ω.
- Test stabilnosti sa otpornikom malog tempka (0.1 %, ≤ 25 ppm/K), bez diranja,
  posle par minuta stabilizacije, duža serija (`-n 6000`, ~2 min).
- Dodati u program snimanje u CSV (vreme, kod, R, T) i nacrtati grafik
  da se vidi oblik drifta (linearan / eksponencijalan / skokovi).
- Ponoviti test na kanalima 1, 3 i 4.

---

## 3. Naponski ulazi

> TODO: mapiranje ulaza (konektor → AIN pin), delitelj (faktor 4.3),
> komanda i rezultati merenja.

---

## 4. Strujni ulazi

> TODO: mapiranje ulaza, šant otpornik, komanda i rezultati merenja.
