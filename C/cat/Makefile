CC=gcc

CFLAGS =-Wall -Werror -Wextra -std=c11 -c

all: s21_cat

s21_cat: s21_cat.o applyOptions_cat.o squeezeStrings_cat.o numberStrings_cat.o printTabs_cat.o printEnds_cat.o nonPrint_cat.o parser.o quantity.o searchOptions.o searchRepeats.o strlensum.o
	$(CC) s21_cat.o applyOptions_cat.o squeezeStrings_cat.o numberStrings_cat.o printTabs_cat.o printEnds_cat.o nonPrint_cat.o parser.o quantity.o searchOptions.o searchRepeats.o strlensum.o -o s21_cat

s21_cat.o: s21_cat.c ../common/searchRepeats.h ../common/strlensum.h ../common/parser.h ../common/quantity.h applyOptions_cat.h
	$(CC) $(CFLAGS) s21_cat.c
	
applyOptions_cat.o: applyOptions_cat.c printEnds_cat.h numberStrings_cat.h squeezeStrings_cat.h printTabs_cat.h nonPrint_cat.h
	$(CC) $(CFLAGS) applyOptions_cat.c
	
squeezeStrings_cat.o: squeezeStrings_cat.c
	$(CC) $(CFLAGS) squeezeStrings_cat.c

numberStrings_cat.o: numberStrings_cat.c
	$(CC) $(CFLAGS) numberStrings_cat.c

printTabs_cat.o: printTabs_cat.c nonPrint_cat.h
	$(CC) $(CFLAGS) printTabs_cat.c

printEnds_cat.o: printEnds_cat.c nonPrint_cat.h
	$(CC) $(CFLAGS) printEnds_cat.c

nonPrint_cat.o: nonPrint_cat.c
	$(CC) $(CFLAGS) nonPrint_cat.c

parser.o: ../common/parser.c ../common/strlensum.h ../common/searchOptions.h ../common/searchRepeats.h
	$(CC) $(CFLAGS) ../common/parser.c

quantity.o: ../common/quantity.c
	$(CC) $(CFLAGS) ../common/quantity.c
	
searchRepeats.o: ../common/searchRepeats.c
	$(CC) $(CFLAGS) ../common/searchRepeats.c

searchOptions.o: ../common/searchOptions.c ../common/strlensum.h ../common/quantity.h
	$(CC) $(CFLAGS) ../common/searchOptions.c

strlensum.o: ../common/strlensum.c
	$(CC) $(CFLAGS) ../common/strlensum.c

clean:
	rm -rf *.o s21_cat

gtest:
	sh general_test.sh
	
ltest:
	sh leak_test.sh
