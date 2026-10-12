# Quectel EG912U-GL — dijagnostika registracije na mrežu

Beleške sa dijagnostike: modem vidi SIM i ima signal, ali se ne registruje na
mrežu (`No Service`). Uz komande su navedeni dobijeni odgovori i šta oni znače.

- SIM: **MTS Srbija** (IMSI `22003…`, ICCID `89381030000356397457`)
- SIM **radi u telefonu** (pozivi, SMS, mobilni podaci)

---

## 1. Osnovno stanje modema

| Komanda | Odgovor | Značenje |
|---|---|---|
| `ATE1` | `OK` | Echo uključen |
| `AT+CPIN?` | `+CPIN: READY` | SIM prepoznat, PIN nije potreban ✅ |
| `AT+CSQ` | `+CSQ: 16,99` | RSSI ≈ −81 dBm, dobar prijem ✅ |
| `AT+CEREG?` | `+CEREG: 0,0` | Nije registrovan na LTE ❌ |
| `AT+COPS?` | `+COPS: 0` | Automatski izbor operatora, nijedan izabran ❌ |
| `AT+QNWINFO` | `+QNWINFO: "No Service"` | Nema servisa ❌ |
| `AT+CGATT?` | `+CGATT: 0` | Nije zakačen na paketski (data) servis |

> `+CME ERROR: 58` = nepostojeća komanda (greška u kucanju, npr. `AT+QNWING`
> umesto `AT+QNWINFO`). `+CME ERROR: 49` = pogrešna sintaksa (npr. `AT+CIMI?`
> umesto `AT+CIMI`).

## 2. Registracija, operator, bendovi

| Komanda | Odgovor | Značenje |
|---|---|---|
| `AT+CREG?` | `+CREG: 0,2` | 2G/3G: nije registrovan, traži mrežu |
| `AT+CGREG?` | `+CGREG: 0,2` | GPRS: nije registrovan, traži mrežu |
| `AT+CIMI` | `220033401760327` | MCC 220 / MNC 03 = MTS Srbija (domaća mreža) |
| `AT+QCFG="nwscanmode"` | `"nwscanmode",0` | AUTO skeniranje ✅ |
| `AT+QCFG="band"` | `"band",0xf,0x2000001e20b0f18df` | Svi GSM bendovi, LTE B1/B3/B7/B8/B20… ✅ |
| `AT+COPS=?` | MTS (`2` = trenutni, LTE), MTS GSM, Yettel LTE/GSM | Modem vidi obe mreže ✅ |
| `AT+QENG="servingcell"` | `"LIMSRV","LTE","FDD",220,03,…,1500,3,…,-106,-14,-74,…` | Zakačen na MTS ćeliju, ali samo **ograničeni servis** ❌ |

Dekodiran `servingcell`: LTE B3 (EARFCN 1500), TAC `4EF4`,
RSRP **−106 dBm**, RSRQ **−14 dB**, RSSI −74 dBm. Signal je granični, ali
dovoljan da se modem zakači na ćeliju.

`LIMSRV` = modem je zakačen na ćeliju, ali registracija nije uspela (dozvoljeni
su samo hitni pozivi).

## 3. Razlog odbijanja i APN

| Komanda | Odgovor | Značenje |
|---|---|---|
| `AT+CEER` | `+CEER: 0,-1` | **Mreža nije poslala razlog odbijanja** |
| `AT+QCCID` | `89381030000356397457` | ICCID SIM kartice |
| `AT+CGDCONT?` | `1,"IP","gprsinternet",…` | APN za MTS je ispravan ✅ |

---

## Zaključak (trenutno stanje)

- **SIM i pretplata su ispravni**: kartica radi u telefonu, a APN je dobar.
- **Prijem radi**: modem vidi ćelije i operatore i zakači se na MTS LTE ćeliju.
- **Mreža nije poslala reject cause** (`CEER 0,-1`). Da je mreža odbila SIM,
  ovde bi stajao razlog. Zato je najverovatnije da **zahtev za registraciju
  ne stiže do bazne stanice**, odnosno da **uplink (predaja) ne radi**.

### Mogući uzroci (po verovatnoći)

1. **Antena na pogrešnom konektoru**: ako je antena samo na DIV/GNSS ulazu,
   prijem je dobar, ali modem predaje preko MAIN ulaza na kome nema ništa.
2. **Napajanje**: strujni pikovi pri predaji (GSM do ~2 A, LTE manje) obaraju
   VBAT, pa predaja ne uspe ili se modem tiho resetuje (`RDY` u terminalu).
3. **Slab signal na lokaciji**: RSRP −106 i RSRQ −14 su granični za uplink.
4. **Neispravan IMEI** (prazan ili nulti posle flash-ovanja), ređe.

---

## Sledeći koraci

### AT komande

```
AT+CMEE=2                    // tekstualne greške umesto brojeva
AT+GSN                       // IMEI: 15 cifara, ne nule
AT+CBC                       // napon napajanja (~3.8 V, ne ispod ~3.5 V)
AT+CREG=2
AT+CEREG=2                   // URC poruke pri promeni stanja registracije
AT+CFUN=0
AT+CFUN=1                    // ponovni pokušaj registracije; pratiti 1–2 min
```

Tokom registracije pratiti da li se pojavljuje `RDY` / `+CPIN: READY` bez
naše komande. To bi značilo da se modem resetuje (problem sa napajanjem).

Ručna registracija samo na MTS 2G (veći strujni pikovi, dobar test napajanja):

```
AT+COPS=1,2,"22003",0        // ručno: MTS, GSM
AT+CREG?                     // posle ~30 s: 0,1 = OK, 0,3 = odbijen
AT+COPS=0                    // vraćanje na automatski izbor
```

### Fizičke provere

- [ ] Na ploči ili u šemi proveriti na koji je u.FL konektor antena zakačena;
      mora biti **MAIN / ANT_MAIN**.
- [ ] Probati uređaj kraj prozora ili sa spoljnom antenom.
- [ ] Osciloskopom izmeriti VBAT modema tokom registracije (propadi ispod
      ~3.3 V su problem).

### Očekivani rezultat kad proradi

```
AT+CEREG?                    -> +CEREG: 0,1   (0,5 = roaming)
AT+QENG="servingcell"        -> "NOCONN" ili "CONNECT" umesto "LIMSRV"
AT+QNWINFO                   -> "FDD LTE","22003","LTE BAND 3",1500
AT+CGATT?                    -> +CGATT: 1
```

---

## Referenca: vrednosti stanja registracije (`CREG` / `CGREG` / `CEREG`)

| `<stat>` | Značenje |
|---|---|
| 0 | Nije registrovan, ne traži mrežu |
| 1 | Registrovan, domaća mreža |
| 2 | Nije registrovan, traži mrežu |
| 3 | Registracija odbijena |
| 4 | Nepoznato |
| 5 | Registrovan, roaming |
