all: dac_us

dac_us: dac_us.c 
	arm-linux-gnueabihf-gcc dac_us.c gpio.c -o dac_us -lm -ggdb

clean:
	rm -f *.o 
	rm -f *~
	rm -f dac_us

