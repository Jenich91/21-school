PROJECTNAME=s21_smartCalc
.PHONY: all clean test $(PROJECTNAME).a gcov_report linter cppcheck style_check

INSTALL_PATH=../Build
CC=gcc
CFLAGS=-c -std=c11 
CFLAGS_WARN= -Wpedantic -Wshadow -Wuninitialized -Wall -Werror -Wextra 
LDFLAGS= -lcheck -L. -l$(PROJECTNAME)
GFLAGS= -fprofile-arcs -ftest-coverage
HEADERS=$(PROJECTNAME).h
SOURCES=$(PROJECTNAME).c

OBJECTS=$(SOURCES:.c=.o)
OS := $(shell uname -s)

all: clean $(PROJECTNAME).a install dvi
$(OBJECTS): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES)

$(PROJECTNAME).a: $(OBJECTS)
	ar rc $(PROJECTNAME).a $(OBJECTS)
	cp $(PROJECTNAME).a lib$(PROJECTNAME).a

test: $(PROJECTNAME).a
	$(CC) test.c $(PROJECTNAME).a $< -o test.out $(LDFLAGS)
	./test.out

gcov_report: clean
	$(CC) $(CFLAGS) $(SOURCES) $(GFLAGS)
	ar rcs lib$(PROJECTNAME).a $(OBJECTS)
	$(CC) -o test.out test.c $(LDFLAGS) -lgcov
	rm -f *.o
	./test.out
	lcov -c -d . -o coverage.info
	genhtml coverage.info -o gcov_report

.IGNORE: linter
linter:
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extensions=c test.c $(PROJECTNAME).c $(PROJECTNAME).h
	rm -rf CPPLINT.cfg

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem test.c $(PROJECTNAME).c $(PROJECTNAME).h

style_check: linter cppcheck

debug: $(PROJECTNAME).a
	$(CC) -g test.c $(PROJECTNAME).c $< -o debug.out $(LDFLAGS)

check: debug style_check
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./debug.out
else
	valgrind -q --tool=memcheck --leak-check=full --leak-resolution=med ./debug.out
endif

install:
	qmake smartcalc.pro -o Qmakefile
	make -f Qmakefile install INSTALL_ROOT=$(INSTALL_PATH)
	rm -rf smartcalc.app
	make  dvi

uninstall:
	rm -rf $(INSTALL_PATH)/smartcalc

dist: install dvi
	tar -cvzf smartcalc_1.0.tar.gz $(INSTALL_PATH)/smartcalc
	cp smartcalc_1.0.tar.gz $(INSTALL_PATH)/../
	rm smartcalc_1.0.tar.gz

dvi:
	makeinfo --html --no-split -o README.html smartcalc.texi --force
	mkdir -p $(INSTALL_PATH)/smartcalc/
	cp README.html $(INSTALL_PATH)/smartcalc/
	rm README.html

clean:
	make -f Qmakefile clean
	rm -rf $(OBJECTS) *.a *.out *.gcda *.gcno *.info *.cfg gcov_report *.dSYM *.gch *.app .tmp .qmake.stash lib*.a