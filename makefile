main: main.cpp bild.o audio.o median.o #list.o
	c++ main.cpp -o main bild.o audio.o median.o -std=c++11

bild.o: bild.cpp bild.h
	c++ bild.cpp -c -std=c++11

audio.o: audio.cpp audio.h
	c++ audio.cpp -c -std=c++11

median.o: median.cpp median.h
	c++ median.cpp -c -std=c++11
# list.o: list.cpp list.h
	 c++ list.cpp -c -std=c++11
clean:
	rm -f *.o main

