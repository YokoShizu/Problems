#include <stdio.h>
#include <string.h>

#include "searchRepeats.h"

int flags_quantity(int argc, char **argv) {
  int flags_quan = 0;
  if (strstr(argv[0], "s21_cat") != NULL) {
    for (int i = 1; i < argc; i++) {
      if (argv[i][0] == '-' && argv[i][1] == '-' && argv[i][2] != '-') {
        flags_quan++;
        break;
      }
      if (argv[i][0] == '-' && argv[i][1] != '-')
        flags_quan++;
    }
  } else if (strstr(argv[0], "s21_grep") != NULL) {
    for (int i = 1; i < argc - 1; i++) {
      if (argv[i][0] == '-' && argv[i][1] != '-') {
        flags_quan++;
        if (strstr(argv[i], "f") != NULL || strstr(argv[i], "e") != NULL)
          i++;
      }
    }
  }
  return flags_quan;
}

int templs_quantity(int argc, char **argv, int flags_quantity) {
  int templs_quan = 0;
  for (int i = 2; i < argc; i++) {
    if (searchE(argc, argv) == 0 && searchF(argc, argv) == 0 &&
        strstr(argv[i - 1], "-") != NULL) {
      templs_quan++;
      break;
    } else if (strstr(argv[i - 1], "f") != NULL && argv[i - 1][0] == '-')
      templs_quan++;
    else if (strstr(argv[i - 1], "e") != NULL && argv[i - 1][0] == '-')
      templs_quan++;
  }
  if (flags_quantity == 0)
    templs_quan = 1;
  return templs_quan;
}

int min(int a, int b) {
  int minimum = a;
  if (a > b)
    minimum = b;
  return minimum;
}
