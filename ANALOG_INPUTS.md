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

#### 2.2.5 Poređenje sa unimerom

Otpornik na kanalu 2 (VINP2A / VINN2A) izmeren unimerom: **98.2 Ω**.
ADC je za isti otpornik davao **98.65 Ω** (20 uz.), odnosno 98.67 Ω (2000 uz.).
Razlika ≈ 0.45 Ω (≈ 0.46 %).

> **Napomena:** otvoreno je pitanje koliko greši koji instrument — unimer
> ili ADC.

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
- Unimer pokazuje 98.2 Ω, ADC 98.65 Ω (vidi §2.2.5); pitanje je koliko
  greši koji instrument.

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

- Test stabilnosti sa otpornikom malog tempka (0.1 %, ≤ 25 ppm/K), bez diranja,
  posle par minuta stabilizacije, duža serija (`-n 6000`, ~2 min).
- Dodati u program snimanje u CSV (vreme, kod, R, T) i nacrtati grafik
  da se vidi oblik drifta (linearan / eksponencijalan / skokovi).
- Ponoviti test na kanalima 1, 3 i 4.

---

## 3. Naponski ulazi

Test na **kanalu 2**: ulaz VIN2 → **AIN1** na AD4130.

### 3.1. Postavka

| Parametar      | Vrednost                                                     |
|----------------|--------------------------------------------------------------|
| Izvor          | 7.00 V (rezolucija izvora 10 mV), jedan napon, nije menjan   |
| Delitelj       | 10k / (10k + 33k) → faktor 4.3                               |
| Očekivano      | na AIN1: 7 V / 4.3 ≈ 1.6279 V                                |

### 3.2. Rezultati

```bash
./ad4130_test -p 1 -n 0        # AIN1 prema AVSS, unipolarno, gain 1, VREF interna 2.5 V
```

Konfiguracija OK: ID = 0x05, CONFIG_0 = 0x0020, CHANNEL_0 = 0x803100,
FILTER_0 = 0x002030, MCLK ≈ 77.0 kHz.

```
#1     CH0 (AIN1-AVSS)  kod=10916625 (0xA69311)  Vadc=+1.626704 V
...
STATISTIKA (144 uzoraka): srednja = +1.626695 V, min = +1.626671 V, max = +1.626723 V,
                          p-p = 51.9 uV, sigma = 9.7 uV
```

| Veličina              | Na AIN1 (ADC)   | Na konektoru (× 4.3) |
|-----------------------|-----------------|----------------------|
| Očekivano             | 1.627907 V      | 7.000 V              |
| Izmereno (srednje)    | 1.626695 V      | 6.9948 V             |
| Razlika               | −1.21 mV        | −5.2 mV (−0.07 %)    |
| sigma                 | 9.7 µV          | ~42 µV               |
| p-p                   | 51.9 µV         | ~0.22 mV             |

### 3.3. Zaključci

- **Naponski ulaz VIN2 radi.** Izmereno 6.995 V za podešenih 7 V.
- Razlika −5.2 mV je ispod rezolucije izvora (10 mV), pa se iz ovog merenja
  ne može reći koliko greši ADC, a koliko izvor / tolerancija delitelja.
- Šum je mali: sigma ≈ 10 µV na ADC-u (≈ 42 µV na konektoru).
- Meren je samo jedan napon (7 V); linearnost na celom opsegu nije proverena.

---

## 4. Strujni ulazi

Test na **kanalu 1**: diferencijalno **AIN4 − AIN5** na AD4130.

### 4.1. Postavka

| Parametar      | Vrednost                                                          |
|----------------|-------------------------------------------------------------------|
| Šant           | 30 Ω                                                              |
| Izvor          | 0.30 V                                                            |
| Povezivanje    | izvor (+) → unimer (mA) → konektor; drugi konektor → izvor (−)    |
| Struja (unimer)| **10.1 mA**                                                       |
| Očekivano      | na šantu: 10.1 mA × 30 Ω = 0.303 V                                |
| ADC            | bipolarno (offset binary), gain 1, VREF interna 2.5 V             |

### 4.2. Rezultati

```bash
./ad4130_test -p 4 -m 5 -b -n 2000   # AIN4 - AIN5, bipolarno, gain 1, VREF interna 2.5 V
```

Konfiguracija OK: ID = 0x05, CONFIG_0 = 0x0020, CHANNEL_0 = 0x808500,
FILTER_0 = 0x002030, ADC_CONTROL = 0x4710 (BIPOLAR), MCLK ≈ 77.0 kHz.

Tok merenja (2000 uzoraka, ~40 s):

| Uzorci       | Šta se dešava                         | Vadc                          |
|--------------|---------------------------------------|-------------------------------|
| #1 – #68     | struja još nije puštena (0 mA)        | ≈ +6 µV (offset, ~20 kodova)  |
| #69 – #76    | puštanje struje (prelaz)              | 0 → −0.305 V                  |
| #77 – #2000  | ustaljeno, struja teče                | ≈ −0.3052 … −0.3053 V         |

```
#1     CH0 (AIN4-AIN5)  kod= 8388634 (0x80001A) [rel. +26]  Vadc=+0.000008 V
...
#69    CH0 (AIN4-AIN5)  kod= 8376472 (0x7FD098) [rel. -12136]  Vadc=-0.003617 V
#70    CH0 (AIN4-AIN5)  kod= 8034172 (0x7A977C) [rel. -354436]  Vadc=-0.105630 V
#71    CH0 (AIN4-AIN5)  kod= 7496343 (0x726297) [rel. -892265]  Vadc=-0.265916 V
#72    CH0 (AIN4-AIN5)  kod= 7367273 (0x706A69) [rel. -1021335]  Vadc=-0.304382 V
...
#2000  CH0 (AIN4-AIN5)  kod= 7364240 (0x705E90) [rel. -1024368]  Vadc=-0.305285 V

STATISTIKA (2000 uzoraka): srednja = -0.294608 V, min = -0.305454 V, max = +0.000056 V,
                           p-p = 305509.6 uV, sigma = 55880.9 uV
```

Statistika programa obuhvata i uzorke bez struje i prelaz, pa nije merodavna.
Srednja vrednost samo ustaljenog dela (#77–#2000, 1924 uzorka), izračunata iz
ukupne sume minus prvih 76 uzoraka:

| Veličina                      | Vrednost                    |
|-------------------------------|-----------------------------|
| Vadc srednje (#77–#2000)      | −0.305261 V                 |
| **I = \|Vadc\| / 30 Ω**     | **10.175 mA**               |
| Unimer                        | 10.1 mA                     |
| Razlika                       | +0.075 mA (+0.75 %)         |
| Offset bez struje (#1–#68)    | ≈ +6 µV (≈ 0.2 µA)          |

Uočeno u ustaljenom delu:

- **Spori pomak na početku:** prvih ~150 uzoraka ≈ −0.30518 V, posle se
  ustali na ≈ −0.30529 V (≈ 0.1 mV, ≈ 4 µA).
- **Poremećaj #885–#960** (~1.5 s): vrednost skoči do −0.30428 V (≈ +1 mV,
  ≈ 33 µA) i vrati se. Verovatno izvor/unimer (dodir, pomeranje kabla).
- **Kratki parni šiljci** ± 0.1–0.2 mV (npr. #461/#462, #1105/#1106,
  #1234/#1235, #1702/#1703): jedan uzorak gore, sledeći dole. Javljaju se
  i **bez struje** (#25/#26, #64–#66), pa ne potiču od izvora — neka
  smetnja u sistemu.
- Van ovih događaja uzorci se kreću u opsegu ≈ ±30 µV (≈ ±1 µA).

### 4.3. Zaključci

- **Strujni ulaz kanala 1 radi.** ADC daje 10.175 mA, unimer 10.1 mA.
- **Nula je dobra:** bez struje ≈ +6 µV (≈ 0.2 µA).
- **Znak je negativan** (kod < 0x800000): AIN4 − AIN5 < 0, tj. struja kroz
  šant teče od AIN5 ka AIN4. Ili su žice izvora obrnute u odnosu na
  očekivani smer, ili je tako na šemi (pa u softveru treba obrnuti znak).
  U unipolarnom režimu bi ovo klipovalo na 0 + ADC_ERR (kao kod PT100, §2.2.1).
- Razlika +0.75 % — otvoreno je pitanje koliko greši koji instrument
  (unimer, tolerancija šanta 30 Ω ili ADC).
- Parni šiljci postoje i bez struje — treba ih istražiti (izvor smetnje).
