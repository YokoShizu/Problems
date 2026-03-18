#include <regex.h>
#include <stdio.h>
#include <string.h>

#include "compareRegex_grep.h"

int notRepeated_grep(char *pars_res, char *string, char **argv, int j, int l) {
  int flag = 1;
  for (int k = l + 1; k < j; k++) {
    if (strstr(pars_res, "i") != 0) {
      if (compareRegex_grep(string, argv[k], 1) == 0) {
        flag = 0;
        break;
      }
    } else {
      if (compareRegex_grep(string, argv[k], 0) == 0) {
        flag = 0;
        break;
      }
    }
  }
  return flag;
}
