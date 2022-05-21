.PHONY: all clean test s21_string.a check gcov_report
CC=gcc -std=c11
CC2=gcc -D_GNU_Source -std=c11
LDFLAGS= -Wall -Wextra -Werror
OS := $(shell uname -s)

default: all

all: clean s21_string.a test  

test: s21_string.a
ifeq ($(OS), Darwin)
	$(CC) $(LDFLAGS) -o test test.c s21_string.a -L$(HOME)/homebrew/Cellar/check/0.15.2/lib/ -I$(HOME)/homebrew/include -lcheck
	./test
else
	$(CC2) $(LDFLAGS) -c test.c
	$(CC) $(LDFLAGS) -o test test.o s21_string.a -lcheck -pthread -lcheck_pic -pthread -lrt -lm -lsubunit
	./test
endif

s21_string.a:
ifeq ($(OS), Darwin)
	$(CC) $(LDFLAGS) -c -o s21_string.o -c s21_string.c -I$(HOME)/homebrew/include
	ar rc s21_string.a s21_string.o
	ranlib s21_string.a
else
	$(CC2) $(LDFLAGS) -c -o s21_string.o -c s21_string.c -lcheck
	ar rc s21_string.a s21_string.o
	ranlib s21_string.a
endif

clean:
	rm -rf *.a *.o *.out *.dSYM *.gcno *.gcda *.cov *.info report *.cfg

gcov_report: clean s21_string.a
ifeq ($(OS), Darwin)
	$(CC) --coverage -o test test.c s21_string.c -L$(HOME)/homebrew/Cellar/check/0.15.2/lib/ -I$(HOME)/homebrew/include -lcheck
else
	$(CC2) --coverage -o test test.c s21_string.c -lcheck -pthread -lcheck_pic -pthread -lrt -lm -lsubunit
endif
	./test
	lcov -t "test.cov" -o test.info -c -d .
	genhtml -o report test.info

debug:
ifeq ($(OS), Darwin)
	$(CC) $(LDFLAGS) -g -Og -o test test.c s21_string.a -L$(HOME)/homebrew/Cellar/check/0.15.2/lib/ -I$(HOME)/homebrew/include -lcheck
else
	$(CC2) -g -Og -o  test test.c s21_string.c -lcheck -pthread -lcheck_pic -pthread -lrt -lm -lsubunit
endif

check: debug
	cppcheck *.h *.c
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c *.c *.h
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./test
else
	valgrind -q --tool=memcheck --leak-check=full --leak-resolution=med ./test
endif