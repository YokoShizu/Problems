CC = g++
CC_FLAGS = -Wall -Werror -Wextra -std=c++20 -g
LFLAGS = -lm
GTEST_FLAGS = -pthread -lgtest
GCOV_FLAGS = --coverage -fprofile-arcs -ftest-coverage

SOURCES_FILES = s21_matrix_oop.cpp
HEADERS = s21_matrix_oop.h
TEST_FILES = unit_tests/unit_tests.cpp

LIBRARY = s21_matrix_oop.a
OBJECTS = $(SOURCES_FILES:.cpp=.o)
COVERAGE_OBJECTS = $(SOURCES_FILES:.cpp=_gcov.o)
EXECUTABLE = unit_tests/unit_tests.out


all: $(LIBRARY)

$(LIBRARY): $(OBJECTS)
		ar rcs $@ $^

$(OBJECTS): $(SOURCES_FILES) $(HEADERS)
		$(CC) $(CC_FLAGS) -c $< -o $@

$(COVERAGE_OBJECTS): $(SOURCES_FILES) $(HEADERS)
		$(CC) $(CC_FLAGS) $(GCOV_FLAGS ) -c $< -o $@
		ar rcs $(LIBRARY) $@

clean:
		rm -rf report
		rm -rf *.info $(OBJECTS) $(COVERAGE_OBJECTS) $(LIBRARY) $(EXECUTABLE) unit_tests/*.gcno unit_tests/*.gcda .clang-format

test: test all
		$(CC) $(CC_FLAGS) $(TEST_FILES) $(LIBRARY) $(LFLAGS) $(GTEST_FLAGS) -o $(EXECUTABLE)
		./$(EXECUTABLE)

gcov_report: clean $(COVERAGE_OBJECTS)
		mkdir -p report
		$(CC) $(CC_FLAGS) $(GCOV_FLAGS) $(SOURCES_FILES) $(TEST_FILES) $(LIBRARY) $(LFLAGS) $(GTEST_FLAGS) -o $(EXECUTABLE)
		./$(EXECUTABLE)
		lcov --capture --directory . --output-file coverage.info --ignore-errors mismatch
		lcov -e coverage.info 's21_matrix_oop.cpp' -o coverage_filtered.info
		genhtml coverage_filtered.info --output-directory report
		xdg-open report/index.html

clang_check:
		clang-format -n *.cpp unit_tests/*.cpp *.h

clang_fix:
		clang-format -i *.cpp unit_tests/*.cpp *.h

clang_copy:
		cp ../materials/linters/.clang-format .

valgrind_check: test
		valgrind --tool=memcheck --leak-check=yes -s ./$(EXECUTABLE)