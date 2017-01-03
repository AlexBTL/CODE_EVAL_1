How_Many_One: How_Many_One.o Main.o
	gcc -o How_Many_One How_Many_One.o Main.o


How_Many_One.o: ./Firmware/HAL/How_Many_One.c ./Firmware/HAL/How_Many_One.h
	gcc -o How_Many_One.o -c ./Firmware/HAL/How_Many_One.c -W -Wall -Werror -pedantic

Main.o: ./Firmware/APP/Main.c ./Firmware/HAL/How_Many_One.h
	gcc -o Main.o -c ./Firmware/APP/Main.c -W -Wall -Werror -pedantic				