.PHONY: all clean check test s21_cat s21_grep

default: all

all: s21_cat s21_grep

s21_cat:
	make s21_cat -C cat/

s21_grep:
	make s21_grep -C grep/

clean:
	make clean -C cat/
	make clean -C grep/

test:
	make test -C cat/
	make test -C grep/

check:
	make check -C cat/
	make check -C grep/
