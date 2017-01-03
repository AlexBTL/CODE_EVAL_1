How_Many_One: How_Many_One.o
	gcc -o How_Many_One How_Many_One.o 


How_Many_One.o: ./Firmware/APP/How_Many_One.c ./Firmware/APP/How_Many_One.h
	gcc -o How_Many_One.o -c ./Firmware/APP/How_Many_One.c -W -Wall -Werror -pedantic

				