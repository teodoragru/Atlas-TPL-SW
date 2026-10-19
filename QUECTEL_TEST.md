# Quectel EG912U-GL — test mreže i GPS-a (Atlas TPL / NanoPi)

Beleške za povezivanje na uređaj i testiranje Quectel modema.
Postupak je izvučen sa slika iz `../docs/IMG_7142–7149.jpeg` (kolegin postupak)
i iz datasheet-ova u `../docs/datasheet/ug912ul-glab/`.

---

## 1. Povezivanje računara sa uređajem (SSH)

Uređaj: **`10.1.49.18`**, maska `255.255.0.0` (= `/16`, mreža 10.1.0.0–10.1.255.255).
(Fabrički je bio `10.0.104.15/12`.)

Razvojni Linux je VMware VM sa NAT karticom (`ens33`). Kroz NAT nema pristupa
mreži uređaja, pa je potrebna dodatna **bridged** kartica:

1. VMware: **VM → Settings → Add… → Network Adapter → Bridged**
   (u *Virtual Network Editor*-u izabrati fizičku karticu na kojoj je uređaj).
2. U VM-u naći ime nove kartice: `ip -br link` (npr. `ens37`).
3. Dodeliti adresu iz iste mreže (bez gateway-a, internet ostaje preko `ens33`):

   ```bash
   # trajno
   sudo nmcli con add type ethernet ifname ens37 con-name atlas \
        ipv4.method manual ipv4.addresses 10.1.49.100/16
   sudo nmcli con up atlas

   # ili privremeno
   sudo ip addr add 10.1.49.100/16 dev ens37
   sudo ip link set ens37 up
   ```

4. Povezivanje:

   ```bash
   ping 10.1.49.18
   ssh root@10.1.49.18
   ```

Kopiranje fajla na uređaj (obavezna `:` posle adrese, inače `scp` napravi
lokalni fajl sa imenom `root@10.1.49.18`):

```bash
scp quectel_test root@10.1.49.18:/root/
```

### Trajna promena IP adrese uređaja

Na uređaju (preko SSH-a ili serijske konzole) pokrenuti:

```bash
sysconf.sh
```

U tekstualnom (GUI) meniju izabrati mrežna podešavanja, uneti novu adresu i
masku, zatim **sačuvati** izmene i uraditi **reboot**. Samo pratiti korake u
meniju. Posle reboot-a uređaj je na novoj adresi: računaru treba dati adresu
iz iste mreže (korak 3 gore), pa se ponovo povezati sa `ssh root@<nova_adresa>`.

---

## 2. Tip hardvera — `/etc/init.d/hwtype`

Init skripta koja na boot-u, prema izabranom tipu ploče, podešava GPIO-ove,
linkove u `/dev` i USB-serial driver. Za našu ploču tip je **`ATLAS_TPL`**
(opcija `i`), a izvršava se funkcija `nanopi_tpl_prepare()`.

```bash
/etc/init.d/hwtype status     # trenutni tip
/etc/init.d/hwtype init       # meni za izbor tipa (upisuje /mnt/etc/.hw_type i dtb)
nano /etc/init.d/hwtype       # izmena skripte
/usr/bin/atlas-xbb/save-mydata-xbb.sh hwtype   # trajno snimanje izmene u flash
```

> **Važno:** posle svake izmene `/etc/init.d/hwtype` obavezno je upisati u flash:
>
> ```bash
> /usr/bin/atlas-xbb/save-mydata-xbb.sh hwtype
> ```
>
> Bez toga se izmena gubi posle restarta.

Trenutni sadržaj `nanopi_tpl_prepare()`:
- registruje Quectel USB ID za generic usb-serial driver: `echo 2c7c 0901 > .../generic/new_id`
- pravi link `/dev/modem -> /dev/ttyUSB5`
- GPIO za napajanje/reset su **zakomentarisani**, GPIO za aktivnu antenu ne postoji

GPIO-ovi za Quectel (iz `quectel_test.c`, H3 GPIO_A → sysfs broj):

| sysfs GPIO | Signal         | Quectel pin | Namena                       |
|-----------:|----------------|-------------|------------------------------|
| 21         | GNSS_LDO_ON    | —           | napajanje modula (LDO)       |
| 20         | GNSS_PWR_KEY   | 15 PWRKEY   | paljenje modula (impuls)     |
| 17         | GNSS_RST_KEY   | 17 RESET_N  | reset                        |
| ?          | —              | —           | napajanje aktivne GPS antene |

> TODO: potvrditi aktivne nivoe (PWRKEY/RESET obično idu preko tranzistora,
> pa su invertovani) i broj GPIO-a za antenu, pa ubaciti sekvencu paljenja
> u `nanopi_tpl_prepare()`.

---

## 3. USB portovi modema

Modem se preko USB-a vidi kao više `/dev/ttyUSBx` portova (AT, modem/PPP,
NMEA, debug…). Tačna podela nije navedena u hardware design dokumentima —
utvrđuje se na uređaju:

```bash
ls -l /dev/modem          # na koji port pokazuje link
ls /dev/ttyUSB*
dmesg | grep -i ttyUSB    # redosled kreiranja portova
lsusb                     # Quectel: VID 2c7c, PID 0901
```

Zatim na svakom portu probati `AT` (vidi §4): AT port odgovara `OK`;
NMEA port sam šalje `$GNGGA…` linije kad je GPS uključen.
Kolega je čitao `/dev/ttyUSB6` (verovatno NMEA port).

Detaljna mapa portova: *Quectel UNISOC Linux USB Driver User Guide* i
*EC200U & EG912U-GL GNSS Application Note* (nisu u `docs/`, treba ih skinuti).

---

## 4. AT komande — provera mreže

```bash
screen /dev/modem 115200
```

Izlaz iz `screen`-a: **Ctrl+A**, zatim **k**, zatim **y**.

**Echo je isključen:** dok kucaš AT komande, ne vidiš ih na ekranu, vidi se
samo odgovor (`OK`, `+CSQ: ...`). Kucaj „na slepo" i pritisni Enter. Da se
vidi šta se kuca, uključi echo:

```
ATE1     → uključi echo (važi do restarta modema)
AT&W     → (opciono) trajno sačuvaj podešavanje u modemu
ATE0     → isključi echo
```

| Komanda       | Očekivano                 | Značenje                                       |
|---------------|---------------------------|------------------------------------------------|
| `AT`          | `OK`                      | modem odgovara                                 |
| `AT+CPIN?`    | `+CPIN: READY`            | SIM kartica radi                               |
| `AT+CSQ`      | `+CSQ: 10..31,99`         | jačina signala (99 = nema signala); 13 ≈ −87 dBm |
| `AT+CEREG?`   | `+CEREG: 0,1` ili `0,5`   | registrovan na LTE (1 = domaća, 5 = roaming)   |
| `AT+CREG?`    | `+CREG: 0,1` ili `0,5`    | registracija (2G/opšte)                        |
| `AT+COPS?`    | ime operatera             | na kog operatera je prijavljen                 |
| `AT+QNWINFO`  | tip mreže, operater, band | `"No Service"` = nije registrovan              |
| `AT+CGATT?`   | `+CGATT: 1`               | packet data attach                             |

Ako je `CSQ` dobar a `QNWINFO` daje `"No Service"` → proveriti `CPIN`, `CEREG`,
APN i podržane band-ove.

---

## 5. Data konekcija (PPP)

1. Generisati chatscripts (`/etc/chatscripts/gprs`, `gprs_`) i odgovoriti
   `save` da se snime u flash (`/mnt/etc/imp_atlas_sys/chatscripts/`).
   > TODO: ime skripte koja ovo radi nije vidljivo na slici — pitati kolegu.
2. Podići vezu i pratiti log:

   ```bash
   pppd call provider
   tail -f /var/log/messages     # tražiti "local  IP address"
   ip addr show ppp0
   ping -I ppp0 8.8.8.8
   ```

---

## 6. GPS (GNSS)

GNSS je po defaultu isključen (datasheet, §5.2). Potrebna je antena na `ANT_GNSS`
(aktivna antena traži napajanje — vidi GPIO u §2) i pogled na nebo.

| Komanda                           | Značenje                                   |
|-----------------------------------|--------------------------------------------|
| `AT+QGPSCFG="outport","usbnmea"`  | NMEA izlaz na USB NMEA port                |
| `AT+QGPS=1`                       | uključi GNSS                               |
| `AT+QGPSLOC=2`                    | pozicija (`+CME ERROR: 516` = još nema fix) |
| `AT+QGPSEND`                      | isključi GNSS                              |

NMEA rečenice: `cat /dev/ttyUSB6` (ako je to NMEA port, vidi §3).
Prvi fix (cold start) može trajati i nekoliko minuta.

> Komande u ovoj sekciji nisu sa slika — to su standardne Quectel GNSS
> komande; potvrditi u GNSS Application Note.

---

## Redosled ukratko

1. SSH na uređaj (§1)
2. Proveriti/podesiti `hwtype` = `ATLAS_TPL`, snimiti u flash, reboot (§2)
3. Utvrditi portove (§3)
4. AT provera SIM-a, signala i registracije (§4)
5. PPP konekcija (§5)
6. GPS (§6)
