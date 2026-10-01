root@NanoPi:~# ./dac_us
    MOSI -> [8 B]: FF FF FF FF FF FF FF FF 
    MISO <- [8 B]: 00 00 00 00 00 00 00 01 
Softverski reset.
    MOSI -> [2 B]: 45 00 
    MISO <- [2 B]: FF 05 
    MOSI -> [2 B]: 45 00 
    MISO <- [2 B]: FF 05 
===================================================
[SPI DEBUG - SIROVI ISPIS MISO LINIJE]
  Bajt 0 (Odgovor na komandu): 0xFF
  Bajt 1 (Prvi bajt podatka):  0x05
---------------------------------------------------
[ADC] Procitani ID preko ad4130_read_reg: 0x05
===================================================
    MOSI -> [4 B]: 09 80 11 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0A 80 31 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0B 80 71 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0C 80 51 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0D 80 85 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0E 80 C7 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0F 81 09 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 10 81 4B 00 
    MISO <- [4 B]: FF FF FF FF 
Svih 8 kanala (CH0-CH7) uspesno konfigurisano.
    MOSI -> [3 B]: 19 00 20 
    MISO <- [3 B]: FF FF FF 
    MOSI -> [3 B]: 01 45 00 
    MISO <- [3 B]: FF FF FF 
Port ekspanderi (U4, U8, U15) su konfigurisani.
 Postavljanje interne reference za DAC na adresi 0x10.
 Postavljanje interne reference za DAC na adresi 0x52.
DAC reference postavljene.

    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 91 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V | Procenjen Vin: -8.2500 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 80 9E 23 13 
[ADC] NAPONSKI Ulaz Vin4 | Kod: 8429091 (0x809E23) | ADC ulaz: 0.0121 V | Procenjen Vin: 0.0398 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 80 00 39 17 
[ADC] STRUJNI Ulaz Iin4  | Kod: 8388665 (0x800039) | ADC ulaz: 0.0000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 81 14 2B 13 
[ADC] NAPONSKI Ulaz Vin4 | Kod: 8459307 (0x81142B) | ADC ulaz: 0.0211 V | Procenjen Vin: 0.0695 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 80 00 81 17 
[ADC] STRUJNI Ulaz Iin4  | Kod: 8388737 (0x800081) | ADC ulaz: 0.0000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 80 94 A4 15 
[ADC] STRUJNI Ulaz Iin2  | Kod: 8426660 (0x8094A4) | ADC ulaz: 0.0113 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 80 0A 7A 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 8391290 (0x800A7A) | ADC ulaz: 0.0008 V | Procenjen Vin: 0.0026 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 80 82 1A 15 
[ADC] STRUJNI Ulaz Iin2  | Kod: 8421914 (0x80821A) | ADC ulaz: 0.0099 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 80 0A 60 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 8391264 (0x800A60) | ADC ulaz: 0.0008 V | Procenjen Vin: 0.0026 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 71 96 1A 15 
[ADC] STRUJNI Ulaz Iin2  | Kod: 7443994 (0x71961A) | ADC ulaz: -0.2815 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 A0 1B 70 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 10492784 (0xA01B70) | ADC ulaz: 0.6271 V | Procenjen Vin: 2.0694 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 71 0E 26 15 
[ADC] STRUJNI Ulaz Iin2  | Kod: 7409190 (0x710E26) | ADC ulaz: -0.2919 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 87 23 F3 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 8856563 (0x8723F3) | ADC ulaz: 0.1395 V | Procenjen Vin: 0.4602 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 70 31 01 15 
[ADC] STRUJNI Ulaz Iin2  | Kod: 7352577 (0x703101) | ADC ulaz: -0.3088 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 80 0B 8B 13 
[ADC] NAPONSKI Ulaz Vin4 | Kod: 8391563 (0x800B8B) | ADC ulaz: 0.0009 V | Procenjen Vin: 0.0029 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 80 56 0F 17 
[ADC] STRUJNI Ulaz Iin4  | Kod: 8410639 (0x80560F) | ADC ulaz: 0.0066 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 80 0B D9 13 
[ADC] NAPONSKI Ulaz Vin4 | Kod: 8391641 (0x800BD9) | ADC ulaz: 0.0009 V | Procenjen Vin: 0.0030 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 81 00 C5 17 
[ADC] STRUJNI Ulaz Iin4  | Kod: 8454341 (0x8100C5) | ADC ulaz: 0.0196 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 81 54 0E 13 
[ADC] NAPONSKI Ulaz Vin4 | Kod: 8475662 (0x81540E) | ADC ulaz: 0.0259 V | Procenjen Vin: 0.0856 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
---------------------------------------------------
^C


root@NanoPi:~# ls /dev/ttyS*
/dev/ttyS0  /dev/ttySS0  /dev/ttySS2  /dev/ttySS4  /dev/ttySS6
/dev/ttyS1  /dev/ttySS1  /dev/ttySS3  /dev/ttySS5  /dev/ttySS7


root@NanoPi:~# cat /proc/tty/driver/*
serinfo:1.0 driver revision:
0: uart:U6_16550A mmio:0x01C28000 irq:44 tx:9102 rx:0 RTS|DTR
1: uart:U6_16550A mmio:0x01C28400 irq:45 tx:16 rx:0 CTS
2: uart:U6_16550A mmio:0x01C28800 irq:46 tx:32 rx:0 RTS|CTS|DTR
3: uart:unknown port:00000000 irq:0
4: uart:unknown port:00000000 irq:0
5: uart:unknown port:00000000 irq:0
6: uart:unknown port:00000000 irq:0
7: uart:unknown port:00000000 irq:0
usbserinfo:1.0 driver:2.0
root@NanoPi:~# echo "test123" > /dev/ttySS1
root@NanoPi:~# cat /proc/tty/driver/*
serinfo:1.0 driver revision:
0: uart:U6_16550A mmio:0x01C28000 irq:44 tx:9102 rx:0 RTS|DTR
1: uart:U6_16550A mmio:0x01C28400 irq:45 tx:24 rx:0 CTS
2: uart:U6_16550A mmio:0x01C28800 irq:46 tx:32 rx:0 RTS|CTS|DTR
3: uart:unknown port:00000000 irq:0
4: uart:unknown port:00000000 irq:0
5: uart:unknown port:00000000 irq:0
6: uart:unknown port:00000000 irq:0
7: uart:unknown port:00000000 irq:0
usbserinfo:1.0 driver:2.0




root@NanoPi:~# ./dac_us
    MOSI -> [8 B]: FF FF FF FF FF FF FF FF 
    MISO <- [8 B]: 00 00 00 00 00 00 00 00 
Softverski reset.
    MOSI -> [2 B]: 45 00 
    MISO <- [2 B]: 00 00 
    MOSI -> [2 B]: 45 00 
    MISO <- [2 B]: 00 00 
===================================================
[SPI DEBUG - SIROVI ISPIS MISO LINIJE]
  Bajt 0 (Odgovor na komandu): 0x00
  Bajt 1 (Prvi bajt podatka):  0x00
---------------------------------------------------
[ADC] Procitani ID preko ad4130_read_reg: 0x00
===================================================
    MOSI -> [4 B]: 09 80 11 00 
    MISO <- [4 B]: 00 00 00 00 
    MOSI -> [4 B]: 0A 80 31 00 
    MISO <- [4 B]: 00 00 00 00 
    MOSI -> [4 B]: 0B 80 71 00 
    MISO <- [4 B]: 00 00 00 00 
    MOSI -> [4 B]: 0C 80 51 00 
    MISO <- [4 B]: 00 00 00 00 
    MOSI -> [4 B]: 0D 80 85 00 
    MISO <- [4 B]: 00 00 00 00 
    MOSI -> [4 B]: 0E 80 C7 00 
    MISO <- [4 B]: 00 00 00 00 
    MOSI -> [4 B]: 0F 81 09 00 
    MISO <- [4 B]: 00 00 00 00 
    MOSI -> [4 B]: 10 81 4B 00 
    MISO <- [4 B]: 00 00 00 00 
Svih 8 kanala (CH0-CH7) uspesno konfigurisano.
    MOSI -> [3 B]: 19 00 20 
    MISO <- [3 B]: 00 00 00 
    MOSI -> [3 B]: 01 45 00 
    MISO <- [3 B]: 00 00 00 
Port ekspanderi (U4, U8, U15) su konfigurisani.
 Postavljanje interne reference za DAC na adresi 0x10.
 Postavljanje interne reference za DAC na adresi 0x52.
DAC reference postavljene.

    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 00 00 00 00 
[ADC] NAPONSKI Ulaz Vin1 | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V | Procenjen Vin: -8.2500 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 00 00 00 00 
[ADC] NAPONSKI Ulaz Vin1 | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V | Procenjen Vin: -8.2500 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 00 00 00 00 
[ADC] NAPONSKI Ulaz Vin1 | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V | Procenjen Vin: -8.2500 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 00 00 00 00 
[ADC] NAPONSKI Ulaz Vin1 | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V | Procenjen Vin: -8.2500 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 00 00 00 00 
[ADC] NAPONSKI Ulaz Vin1 | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V | Procenjen Vin: -8.2500 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
---------------------------------------------------
^C


stty -F /dev/ttySS2 115200 cs8 -cstopb -parenb -crtscts raw -echo -ixon -ixoff clocal
while true; do echo -n "UUUUUUUU" > /dev/ttySS2; sleep 0.05; done
*/



root@NanoPi:~# ./dac_us
Pritisni 'b' u bilo kom trenutku da okines LED3 blink test (Ctrl+C za izlaz).

    MOSI -> [8 B]: FF FF FF FF FF FF FF FF 
    MISO <- [8 B]: 00 00 00 00 00 00 00 01 
Softverski reset.
    MOSI -> [2 B]: 45 00 
    MISO <- [2 B]: FF 05 
    MOSI -> [2 B]: 45 00 
    MISO <- [2 B]: FF 05 
===================================================
[SPI DEBUG - SIROVI ISPIS MISO LINIJE]
  Bajt 0 (Odgovor na komandu): 0xFF
  Bajt 1 (Prvi bajt podatka):  0x05
---------------------------------------------------
[ADC] Procitani ID preko ad4130_read_reg: 0x05
===================================================
    MOSI -> [4 B]: 09 80 11 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0A 80 31 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0B 80 71 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0C 80 51 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0D 80 85 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0E 80 C7 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0F 81 09 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 10 81 4B 00 
    MISO <- [4 B]: FF FF FF FF 
Svih 8 kanala (CH0-CH7) uspesno konfigurisano.
    MOSI -> [3 B]: 19 00 20 
    MISO <- [3 B]: FF FF FF 
    MOSI -> [3 B]: 01 45 00 
    MISO <- [3 B]: FF FF FF 
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Port ekspanderi (U4, U8, U15) su konfigurisani.
 Postavljanje interne reference za DAC na adresi 0x10.
Greska pri komunikaciji na I2C magistrali.: No such device or address
 Postavljanje interne reference za DAC na adresi 0x52.
Greska pri komunikaciji na I2C magistrali.: No such device or address
DAC reference postavljene.

    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 75 E0 28 15 
[ADC] STRUJNI Ulaz Iin2  | Kod: 7725096 (0x75E028) | ADC ulaz: -0.1977 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V (izmeri multimetrom i uporedi!)
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 93 1A EA 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 9640682 (0x931AEA) | ADC ulaz: 0.3731 V | Procenjen Vin: 1.2314 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V (izmeri multimetrom i uporedi!)
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 74 49 68 15 
[ADC] STRUJNI Ulaz Iin2  | Kod: 7620968 (0x744968) | ADC ulaz: -0.2288 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V (izmeri multimetrom i uporedi!)
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 82 3B 24 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 8534820 (0x823B24) | ADC ulaz: 0.0436 V | Procenjen Vin: 0.1438 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V (izmeri multimetrom i uporedi!)
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 88 02 11 17 
[ADC] STRUJNI Ulaz Iin4  | Kod: 8913425 (0x880211) | ADC ulaz: 0.1564 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V (izmeri multimetrom i uporedi!)
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 80 1B 26 13 
[ADC] NAPONSKI Ulaz Vin4 | Kod: 8395558 (0x801B26) | ADC ulaz: 0.0021 V | Procenjen Vin: 0.0068 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V (izmeri multimetrom i uporedi!)
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 88 2E 60 17 
[ADC] STRUJNI Ulaz Iin4  | Kod: 8924768 (0x882E60) | ADC ulaz: 0.1598 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V (izmeri multimetrom i uporedi!)
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 80 1B 38 13 
[ADC] NAPONSKI Ulaz Vin4 | Kod: 8395576 (0x801B38) | ADC ulaz: 0.0021 V | Procenjen Vin: 0.0069 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V (izmeri multimetrom i uporedi!)
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 71 66 52 17 
[ADC] STRUJNI Ulaz Iin4  | Kod: 7431762 (0x716652) | ADC ulaz: -0.2852 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V (izmeri multimetrom i uporedi!)
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 83 70 33 13 
[ADC] NAPONSKI Ulaz Vin4 | Kod: 8613939 (0x837033) | ADC ulaz: 0.0672 V | Procenjen Vin: 0.2216 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out

Prekinuto (Ctrl+C) - terminal vracen u normalan mod.
root@NanoPi:~# 

novi log

]: FF 05 
    MOSI -> [2 B]: 45 00 
    MISO <- [2 B]: FF 05 
===================================================
[SPI DEBUG - SIROVI ISPIS MISO LINIJE]
  Bajt 0 (Odgovor na komandu): 0xFF
  Bajt 1 (Prvi bajt podatka):  0x05
---------------------------------------------------
[ADC] Procitani ID preko ad4130_read_reg: 0x05
===================================================
    MOSI -> [4 B]: 09 00 11 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0A 00 31 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0B 00 71 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0C 00 51 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0D 00 85 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0E 00 C7 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0F 01 09 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 10 81 4B 00 
    MISO <- [4 B]: FF FF FF FF 
SAMO kanal 7 aktivan (izolovano testiranje) - ostalih 7 iskljuceno.
    MOSI -> [3 B]: 19 00 20 
    MISO <- [3 B]: FF FF FF 
    MOSI -> [3 B]: 01 45 00 
    MISO <- [3 B]: FF FF FF 
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Port ekspanderi (U4, U8, U15) su konfigurisani.
 Postavljanje interne reference za DAC na adresi 0x10.
Greska pri komunikaciji na I2C magistrali.: No such device or address
 Postavljanje interne reference za DAC na adresi 0x52.
Greska pri komunikaciji na I2C magistrali.: No such device or address
DAC reference postavljene.

    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 70 EE 5C 17 
[ADC] STRUJNI Ulaz Iin4  | Kod: 7401052 (0x70EE5C) | ADC ulaz: -0.2943 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V (izmeri multimetrom i uporedi!)
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 70 61 59 17 
[ADC] STRUJNI Ulaz Iin4  | Kod: 7364953 (0x706159) | ADC ulaz: -0.3051 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V (izmeri multimetrom i uporedi!)
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 70 EA 13 17 
[ADC] STRUJNI Ulaz Iin4  | Kod: 7399955 (0x70EA13) | ADC ulaz: -0.2946 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V (izmeri multimetrom i uporedi!)
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 70 79 1F 17 
[ADC] STRUJNI Ulaz Iin4  | Kod: 7371039 (0x70791F) | ADC ulaz: -0.3033 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V (izmeri multimetrom i uporedi!)
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 70 B8 12 17 
[ADC] STRUJNI Ulaz Iin4  | Kod: 7387154 (0x70B812) | ADC ulaz: -0.2985 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V (izmeri multimetrom i uporedi!)
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 74 28 E5 17 
[ADC] STRUJNI Ulaz Iin4  | Kod: 7612645 (0x7428E5) | ADC ulaz: -0.2313 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V (izmeri multimetrom i uporedi!)
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 74 2A 7D 17 
[ADC] STRUJNI Ulaz Iin4  | Kod: 7613053 (0x742A7D) | ADC ulaz: -0.2311 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V (izmeri multimetrom i uporedi!)
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 74 AA 0C 17 
[ADC] STRUJNI Ulaz Iin4  | Kod: 7645708 (0x74AA0C) | ADC ulaz: -0.2214 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V (izmeri multimetrom i uporedi!)
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 74 AA AF 17 
[ADC] STRUJNI Ulaz Iin4  | Kod: 7645871 (0x74AAAF) | ADC ulaz: -0.2214 V
Greska pri slanju adrese PCA9554 registra: Connection timed out

Prekinuto (Ctrl+C) - terminal vracen u normalan mod.


0 00 00 00 00 00 00 01 
Softverski reset.
    MOSI -> [2 B]: 45 00 
    MISO <- [2 B]: FF 05 
    MOSI -> [2 B]: 45 00 
    MISO <- [2 B]: FF 05 
===================================================
[SPI DEBUG - SIROVI ISPIS MISO LINIJE]
  Bajt 0 (Odgovor na komandu): 0xFF
  Bajt 1 (Prvi bajt podatka):  0x05
---------------------------------------------------
[ADC] Procitani ID preko ad4130_read_reg: 0x05
===================================================
    MOSI -> [4 B]: 09 00 11 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0A 00 31 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0B 00 71 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0C 00 51 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0D 00 85 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0E 00 C7 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0F 01 09 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 10 81 4B 00 
    MISO <- [4 B]: FF FF FF FF 
SAMO kanal 7 aktivan (izolovano testiranje) - ostalih 7 iskljuceno.
    MOSI -> [3 B]: 19 00 20 
    MISO <- [3 B]: FF FF FF 
    MOSI -> [3 B]: 01 45 00 
    MISO <- [3 B]: FF FF FF 
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Port ekspanderi (U4, U8, U15) su konfigurisani.
 Postavljanje interne reference za DAC na adresi 0x10.
Greska pri komunikaciji na I2C magistrali.: No such device or address
 Postavljanje interne reference za DAC na adresi 0x52.
Greska pri komunikaciji na I2C magistrali.: No such device or address
DAC reference postavljene.

    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 7C 70 3C 17 
[ADC] STRUJNI Ulaz Iin4  | Kod: 8155196 (0x7C703C) | ADC ulaz: -0.0696 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V (izmeri multimetrom i uporedi!)
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 7C 75 39 17 
[ADC] STRUJNI Ulaz Iin4  | Kod: 8156473 (0x7C7539) | ADC ulaz: -0.0692 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V (izmeri multimetrom i uporedi!)
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 7C 7A A9 17 
[ADC] STRUJNI Ulaz Iin4  | Kod: 8157865 (0x7C7AA9) | ADC ulaz: -0.0688 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V (izmeri multimetrom i uporedi!)
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 7C 7E 27 17 
[ADC] STRUJNI Ulaz Iin4  | Kod: 8158759 (0x7C7E27) | ADC ulaz: -0.0685 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V (izmeri multimetrom i uporedi!)
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 7C 01 0B 17 
[ADC] STRUJNI Ulaz Iin4  | Kod: 8126731 (0x7C010B) | ADC ulaz: -0.0780 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V (izmeri multimetrom i uporedi!)
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 7C 07 20 17 
[ADC] STRUJNI Ulaz Iin4  | Kod: 8128288 (0x7C0720) | ADC ulaz: -0.0776 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V (izmeri multimetrom i uporedi!)
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 7C 0D 23 17 
[ADC] STRUJNI Ulaz Iin4  | Kod: 8129827 (0x7C0D23) | ADC ulaz: -0.0771 V
Greska pri slanju adrese PCA9554 registra: Connection timed out

Prekinuto (Ctrl+C) - terminal vracen u normalan mod.



  0x05
---------------------------------------------------
[ADC] Procitani ID preko ad4130_read_reg: 0x05
SAMO kanal 0 aktivan (izolovano testiranje) - ostalih 7 iskljuceno.
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Port ekspanderi (U4, U8, U15) su konfigurisani.
 Postavljanje interne reference za DAC na adresi 0x10.
Greska pri komunikaciji na I2C magistrali.: No such device or address
 Postavljanje interne reference za DAC na adresi 0x52.
Greska pri komunikaciji na I2C magistrali.: No such device or address
DAC reference postavljene.

[ADC] NAPONSKI Ulaz Vin2 | Kod: 8391700 (0x800C14) | ADC ulaz: 0.0009 V | Procenjen Vin: 0.0030 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
---------------------------------------------------
[ADC] NAPONSKI Ulaz Vin2 | Kod: 8391717 (0x800C25) | ADC ulaz: 0.0009 V | Procenjen Vin: 0.0031 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
---------------------------------------------------
[ADC] NAPONSKI Ulaz Vin2 | Kod: 8391726 (0x800C2E) | ADC ulaz: 0.0009 V | Procenjen Vin: 0.0031 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
---------------------------------------------------
[ADC] NAPONSKI Ulaz Vin2 | Kod: 8391716 (0x800C24) | ADC ulaz: 0.0009 V | Procenjen Vin: 0.0031 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
---------------------------------------------------
[ADC] NAPONSKI Ulaz Vin2 | Kod: 8391707 (0x800C1B) | ADC ulaz: 0.0009 V | Procenjen Vin: 0.0030 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
---------------------------------------------------
[ADC] NAPONSKI Ulaz Vin2 | Kod: 8391712 (0x800C20) | ADC ulaz: 0.0009 V | Procenjen Vin: 0.0031 V
Greska pri slanju adrese PCA9554 registra: Connection timed out

Prekinuto (Ctrl+C) - terminal vracen u normalan mod.



    MOSI -> [8 B]: FF FF FF FF FF FF FF FF 
    MISO <- [8 B]: 00 00 00 00 00 00 00 01 
Softverski reset.
    MOSI -> [2 B]: 45 00 
    MISO <- [2 B]: FF 05 
    MOSI -> [2 B]: 45 00 
    MISO <- [2 B]: FF 05 
[SPI DEBUG - SIROVI ISPIS MISO LINIJE]
  Bajt 0 (Odgovor na komandu): 0xFF
  Bajt 1 (Prvi bajt podatka):  0x05
---------------------------------------------------
[ADC] Procitani ID preko ad4130_read_reg: 0x05
    MOSI -> [4 B]: 09 80 11 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0A 00 31 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0B 00 71 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0C 00 51 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0D 00 85 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0E 00 C7 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0F 01 09 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 10 01 4B 00 
    MISO <- [4 B]: FF FF FF FF 
SAMO kanal 0 aktivan (izolovano testiranje) - ostalih 7 iskljuceno.
    MOSI -> [3 B]: 19 00 20 
    MISO <- [3 B]: FF FF FF 
    MOSI -> [3 B]: 01 45 00 
    MISO <- [3 B]: FF FF FF 
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Port ekspanderi (U4, U8, U15) su konfigurisani.
 Postavljanje interne reference za DAC na adresi 0x10.
Greska pri komunikaciji na I2C magistrali.: No such device or address
 Postavljanje interne reference za DAC na adresi 0x52.
Greska pri komunikaciji na I2C magistrali.: No such device or address
DAC reference postavljene.

    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 80 0B E0 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 8391648 (0x800BE0) | ADC ulaz: 0.0009 V | Procenjen Vin: 0.0030 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 80 0B E5 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 8391653 (0x800BE5) | ADC ulaz: 0.0009 V | Procenjen Vin: 0.0030 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 80 0B A8 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 8391592 (0x800BA8) | ADC ulaz: 0.0009 V | Procenjen Vin: 0.0029 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 80 0B E2 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 8391650 (0x800BE2) | ADC ulaz: 0.0009 V | Procenjen Vin: 0.0030 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 80 0C 28 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 8391720 (0x800C28) | ADC ulaz: 0.0009 V | Procenjen Vin: 0.0031 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 80 0B CF 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 8391631 (0x800BCF) | ADC ulaz: 0.0009 V | Procenjen Vin: 0.0030 V
Greska pri slanju adrese PCA9554 registra: Connection timed out

Prekinuto (Ctrl+C) - terminal vracen u normalan mod.





MOSI -> [8 B]: FF FF FF FF FF FF FF FF 
    MISO <- [8 B]: 00 00 00 00 00 00 00 01 
Softverski reset.
    MOSI -> [2 B]: 45 00 
    MISO <- [2 B]: FF 05 
    MOSI -> [2 B]: 45 00 
    MISO <- [2 B]: FF 05 
[SPI DEBUG - SIROVI ISPIS MISO LINIJE]
  Bajt 0 (Odgovor na komandu): 0xFF
  Bajt 1 (Prvi bajt podatka):  0x05
---------------------------------------------------
[ADC] Procitani ID preko ad4130_read_reg: 0x05
    MOSI -> [4 B]: 09 00 11 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0A 80 31 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0B 00 71 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0C 00 51 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0D 00 85 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0E 00 C7 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0F 01 09 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 10 01 4B 00 
    MISO <- [4 B]: FF FF FF FF 
SAMO kanal 1 aktivan (izolovano testiranje) - ostalih 7 iskljuceno.
    MOSI -> [3 B]: 19 00 20 
    MISO <- [3 B]: FF FF FF 
    MOSI -> [3 B]: 01 45 00 
    MISO <- [3 B]: FF FF FF 
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Port ekspanderi (U4, U8, U15) su konfigurisani.
 Postavljanje interne reference za DAC na adresi 0x10.
Greska pri komunikaciji na I2C magistrali.: No such device or address
 Postavljanje interne reference za DAC na adresi 0x52.
Greska pri komunikaciji na I2C magistrali.: No such device or address
DAC reference postavljene.

    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 8B 5F E5 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 9134053 (0x8B5FE5) | ADC ulaz: 0.2222 V | Procenjen Vin: 0.7331 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 AC 1C F8 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 11279608 (0xAC1CF8) | ADC ulaz: 0.8616 V | Procenjen Vin: 2.8432 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 AF 84 5B 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 11502683 (0xAF845B) | ADC ulaz: 0.9281 V | Procenjen Vin: 3.0626 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 A6 88 23 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 10913827 (0xA68823) | ADC ulaz: 0.7526 V | Procenjen Vin: 2.4835 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 B1 04 01 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 11600897 (0xB10401) | ADC ulaz: 0.9573 V | Procenjen Vin: 3.1592 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 B1 2A ED 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 11610861 (0xB12AED) | ADC ulaz: 0.9603 V | Procenjen Vin: 3.1690 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 B1 A2 E5 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 11641573 (0xB1A2E5) | ADC ulaz: 0.9695 V | Procenjen Vin: 3.1992 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 B1 CE CB 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 11652811 (0xB1CECB) | ADC ulaz: 0.9728 V | Procenjen Vin: 3.2103 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 B2 07 A2 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 11667362 (0xB207A2) | ADC ulaz: 0.9771 V | Procenjen Vin: 3.2246 V

Prekinuto (Ctrl+C) - terminal vracen u normalan mod.
root@NanoPi:~# 


[ADC] Procitani ID preko ad4130_read_reg: 0x05
    MOSI -> [4 B]: 09 00 11 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0A 80 31 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0B 00 71 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0C 00 51 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0D 00 85 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0E 00 C7 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 0F 01 09 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 10 01 4B 00 
    MISO <- [4 B]: FF FF FF FF 
SAMO kanal 1 aktivan (izolovano testiranje) - ostalih 7 iskljuceno.
    MOSI -> [3 B]: 19 00 20 
    MISO <- [3 B]: FF FF FF 
    MOSI -> [3 B]: 01 45 00 
    MISO <- [3 B]: FF FF FF 
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Port ekspanderi (U4, U8, U15) su konfigurisani.
 Postavljanje interne reference za DAC na adresi 0x10.
Greska pri komunikaciji na I2C magistrali.: No such device or address
 Postavljanje interne reference za DAC na adresi 0x52.
Greska pri komunikaciji na I2C magistrali.: No such device or address
DAC reference postavljene.

    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 B2 C2 D0 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 11715280 (0xB2C2D0) | ADC ulaz: 0.9914 V | Procenjen Vin: 3.2717 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 B2 D6 ED 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 11720429 (0xB2D6ED) | ADC ulaz: 0.9930 V | Procenjen Vin: 3.2768 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 B2 D5 D9 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 11720153 (0xB2D5D9) | ADC ulaz: 0.9929 V | Procenjen Vin: 3.2765 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 B2 D7 12 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 11720466 (0xB2D712) | ADC ulaz: 0.9930 V | Procenjen Vin: 3.2768 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 B2 CE F6 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 11718390 (0xB2CEF6) | ADC ulaz: 0.9924 V | Procenjen Vin: 3.2748 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 B2 CA 07 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 11717127 (0xB2CA07) | ADC ulaz: 0.9920 V | Procenjen Vin: 3.2735 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 B2 CA D0 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 11717328 (0xB2CAD0) | ADC ulaz: 0.9920 V | Procenjen Vin: 3.2737 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 B2 C2 C2 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 11715266 (0xB2C2C2) | ADC ulaz: 0.9914 V | Procenjen Vin: 3.2717 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 B2 5E DB 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 11689691 (0xB25EDB) | ADC ulaz: 0.9838 V | Procenjen Vin: 3.2465 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
---------------------------------------------------
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 B2 5F C9 11 
[ADC] NAPONSKI Ulaz Vin2 | Kod: 11689929 (0xB25FC9) | ADC ulaz: 0.9839 V | Procenjen Vin: 3.2468 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out

Prekinuto (Ctrl+C) - terminal vracen u normalan mod.

13/8/2026
Pritisni 'b' u bilo kom trenutku da upalis LED3 blink test.

    MOSI -> [8 B]: FF FF FF FF FF FF FF FF 
    MISO <- [8 B]: 00 00 00 00 00 00 00 01 
Softverski reset. 
    MOSI -> [2 B]: 45 00 
    MISO <- [2 B]: FF 05 
Procitani ID ADC registra: 0x05
    MOSI -> [4 B]: 09 00 11 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 49 00 00 00 
    MISO <- [4 B]: FF 00 11 01 
  [CH0] Ne podudara se: poslato 0x001100, procitano nazad 0x001101. 
    MOSI -> [4 B]: 0A 00 31 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 4A 00 00 00 
    MISO <- [4 B]: FF 00 31 01 
  [CH1] Ne podudara se: poslato 0x003100, procitano nazad 0x003101. 
    MOSI -> [4 B]: 0B 00 71 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 4B 00 00 00 
    MISO <- [4 B]: FF 00 71 01 
  [CH2] Ne podudara se: poslato 0x007100, procitano nazad 0x007101. 
    MOSI -> [4 B]: 0C 00 51 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 4C 00 00 00 
    MISO <- [4 B]: FF 00 51 01 
  [CH3] Ne podudara se: poslato 0x005100, procitano nazad 0x005101. 
    MOSI -> [4 B]: 0D 00 85 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 4D 00 00 00 
    MISO <- [4 B]: FF 00 85 01 
  [CH4] Ne podudara se: poslato 0x008500, procitano nazad 0x008501. 
    MOSI -> [4 B]: 0E 00 C7 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 4E 00 00 00 
    MISO <- [4 B]: FF 00 C7 01 
  [CH5] Ne podudara se: poslato 0x00C700, procitano nazad 0x00C701. 
    MOSI -> [4 B]: 0F 01 09 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 4F 00 00 00 
    MISO <- [4 B]: FF 01 09 01 
  [CH6] Ne podudara se: poslato 0x010900, procitano nazad 0x010901. 
    MOSI -> [4 B]: 10 81 4B 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 50 00 00 00 
    MISO <- [4 B]: FF 81 4B 01 
  [CH7] Ne podudara se: poslato 0x814B00, procitano nazad 0x814B01. 
Samo je kanal 7 aktivan (izolovano testiranje) - ostalih 7 iskljuceno.
    MOSI -> [3 B]: 19 00 20 
    MISO <- [3 B]: FF FF FF 
    MOSI -> [3 B]: 59 00 00 
    MISO <- [3 B]: FF 00 21 
Proveravanje CONFIG_0: poslato 0x0020, procitano nazad 0x0021 -> Not OK
    MOSI -> [3 B]: 01 45 00 
    MISO <- [3 B]: FF FF FF 
    MOSI -> [3 B]: 41 00 00 
    MISO <- [3 B]: FF 45 01 
Verifikacija ADC_CTRL: poslato 0x4500, procitano nazad 0x4501 -> Not OK
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Port ekspanderi (U4, U8, U15) su konfigurisani.
 Postavljanje interne reference za DAC na adresi 0x10.
Greska pri komunikaciji na I2C magistrali.: No such device or address
 Postavljanje interne reference za DAC na adresi 0x52.
Greska pri komunikaciji na I2C magistrali.: No such device or address
DAC reference postavljene.

    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 81 31 40 17 
[ADC] Strujni ulaz Iin4  | Kod: 8466752 (0x813140) | ADC ulaz: 0.0233 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 80 0A 91 17 
[ADC] Strujni ulaz Iin4  | Kod: 8391313 (0x800A91) | ADC ulaz: 0.0008 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 80 02 4F 17 
[ADC] Strujni ulaz Iin4  | Kod: 8389199 (0x80024F) | ADC ulaz: 0.0002 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 80 41 53 17 
[ADC] Strujni ulaz Iin4  | Kod: 8405331 (0x804153) | ADC ulaz: 0.0050 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 80 80 0F 17 
[ADC] Strujni ulaz Iin4  | Kod: 8421391 (0x80800F) | ADC ulaz: 0.0098 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 84 25 96 17 
[ADC] Strujni ulaz Iin4  | Kod: 8660374 (0x842596) | ADC ulaz: 0.0810 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 84 68 54 17 
[ADC] Strujni ulaz Iin4  | Kod: 8677460 (0x846854) | ADC ulaz: 0.0861 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 84 20 97 17 
[ADC] Strujni ulaz Iin4  | Kod: 8659095 (0x842097) | ADC ulaz: 0.0806 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 84 62 87 17 
[ADC] Strujni ulaz Iin4  | Kod: 8675975 (0x846287) | ADC ulaz: 0.0856 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 84 00 09 17 
[ADC] Strujni ulaz Iin4  | Kod: 8650761 (0x840009) | ADC ulaz: 0.0781 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 84 16 82 17 
[ADC] Strujni ulaz Iin4  | Kod: 8656514 (0x841682) | ADC ulaz: 0.0798 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out

Prekinut rad. 



13/8/2026
Current time/date is: Thu Jan  1 01:00:30 CET 1970
root@NanoPi:~# modprobe spidev
root@NanoPi:~# ./dac_us
Pritisni 'b' u bilo kom trenutku da upalis LED3 blink test.

    MOSI -> [8 B]: FF FF FF FF FF FF FF FF 
    MISO <- [8 B]: 00 00 00 00 00 00 00 01 
Softverski reset. 
    MOSI -> [2 B]: 45 00 
    MISO <- [2 B]: FF 05 
Procitani ID ADC registra: 0x05
    MOSI -> [4 B]: 09 00 11 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 49 00 00 00 
    MISO <- [4 B]: FF 00 11 01 
  [CH0] Ne podudara se: poslato 0x001100, procitano nazad 0x001101. 
    MOSI -> [4 B]: 0A 80 31 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 4A 00 00 00 
    MISO <- [4 B]: FF 80 31 01 
  [CH1] Ne podudara se: poslato 0x803100, procitano nazad 0x803101. 
    MOSI -> [4 B]: 0B 00 71 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 4B 00 00 00 
    MISO <- [4 B]: FF 00 71 01 
  [CH2] Ne podudara se: poslato 0x007100, procitano nazad 0x007101. 
    MOSI -> [4 B]: 0C 00 51 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 4C 00 00 00 
    MISO <- [4 B]: FF 00 51 01 
  [CH3] Ne podudara se: poslato 0x005100, procitano nazad 0x005101. 
    MOSI -> [4 B]: 0D 00 85 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 4D 00 00 00 
    MISO <- [4 B]: FF 00 85 01 
  [CH4] Ne podudara se: poslato 0x008500, procitano nazad 0x008501. 
    MOSI -> [4 B]: 0E 00 C7 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 4E 00 00 00 
    MISO <- [4 B]: FF 00 C7 01 
  [CH5] Ne podudara se: poslato 0x00C700, procitano nazad 0x00C701. 
    MOSI -> [4 B]: 0F 01 09 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 4F 00 00 00 
    MISO <- [4 B]: FF 01 09 01 
  [CH6] Ne podudara se: poslato 0x010900, procitano nazad 0x010901. 
    MOSI -> [4 B]: 10 01 4B 00 
    MISO <- [4 B]: FF FF FF FF 
    MOSI -> [4 B]: 50 00 00 00 
    MISO <- [4 B]: FF 01 4B 01 
  [CH7] Ne podudara se: poslato 0x014B00, procitano nazad 0x014B01. 
Samo je kanal 1 aktivan (izolovano testiranje) - ostalih 7 iskljuceno.
    MOSI -> [3 B]: 19 00 20 
    MISO <- [3 B]: FF FF FF 
    MOSI -> [3 B]: 59 00 00 
    MISO <- [3 B]: FF 00 21 
Proveravanje CONFIG_0: poslato 0x0020, procitano nazad 0x0021 -> Not OK
    MOSI -> [3 B]: 01 45 00 
    MISO <- [3 B]: FF FF FF 
    MOSI -> [3 B]: 41 00 00 
    MISO <- [3 B]: FF 45 01 
Verifikacija ADC_CTRL: poslato 0x4500, procitano nazad 0x4501 -> Not OK
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Port ekspanderi (U4, U8, U15) su konfigurisani.
 Postavljanje interne reference za DAC na adresi 0x10.
Greska pri komunikaciji na I2C magistrali.: No such device or address
 Postavljanje interne reference za DAC na adresi 0x52.
Greska pri komunikaciji na I2C magistrali.: No such device or address
DAC reference postavljene.

    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 A4 6A A1 11 
[ADC] Naponski ulaz Vin2 | Kod: 10775201 (0xA46AA1) | ADC ulaz: 0.7113 V | ADC ulaz * 4.3: 3.0584 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 AD E9 CD 11 
[ADC] Naponski ulaz Vin2 | Kod: 11397581 (0xADE9CD) | ADC ulaz: 0.8967 V | ADC ulaz * 4.3: 3.8560 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 AD CE DA 11 
[ADC] Naponski ulaz Vin2 | Kod: 11390682 (0xADCEDA) | ADC ulaz: 0.8947 V | ADC ulaz * 4.3: 3.8472 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 AD EC 64 11 
[ADC] Naponski ulaz Vin2 | Kod: 11398244 (0xADEC64) | ADC ulaz: 0.8969 V | ADC ulaz * 4.3: 3.8568 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 AE CA CE 11 
[ADC] Naponski ulaz Vin2 | Kod: 11455182 (0xAECACE) | ADC ulaz: 0.9139 V | ADC ulaz * 4.3: 3.9298 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 AE C8 DA 11 
[ADC] Naponski ulaz Vin2 | Kod: 11454682 (0xAEC8DA) | ADC ulaz: 0.9138 V | ADC ulaz * 4.3: 3.9292 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 AE CE 07 11 
[ADC] Naponski ulaz Vin2 | Kod: 11456007 (0xAECE07) | ADC ulaz: 0.9142 V | ADC ulaz * 4.3: 3.9309 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 AE AA 72 11 
[ADC] Naponski ulaz Vin2 | Kod: 11446898 (0xAEAA72) | ADC ulaz: 0.9114 V | ADC ulaz * 4.3: 3.9192 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 AE AD F1 11 
[ADC] Naponski ulaz Vin2 | Kod: 11447793 (0xAEADF1) | ADC ulaz: 0.9117 V | ADC ulaz * 4.3: 3.9203 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 AE AD 6A 11 
[ADC] Naponski ulaz Vin2 | Kod: 11447658 (0xAEAD6A) | ADC ulaz: 0.9117 V | ADC ulaz * 4.3: 3.9202 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 AE A8 93 11 
[ADC] Naponski ulaz Vin2 | Kod: 11446419 (0xAEA893) | ADC ulaz: 0.9113 V | ADC ulaz * 4.3: 3.9186 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 AE A9 15 11 
[ADC] Naponski ulaz Vin2 | Kod: 11446549 (0xAEA915) | ADC ulaz: 0.9113 V | ADC ulaz * 4.3: 3.9188 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 AE AA C3 11 
[ADC] Naponski ulaz Vin2 | Kod: 11446979 (0xAEAAC3) | ADC ulaz: 0.9115 V | ADC ulaz * 4.3: 3.9193 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 AE AE 64 11 
[ADC] Naponski ulaz Vin2 | Kod: 11447908 (0xAEAE64) | ADC ulaz: 0.9117 V | ADC ulaz * 4.3: 3.9205 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 AE A8 5C 11 
[ADC] Naponski ulaz Vin2 | Kod: 11446364 (0xAEA85C) | ADC ulaz: 0.9113 V | ADC ulaz * 4.3: 3.9185 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 AE 99 68 11 
[ADC] Naponski ulaz Vin2 | Kod: 11442536 (0xAE9968) | ADC ulaz: 0.9101 V | ADC ulaz * 4.3: 3.9136 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 AE AC 23 11 
[ADC] Naponski ulaz Vin2 | Kod: 11447331 (0xAEAC23) | ADC ulaz: 0.9116 V | ADC ulaz * 4.3: 3.9198 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 AE 9C 5E 11 
[ADC] Naponski ulaz Vin2 | Kod: 11443294 (0xAE9C5E) | ADC ulaz: 0.9104 V | ADC ulaz * 4.3: 3.9146 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 AE 8A E1 11 
[ADC] Naponski ulaz Vin2 | Kod: 11438817 (0xAE8AE1) | ADC ulaz: 0.9090 V | ADC ulaz * 4.3: 3.9088 V
Greska pri slanju adrese PCA9554 registra: Connection timed out

Prekinut rad. 






munikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 88 80 05 17 
[ADC] Strujni ulaz Iin4  | Kod: 8945669 (0x888005) | ADC ulaz: 0.1660 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 88 80 28 17 
[ADC] Strujni ulaz Iin4  | Kod: 8945704 (0x888028) | ADC ulaz: 0.1660 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 88 89 73 17 
[ADC] Strujni ulaz Iin4  | Kod: 8948083 (0x888973) | ADC ulaz: 0.1667 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 88 88 34 17 
[ADC] Strujni ulaz Iin4  | Kod: 8947764 (0x888834) | ADC ulaz: 0.1666 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 88 80 1A 17 
[ADC] Strujni ulaz Iin4  | Kod: 8945690 (0x88801A) | ADC ulaz: 0.1660 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 88 80 61 17 
[ADC] Strujni ulaz Iin4  | Kod: 8945761 (0x888061) | ADC ulaz: 0.1660 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 88 80 56 17 
[ADC] Strujni ulaz Iin4  | Kod: 8945750 (0x888056) | ADC ulaz: 0.1660 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 88 81 11 17 
[ADC] Strujni ulaz Iin4  | Kod: 8945937 (0x888111) | ADC ulaz: 0.1661 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 88 80 0C 17 
[ADC] Strujni ulaz Iin4  | Kod: 8945676 (0x88800C) | ADC ulaz: 0.1660 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 88 80 28 17 
[ADC] Strujni ulaz Iin4  | Kod: 8945704 (0x888028) | ADC ulaz: 0.1660 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 88 80 12 17 
[ADC] Strujni ulaz Iin4  | Kod: 8945682 (0x888012) | ADC ulaz: 0.1660 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 88 88 0C 17 
[ADC] Strujni ulaz Iin4  | Kod: 8947724 (0x88880C) | ADC ulaz: 0.1666 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 88 80 0E 17 
[ADC] Strujni ulaz Iin4  | Kod: 8945678 (0x88800E) | ADC ulaz: 0.1660 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 88 82 11 17 
[ADC] Strujni ulaz Iin4  | Kod: 8946193 (0x888211) | ADC ulaz: 0.1662 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 88 80 CE 17 
[ADC] Strujni ulaz Iin4  | Kod: 8945870 (0x8880CE) | ADC ulaz: 0.1661 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 88 80 21 17 
[ADC] Strujni ulaz Iin4  | Kod: 8945697 (0x888021) | ADC ulaz: 0.1660 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 88 82 AC 17 
[ADC] Strujni ulaz Iin4  | Kod: 8946348 (0x8882AC) | ADC ulaz: 0.1662 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 88 81 36 17 
[ADC] Strujni ulaz Iin4  | Kod: 8945974 (0x888136) | ADC ulaz: 0.1661 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 88 1A 1F 17 
[ADC] Strujni ulaz Iin4  | Kod: 8919583 (0x881A1F) | ADC ulaz: 0.1582 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 88 19 83 17 
[ADC] Strujni ulaz Iin4  | Kod: 8919427 (0x881983) | ADC ulaz: 0.1582 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 7B 01 0C 17 
[ADC] Strujni ulaz Iin4  | Kod: 8061196 (0x7B010C) | ADC ulaz: -0.0976 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 7B 00 18 17 
[ADC] Strujni ulaz Iin4  | Kod: 8060952 (0x7B0018) | ADC ulaz: -0.0976 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 7B 00 B8 17 
[ADC] Strujni ulaz Iin4  | Kod: 8061112 (0x7B00B8) | ADC ulaz: -0.0976 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 7B 00 8B 17 
[ADC] Strujni ulaz Iin4  | Kod: 8061067 (0x7B008B) | ADC ulaz: -0.0976 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 7B 05 0D 17 
[ADC] Strujni ulaz Iin4  | Kod: 8062221 (0x7B050D) | ADC ulaz: -0.0973 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 7B 01 BC 17 
[ADC] Strujni ulaz Iin4  | Kod: 8061372 (0x7B01BC) | ADC ulaz: -0.0975 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 7B 05 9C 17 
[ADC] Strujni ulaz Iin4  | Kod: 8062364 (0x7B059C) | ADC ulaz: -0.0972 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 7B 06 34 17 
[ADC] Strujni ulaz Iin4  | Kod: 8062516 (0x7B0634) | ADC ulaz: -0.0972 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 73 65 DB 17 
[ADC] Strujni ulaz Iin4  | Kod: 7562715 (0x7365DB) | ADC ulaz: -0.2461 V
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri slanju adrese PCA9554 registra: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri upisu u PCA9554 registar: Connection timed out
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
Greska pri komunikaciji na I2C magistrali.: No such device or address
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 73 64 35 15 
[ADC] Strujni ulaz Iin2  | Kod: 7562293 (0x736435) | ADC ulaz: -0.2463 V





 MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 83 18 40 95 
[ADC] Strujni ulaz Iin2  | Kod: 8591424 (0x831840) | ADC ulaz: 0.0604 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 83 18 40 95 
[ADC] Strujni ulaz Iin2  | Kod: 8591424 (0x831840) | ADC ulaz: 0.0604 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 83 18 40 95 
[ADC] Strujni ulaz Iin2  | Kod: 8591424 (0x831840) | ADC ulaz: 0.0604 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 83 18 40 95 
[ADC] Strujni ulaz Iin2  | Kod: 8591424 (0x831840) | ADC ulaz: 0.0604 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 83 18 40 95 
[ADC] Strujni ulaz Iin2  | Kod: 8591424 (0x831840) | ADC ulaz: 0.0604 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 83 18 40 95 
[ADC] Strujni ulaz Iin2  | Kod: 8591424 (0x831840) | ADC ulaz: 0.0604 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
[ADC] Strujni ulaz Iin4  | Kod: 16777215 (0xFFFFFF) | ADC ulaz: 2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
[ADC] Strujni ulaz Iin4  | Kod: 16777215 (0xFFFFFF) | ADC ulaz: 2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
[ADC] Strujni ulaz Iin4  | Kod: 16777215 (0xFFFFFF) | ADC ulaz: 2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
[ADC] Strujni ulaz Iin4  | Kod: 16777215 (0xFFFFFF) | ADC ulaz: 2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
[ADC] Strujni ulaz Iin4  | Kod: 16777215 (0xFFFFFF) | ADC ulaz: 2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
[ADC] Strujni ulaz Iin4  | Kod: 16777215 (0xFFFFFF) | ADC ulaz: 2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
[ADC] Strujni ulaz Iin4  | Kod: 16777215 (0xFFFFFF) | ADC ulaz: 2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
[ADC] Strujni ulaz Iin4  | Kod: 16777215 (0xFFFFFF) | ADC ulaz: 2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
[ADC] Strujni ulaz Iin4  | Kod: 16777215 (0xFFFFFF) | ADC ulaz: 2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
[ADC] Strujni ulaz Iin4  | Kod: 16777215 (0xFFFFFF) | ADC ulaz: 2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
[ADC] Strujni ulaz Iin4  | Kod: 16777215 (0xFFFFFF) | ADC ulaz: 2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
[ADC] Strujni ulaz Iin4  | Kod: 16777215 (0xFFFFFF) | ADC ulaz: 2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
[ADC] Strujni ulaz Iin4  | Kod: 16777215 (0xFFFFFF) | ADC ulaz: 2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
[ADC] Strujni ulaz Iin4  | Kod: 16777215 (0xFFFFFF) | ADC ulaz: 2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
[ADC] Strujni ulaz Iin4  | Kod: 16777215 (0xFFFFFF) | ADC ulaz: 2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
[ADC] Strujni ulaz Iin4  | Kod: 16777215 (0xFFFFFF) | ADC ulaz: 2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
[ADC] Strujni ulaz Iin4  | Kod: 16777215 (0xFFFFFF) | ADC ulaz: 2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
[ADC] Strujni ulaz Iin4  | Kod: 16777215 (0xFFFFFF) | ADC ulaz: 2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 
Prekinut rad. 
root@NanoPi:~# 





    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
UPOZORENJE: RDYB i dalje 1 posle 100 pokusaja - preskacem ovaj ciklus.
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 99 3A BC 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 08 88 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 08 88 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 08 88 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 08 88 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 08 88 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 08 88 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 08 88 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
UPOZORENJE: RDYB i dalje 1 posle 100 pokusaja - preskacem ovaj ciklus.
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 68 CC 7C 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 68 CC 7C 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 68 CC 7C 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 68 CC 7C 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 68 CC 7C 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 68 CC 7C 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 68 CC 7C 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 



noviii

MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF F2 E3 13 
(RDYB se oslobodio posle 25 pokusaja, ~50 ms)
[ADC] Naponski ulaz Vin4 | Kod: 16773859 (0xFFF2E3) | ADC ulaz: 2.4990 V | ADC ulaz * 4.3: 10.7457 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF F2 E3 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF F3 E9 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF F3 E9 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF F3 E9 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF F3 E9 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF F3 E9 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF F3 E9 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF F3 E9 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF F3 E9 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF F3 E9 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF F3 E9 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF F3 E9 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF F3 E9 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF F3 E9 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF F3 E9 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF F3 E9 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF F3 E9 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF F3 E9 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF F3 E9 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF F3 E9 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF F3 E9 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF F3 E9 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF F3 E9 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF F3 E9 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 00 00 00 15 
(RDYB se oslobodio posle 25 pokusaja, ~50 ms)
[ADC] Strujni ulaz Iin2  | Kod: 0 (0x000000) | ADC ulaz: -2.5000 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 00 00 00 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 57 91 0F 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 A7 93 E6 17 
(RDYB se oslobodio posle 49 pokusaja, ~98 ms)
[ADC] Strujni ulaz Iin4  | Kod: 10982374 (0xA793E6) | ADC ulaz: 0.7730 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF A7 93 E6 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF EC 76 C6 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF EC 76 C6 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF EC 76 C6 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF EC 76 C6 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF EC 76 C6 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF EC 76 C6 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF EC 76 C6 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF EC 76 C6 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF EC 76 C6 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF EC 76 C6 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF EC 76 C6 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF EC 76 C6 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF EC 76 C6 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF EC 76 C6 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF EC 76 C6 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF EC 76 C6 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF EC 76 C6 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF EC 76 C6 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF EC 76 C6 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF EC 76 C6 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF EC 76 C6 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF EC 76 C6 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF EC 76 C6 97 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 80 0C 8E 11 
(RDYB se oslobodio posle 25 pokusaja, ~50 ms)
[ADC] Naponski ulaz Vin2 | Kod: 8391822 (0x800C8E) | ADC ulaz: 0.0010 V | ADC ulaz * 4.3: 0.0041 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 0C 8E 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 0E 88 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 0E 88 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 0E 88 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 0E 88 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 0E 88 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 0E 88 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 0E 88 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 0E 88 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 0E 88 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 0E 88 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 0E 88 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 0E 88 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 0E 88 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 0E 88 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 0E 88 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 0E 88 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 0E 88 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 0E 88 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 0E 88 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 0E 88 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 0E 88 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 80 0E 88 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 83 CF AF 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 91 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 8A 48 BE 13 
(RDYB se oslobodio posle 49 pokusaja, ~98 ms)
[ADC] Naponski ulaz Vin4 | Kod: 9062590 (0x8A48BE) | ADC ulaz: 0.2009 V | ADC ulaz * 4.3: 0.8637 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 8A 48 BE 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 82 18 B5 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 82 18 B5 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 82 18 B5 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 82 18 B5 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 82 18 B5 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 82 18 B5 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 82 18 B5 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 82 18 B5 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 82 18 B5 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 82 18 B5 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 82 18 B5 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 82 18 B5 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 82 18 B5 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 82 18 B5 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 82 18 B5 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 82 18 B5 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 82 18 B5 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 82 18 B5 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 82 18 B5 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 82 18 B5 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 82 18 B5 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 82 18 B5 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 82 18 B5 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: 00 FF FF FF 13 
(RDYB se oslobodio posle 25 pokusaja, ~50 ms)
[ADC] Naponski ulaz Vin4 | Kod: 16777215 (0xFFFFFF) | ADC ulaz: 2.5000 V | ADC ulaz * 4.3: 10.7500 V
[DAC] Osvezen naponski izlaz CH_A na kod 0
[DAC] Ocekivan napon na VOUT1: ~0.000 V
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF FF FF 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF FF F2 95 93 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF 83 B2 85 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF AB B2 97 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF AB B2 97 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF AB B2 97 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF AB B2 97 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF AB B2 97 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF AB B2 97 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF AB B2 97 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF AB B2 97 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF AB B2 97 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF AB B2 97 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF AB B2 97 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF AB B2 97 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF AB B2 97 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF AB B2 97 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF AB B2 97 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF AB B2 97 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF AB B2 97 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF AB B2 97 95 
    MOSI -> [5 B]: 42 00 00 00 00 
    MISO <- [5 B]: FF AB B2 97 95 
    MOSI -> [5 B]: 42 00 00 00 00 




root@NanoPi:~# ./quectel_test
Ukljucivanje Quectel modula...
  LDO ukljucen, cekam 200ms da se napon stabilizuje...
  PWRKEY nisko 2.5s...
  Cekam da modul zavrsi boot (6s)...
Modul bi trebalo da je spreman za AT komande.

tcgetattr: Input/output error
Ne mogu da otvorim UART ka modulu. Proveri QUECTEL_UART_DEVICE.



root@NanoPi:~# ls -la /dev/ttySS*
crw-rw---- 1 root tty     4, 64 Jan  1 01:00 /dev/ttySS0
crw-rw---T 1 root dialout 4, 65 Jan  1 01:00 /dev/ttySS1
crw-rw---T 1 root dialout 4, 66 Jan  1 01:00 /dev/ttySS2
crw-rw---T 1 root dialout 4, 67 Jan  1 01:00 /dev/ttySS3
crw-rw---T 1 root dialout 4, 68 Jan  1 01:00 /dev/ttySS4
crw-rw---T 1 root dialout 4, 69 Jan  1 01:00 /dev/ttySS5
crw-rw---T 1 root dialout 4, 70 Jan  1 01:00 /dev/ttySS6
crw-rw---T 1 root dialout 4, 71 Jan  1 01:00 /dev/ttySS7
root@NanoPi:~# dmesg | grep -i -E "ttyss|uart|serial"
[    0.000000] Kernel command line: console=ttySS0,115200 earlyprintk at24.io_limit=4096 root=LABEL=AtlasXBB_RootFS rootfstype=ext4 rw rootwait fsck.repair=yes panic=10 fbcon=map:0
[    2.235892] Serial: 8250/16550 driver, 8 ports, IRQ sharing disabled
[    2.241865] console [ttySS0] disabled
[    2.262232] 1c28000.serial: ttySS0 at MMIO 0x1c28000 (irq = 44, base_baud = 1500000) is a U6_16550A
[    3.068953] console [ttySS0] enabled
[    3.097737] 1c28400.serial: ttySS1 at MMIO 0x1c28400 (irq = 45, base_baud = 1500000) is a U6_16550A
[    3.128724] 1c28800.serial: ttySS2 at MMIO 0x1c28800 (irq = 46, base_baud = 1500000) is a U6_16550A
[    3.452275] usb usb1: New USB device strings: Mfr=3, Product=2, SerialNumber=1
[    3.470774] usb usb1: SerialNumber: 1c1a000.usb
[    3.583040] usb usb2: New USB device strings: Mfr=3, Product=2, SerialNumber=1
[    3.605611] usb usb2: SerialNumber: 1c1a400.usb
[    3.653288] usbcore: registered new interface driver usbserial
[    3.659276] usbcore: registered new interface driver usbserial_generic
[    3.665944] usbserial: USB Serial support registered for generic
[    4.243337] usb usb3: New USB device strings: Mfr=3, Product=2, SerialNumber=1
[    4.261780] usb usb3: SerialNumber: 1c1b000.usb
[    4.318216] usb usb4: New USB device strings: Mfr=3, Product=2, SerialNumber=1
[    4.336624] usb usb4: SerialNumber: 1c1c000.usb
[    4.392190] usb usb5: New USB device strings: Mfr=3, Product=2, SerialNumber=1
[    4.410623] usb usb5: SerialNumber: 1c1d000.usb
[    4.510018] usb usb6: New USB device strings: Mfr=3, Product=2, SerialNumber=1
[    4.529467] usb usb6: SerialNumber: 1c1b400.usb
[    4.629027] usb usb7: New USB device strings: Mfr=3, Product=2, SerialNumber=1
[    4.648476] usb usb7: SerialNumber: 1c1c400.usb
[    4.748060] usb usb8: New USB device strings: Mfr=3, Product=2, SerialNumber=1
[    4.767651] usb usb8: SerialNumber: 1c1d400.usb
[    4.816421] usb usb9: New USB device strings: Mfr=3, Product=2, SerialNumber=1
[    4.835036] usb usb9: SerialNumber: musb-hdrc.1.auto
root@NanoPi:~# for p in /dev/ttySS0 /dev/ttySS1 /dev/ttySS2 /dev/ttySS3 /dev/ttySS4 /dev/tty/SS5 /dev/ttySS6 /dev/ttySS7; do echo "== $p ==" stty -F $p 115200 raw -echo 2>&1; done
== /dev/ttySS0 == stty -F /dev/ttySS0 115200 raw -echo
== /dev/ttySS1 == stty -F /dev/ttySS1 115200 raw -echo
== /dev/ttySS2 == stty -F /dev/ttySS2 115200 raw -echo
== /dev/ttySS3 == stty -F /dev/ttySS3 115200 raw -echo
== /dev/ttySS4 == stty -F /dev/ttySS4 115200 raw -echo
== /dev/tty/SS5 == stty -F /dev/tty/SS5 115200 raw -echo
== /dev/ttySS6 == stty -F /dev/ttySS6 115200 raw -echo
== /dev/ttySS7 == stty -F /dev/ttySS7 115200 raw -echo
root@NanoPi:~# 



root@NanoPi:~# ./quectel_test
Ukljucivanje Quectel modula...
  LDO ukljucen, cekam 200ms da se napon stabilizuje...
  PWRKEY nisko 2.5s...
  Cekam da modul zavrsi boot (6s)...
Modul bi trebalo da je spreman za AT komande.

=== Osnovni test (da li modul uopste odgovara) ===
>> AT

=== GPRS/mobilna mreza ===
>> AT+CPIN?

>> AT+CSQ

>> AT+CREG?

>> AT+CGATT?

=== GNSS ===
>> AT+QGPS=1

>> AT+QGPSLOC?



razvoj@ubuntu:~/Desktop/teodora$ make
arm-linux-gnueabihf-gcc quectel_test.c -o quectel_test -lm -ggdb
quectel_test.c: In function ‘quectel_power_on’:
quectel_test.c:91:17: error: ‘GPIO_LDO_ON’ undeclared (first use in this function)
quectel_test.c:91:17: note: each undeclared identifier is reported only once for each function it appears in
quectel_test.c:92:17: error: ‘GPIO_PWRKEY’ undeclared (first use in this function)
quectel_test.c:93:17: error: ‘GPIO_RESET’ undeclared (first use in this function)
quectel_test.c: In function ‘quectel_uart_open’:
quectel_test.c:125:19: error: ‘QUECTEL_UART_DEVICE’ undeclared (first use in this function)
quectel_test.c:127:9: error: too many arguments to function ‘perror’
In file included from quectel_test.c:9:0:
/usr/lib/gcc-cross/arm-linux-gnueabihf/4.7/../../../../arm-linux-gnueabihf/include/stdio.h:846:13: note: declared here
quectel_test.c:139:23: error: ‘QUECTEL_BAUD’ undeclared (first use in this function)
make: *** [quectel_test] Error 1


razvoj@ubuntu:~/Desktop/teodora$ head -30 quectel_test.c
// quectel_test.c
// Test program za Quectel EG912U-GL modul (GPRS/GNSS) na Atlas-TPL BB plocici.
// Radi DVE stvari: (1) upali modul preko GPIO-a (LDO + PWRKEY), (2) salje
// AT komande preko UART-a i cita odgovor.
//
// Kompajliranje: gcc quectel_test.c -o quectel_test
// Pokretanje:    sudo ./quectel_test   (root je potreban zbog /sys/class/gpio)

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>

/* GPIO brojevi - (GPIO_A17/A20/A21 -> sysfs 17/20/21).

#define GPIO_LDO_ON   21   // GNSS_LDO_ON  - napajanje modula (BB plocica)
#define GPIO_PWRKEY   20   // GNSS_PWR_KEY - PWRKEY modula (Quectel pin 15)
#define GPIO_RESET    17   // GNSS_RST_KEY - RESET_N modula (Quectel pin 17)

/* UART port ka MAIN_TXD/MAIN_RXD (Quectel pinovi 35/34)

#define QUECTEL_UART_DEVICE   "/dev/ttySS1"  
#define QUECTEL_BAUD           B115200

/* ===================== GPIO (sysfs) pomocne funkcije ===================== */

/**


