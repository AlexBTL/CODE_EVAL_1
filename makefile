CC         = gcc 
XFLAGS     = -W -Wall -Werror -pedantic
INC1       = ./Firmware/HAL
INCDIRS    = -I ${INC1} 
CFLAGS     = ${INCDIRS} ${XFLAGS} 

HowManyOne: HowManyOne.o Main.o
	gcc -o HowManyOne HowManyOne.o Main.o

HowManyOne.o: ./Firmware/HAL/HowManyOne.c ./Firmware/HAL/HowManyOne.h
	gcc -o HowManyOne.o -c ./Firmware/HAL/HowManyOne.c ${CFLAGS}

Main.o: ./Firmware/APP/Main.c ./Firmware/HAL/HowManyOne.h
	gcc -o Main.o -c ./Firmware/APP/Main.c ${CFLAGS}			

