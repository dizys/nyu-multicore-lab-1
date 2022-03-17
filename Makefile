GCC_BIN=gcc
GCC_STD=c99

.PHONY: clean

all: zz2960seq zz2960ver1 zz2960ver2

zz2960seq: zz2960seq.c
	$(GCC_BIN) -o zz2960seq -std=$(GCC_STD) zz2960seq.c

zz2960ver1: zz2960ver1.c
	$(GCC_BIN) -o zz2960ver1 -std=$(GCC_STD) zz2960ver1.c

zz2960ver2: zz2960ver2.c
	$(GCC_BIN) -o zz2960ver2 -std=$(GCC_STD) zz2960ver2.c

clean:
	rm -f zz2960seq zz2960ver1 zz2960ver2