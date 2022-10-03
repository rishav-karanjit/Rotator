output: main.o Rotator.o ColorPixel.o GreyPixel.o
	g++ main.o Rotator.o ColorPixel.o GreyPixel.o -o output

main.o: main.cpp
	g++ -c main.cpp

Rotator.o: Rotator.cpp Rotator.h
	g++ -c Rotator.cpp

ColorPixel.o: ColorPixel.cpp ColorPixel.h
	g++ -c ColorPixel.cpp

GreyPixel.o: GreyPixel.cpp GreyPixel.h
	g++ -c GreyPixel.cpp

clean:
	rm *.o output