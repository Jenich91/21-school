.PHONY: all clean check test s21_cat
CC=gcc -std=c11
CC2=gcc -std=c11 -D_GNU_Source
LDFLAGS= -Wall -Wextra -Werror
OS := $(shell uname -s)

default: all

all: s21_cat

s21_cat: clean
ifeq ($(OS), Darwin)
	$(CC) $(LDFLAGS) *.c -o s21_cat	
else
	$(CC2) $(LDFLAGS) *.c -o s21_cat
endif

clean:
	rm -rf *.txt
	rm -rf *_out
	rm -rf *.dSYM
	rm -rf *.cfg
	rm -rf *.a
	rm -rf *.o
	rm -rf *.out
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.cov
	rm -rf *.info
	rm -rf report

test:
	sh test_cat.sh

debug:
	$(CC2) -g -Og -o s21_cat s21_cat.c 

check: debug
	cppcheck *.h *.c
	cp ../../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../../materials/linters/cpplint.py --extension=c *.c *.h
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./s21_cat
else
	valgrind -q --tool=memcheck --leak-check=full --leak-resolution=med ./s21_cat
endif