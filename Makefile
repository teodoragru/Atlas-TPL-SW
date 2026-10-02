all: dac_us

dac_us: dac_us.c 
	arm-linux-gnueabihf-gcc dac_us.c gpio.c -o dac_us -lm -ggdb -static
	
ad4130_test: ad4130_test.c
	arm-linux-gnueabihf-gcc ad4130_test.c gpio.c -o ad4130_test -lm -ggdb -static

clean:
	rm -f *.o 
	rm -f *~
	rm -f dac_us
	rm -f ad4130_test

