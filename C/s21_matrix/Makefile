CC = gcc

CFLAGS = -Wall -Werror -Wextra -std=c11 -g
TEST = s21_matrix_test.c -lcheck -lsubunit -lrt -lpthread -lm
SRC = s21_matrix.c

all: s21_matrix.a

s21_matrix.a: *.o
	ar rcs s21_matrix.a *.o
	ranlib s21_matrix.a

*.o: *.c s21_matrix.h
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -rf *.o s21_matrix.a report *.out* *.info index.* *.html .clang-format

test: s21_matrix.a
	$(CC) $(CFLAGS) $(TEST) -o unit_tests.out s21_matrix.a 
	./unit_tests.out

gcov_report: s21_matrix.a
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage --coverage $(TEST) $(SRC) -o unit_tests.out
	./unit_tests.out
	mkdir -p report
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory report
	open ./report/index.html

gcovr_report: s21_matrix.a
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage $(TEST) $(SRC) -o unit_tests.out
	./unit_tests.out
	gcovr -r . --txt-metric branch --html --html-details -o index.html
	open ./index.html

clang_copy:
	cp ../materials/linters/.clang-format .

style_check:
	clang-format -n *.c *.h

style_fix:
	clang-format -i *.c *.h

valgrind:
	valgrind --tool=memcheck --leak-check=yes -s ./unit_tests.out