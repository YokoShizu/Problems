CC = gcc

CFLAGS = -Wall -Werror -Wextra -std=c11 -g
TEST = s21_decimal_tests.c -lcheck -lsubunit -lrt -lpthread -lm
#To run tests on my school mac I need to add: -I/opt/goinfre/wholemew/brew/opt/check/include -L/opt/goinfre/wholemew/brew/opt/check/lib
#For Linux users add to TEST: -lsubunit -lrt -lpthread -lm
SRC = s21_add.c s21_auxiliary.c s21_div.c s21_floor.c s21_from_decimal_to_float.c s21_from_decimal_to_int.c s21_from_float_to_decimal.c s21_from_int_to_decimal.c s21_is_equal.c s21_is_greater_or_equal.c s21_is_greater.c s21_is_less_or_equal.c s21_is_less.c s21_is_not_equal.c s21_mul.c s21_negate.c s21_round.c s21_sub.c s21_truncate.c

all: s21_decimal.a

s21_decimal.a: *.o
	ar rcs s21_decimal.a *.o
	ranlib s21_decimal.a

*.o: *.c s21_decimal.h
	$(CC) $(CFLAGS) -c $(SRC)

clean:
	rm -rf *.o s21_decimal.a
	rm *.out
	rm *.info
	rm *.gcda
	rm *.gcno
	rm -rf report

test: s21_decimal.a
	$(CC) $(CFLAGS) $(TEST) -o unit_test.out s21_decimal.a 
	./unit_test.out

gcov_report: test
	$(CC) -fprofile-arcs -ftest-coverage --coverage $(TEST) $(SRC) -o test.out
	./test.out
	mkdir -p report
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory report
	open ./report/index.html

style:
	cp ../materials/linters/.clang-format .
	clang-format -i *.c *.h
	clang-format -n *.c *.h
	rm .clang-format