CC=gcc

CFLAGS =-Wall -Werror -Wextra -std=c11 -c

all: s21_grep

s21_grep: s21_grep.o applyOptions_grep.o presenceStringNumber_grep.o printCL_grep.o onlyTheSameParts_grep.o notRepeated_grep.o parser.o quantity.o core_grep.o searchOptions.o searchRepeats.o strlensum.o searchTemplate_grep.o compareRegex_grep.o
	$(CC) s21_grep.o applyOptions_grep.o presenceStringNumber_grep.o notRepeated_grep.o printCL_grep.o onlyTheSameParts_grep.o parser.o quantity.o core_grep.o searchOptions.o searchRepeats.o strlensum.o searchTemplate_grep.o compareRegex_grep.o -o s21_grep

s21_grep.o: s21_grep.c ../common/strlensum.h ../common/parser.h ../common/quantity.h applyOptions_grep.h ../common/searchRepeats.h
	$(CC) $(CFLAGS) s21_grep.c
	
applyOptions_grep.o: applyOptions_grep.c printCL_grep.h core_grep.h
	$(CC) $(CFLAGS) applyOptions_grep.c

presenceStringNumber_grep.o: presenceStringNumber_grep.c
	$(CC) $(CFLAGS) presenceStringNumber_grep.c

onlyTheSameParts_grep.o: onlyTheSameParts_grep.c
	$(CC) $(CFLAGS) onlyTheSameParts_grep.c
	
core_grep.o: core_grep.c searchTemplate_grep.h onlyTheSameParts_grep.h presenceStringNumber_grep.h
	$(CC) $(CFLAGS) core_grep.c

printCL_grep.o: printCL_grep.c notRepeated_grep.h
	$(CC) $(CFLAGS) printCL_grep.c
	
notRepeated_grep.o: notRepeated_grep.c
	$(CC) $(CFLAGS) notRepeated_grep.c

searchTemplate_grep.o: searchTemplate_grep.c compareRegex_grep.h
	$(CC) $(CFLAGS) searchTemplate_grep.c

parser.o: ../common/parser.c ../common/strlensum.h ../common/searchOptions.h ../common/searchRepeats.h
	$(CC) $(CFLAGS) ../common/parser.c

quantity.o: ../common/quantity.c ../common/searchRepeats.h
	$(CC) $(CFLAGS) ../common/quantity.c

searchOptions.o: ../common/searchOptions.c ../common/strlensum.h ../common/quantity.h
	$(CC) $(CFLAGS) ../common/searchOptions.c

searchRepeats.o: ../common/searchRepeats.c
	$(CC) $(CFLAGS) ../common/searchRepeats.c

strlensum.o: ../common/strlensum.c
	$(CC) $(CFLAGS) ../common/strlensum.c
	
compareRegex_grep.o: compareRegex_grep.c
	$(CC) $(CFLAGS) compareRegex_grep.c

clean:
	rm -rf *.o s21_grep

gtest:
	sh general_test.sh
	
ltest:
	sh leak_test.sh
