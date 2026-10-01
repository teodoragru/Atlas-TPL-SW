#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int gpio_export(int gpio) {

	int fd;
	char tmp[1024];

	if(gpio < 0)
		return -1;

	if ((fd = open("/sys/class/gpio/export", O_WRONLY)) < 0) {
	     printf("Unable to open export for GPIO %d\n", gpio);
	     return -1;
        }

	sprintf(tmp, "%d", gpio);
	if(write(fd, tmp, strlen(tmp)) <= 0) {
	     printf("Unable to export GPIO pin %d\n", gpio);
	     close(fd);
             return -1;
	}

	close(fd);

	return 0;
}


int gpio_direction_input(int gpio){
	int fd;
	char tmp[1024];
	
	if(gpio < 0)
		return -1;

	sprintf(tmp, "/sys/class/gpio/gpio%d/direction", gpio);
	if ((fd = open(tmp, O_WRONLY)) < 0) {
             printf("Unable to open direction for GPIO %d\n", gpio);
             return -1;
        }

	sprintf(tmp, "in");
	if(write(fd, tmp, strlen(tmp)) < 0) {
             printf("Unable to set direction for GPIO %d\n", gpio);
             close(fd);
             return -1;
        }
	close(fd);

	sprintf(tmp, "/sys/class/gpio/gpio%d/value", gpio);
	if ((fd = open(tmp, O_RDWR)) < 0) {
	  fprintf(stderr,"Failed to open /sys/class/gpio/gpio%d/value\n", gpio);
	  return -1;
        }

	return fd;
}

int gpio_direction_output(int gpio, int val) {

	int fd;
	char tmp[1024];
	
	if(gpio < 0)
		return -1;

	sprintf(tmp, "/sys/class/gpio/gpio%d/direction", gpio);
	if ((fd = open(tmp, O_WRONLY)) < 0) {
             printf("Unable to open direction for GPIO %d\n", gpio);
             return -1;
        }

	sprintf(tmp, "out");
	if(write(fd, tmp, strlen(tmp)) < 0) {
             printf("Unable to set direction for GPIO %d\n", gpio);
             close(fd);
             return -1;
        }
	close(fd);

	sprintf(tmp, "/sys/class/gpio/gpio%d/value", gpio);
	if ((fd = open(tmp, O_RDWR)) < 0) {
	  fprintf(stderr,"Failed to open /sys/class/gpio/gpio%d/value\n", gpio);
	  return -1;
        }

	sprintf(tmp, "%d", val);
	if(write(fd, tmp, strlen(tmp)) <= 0) {
	  fprintf(stderr,"Failed to write initial value for gpio %d\n", gpio);
	}

	return fd;
}

int gpio_read(int fd) {
	
	char tmp[8];
	int ret;

	lseek(fd, 0, SEEK_SET);

	if(read(fd, tmp, 8) > 0)
		ret = atoi(tmp);
	else
		ret = -1;

	return ret;
}

int gpio_write(int fd, int val) {
	
	char tmp[8];
	int ret;
	if(fd < 0)
		return -1;

	sprintf(tmp, "%d", val);
	if(write(fd, tmp, 1) > 0)
		ret = 0;
	else
		ret = -1;

	return ret;
}

int gpio_unexport(int gpio) {
	int fd;
	char tmp[1024];

	if ((fd = open("/sys/class/gpio/unexport", O_WRONLY)) < 0) {
	     printf("Unable to open unexport for GPIO %d\n", gpio);
	     return -1;
        }

	sprintf(tmp, "%d", gpio);
	if(write(fd, tmp, strlen(tmp)) <= 0) {
	     printf("Unable to unexport GPIO pin %d\n", gpio);
	     close(fd);
             return -1;
	}

	close(fd);

	return 0;
}
