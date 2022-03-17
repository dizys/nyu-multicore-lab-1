GCC_BIN=gcc
GCC_STD=c99

.PHONY: clean

all: random-num zz2960seq zz2960ver1 zz2960ver2

random-num: random-num.c
	$(GCC_BIN) -Wall -o random-num -std=$(GCC_STD) random-num.c

zz2960seq: zz2960seq.c
	$(GCC_BIN) -Wall -o zz2960seq -std=$(GCC_STD) zz2960seq.c

zz2960ver1: zz2960ver1.c
	$(GCC_BIN) -fopenmp -Wall -o zz2960ver1 -std=$(GCC_STD) zz2960ver1.c

zz2960ver2: zz2960ver2.c
	$(GCC_BIN) -fopenmp -Wall -o zz2960ver2 -std=$(GCC_STD) zz2960ver2.c

clean:
	rm -f random-num zz2960seq zz2960ver1 zz2960ver2
