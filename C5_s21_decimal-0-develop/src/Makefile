.PHONY: clean all linter cppcheck test style_check gcov_report
CC=gcc
CFLAGS=-c -Wall -Werror -Wextra -std=c11
LDFLAGS= -lcheck -L. -ls21_decimal
GFLAGS= -fprofile-arcs -ftest-coverage
HEADERS=s21_decimal.h
SOURCES=s21_decimal.c

OBJECTS=$(SOURCES:.c=.o)
OS := $(shell uname)

ifeq ($(OS), Linux) 
	LDFLAGS += -lrt -lm -lpthread -lsubunit
endif

all: s21_decimal.a

$(OBJECTS): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES)

s21_decimal.a: $(OBJECTS)
	ar rc s21_decimal.a $(OBJECTS)
	cp s21_decimal.a libs21_decimal.a

clean:
	rm -rf $(OBJECTS) *.a *.out *.gcda *.gcno *.info *.cfg gcov_report

test: test.c s21_decimal.a
	$(CC) s21_decimal.a $< -o test.out $(LDFLAGS)
	./test.out

gcov_report: clean
	$(CC) $(CFLAGS) $(SOURCES) $(GFLAGS)
	ar rcs libs21_decimal.a $(OBJECTS)
	$(CC) -o test.out test.c $(LDFLAGS) -lgcov
	rm -f *.o
	./test.out
	lcov -c -d . -o coverage.info
	genhtml coverage.info -o gcov_report

.IGNORE: linter
linter:
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h
	rm -rf CPPLINT.cfg

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem --suppress=invalidPointerCast  *.c *.h

style_check: linter cppcheck

