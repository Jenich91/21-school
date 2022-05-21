.PHONY: all clean test s21_matrix.a gcov_report linter cppcheck style_check
CC=gcc
CFLAGS=-c -std=c11 
CFLAGS_WARN= -Wpedantic -Wshadow -Wuninitialized -Wall -Werror -Wextra 
PROJECTNAME=s21_matrix
LDFLAGS= -lcheck -L. -l$(PROJECTNAME)
GFLAGS= -fprofile-arcs -ftest-coverage
HEADERS=$(PROJECTNAME).h
SOURCES=$(PROJECTNAME).c

OBJECTS=$(SOURCES:.c=.o)
OS := $(shell uname)

ifeq ($(OS), Linux) 
	LDFLAGS += -lrt -lm -lpthread -lsubunit
endif

all: $(PROJECTNAME).a test clean gcov_report
$(OBJECTS): $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $(SOURCES)

$(PROJECTNAME).a: $(OBJECTS)
	ar rc $(PROJECTNAME).a $(OBJECTS)
	cp $(PROJECTNAME).a lib$(PROJECTNAME).a

clean:
	rm -rf $(OBJECTS) *.a *.out *.gcda *.gcno *.info *.cfg gcov_report *.dSYM

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
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h
	rm -rf CPPLINT.cfg

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem test.c $(PROJECTNAME).c *.h

style_check: linter cppcheck

debug: $(PROJECTNAME).a
	$(CC) test.c $(PROJECTNAME).c $< -o debug.out $(LDFLAGS)

check: debug style_check
ifeq ($(OS), Darwin)
	CK_FORK=no leaks --atExit -- ./debug.out
else
	valgrind -q --tool=memcheck --leak-check=full --leak-resolution=med ./debug.out
endif