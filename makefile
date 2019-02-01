all: picmaker.c
	gcc -o pmaker picmaker.c -lm
	./pmaker

clean:
	rm -f *.png *.ppm pmaker
