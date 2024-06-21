#include <stdio.h>
#include <string.h>

#include "quantity.h"
#include "strlensum.h"

int searchOptions(int flags_q, int *fflag, int templs_q, char *pars_res,
                  char **argv) {
  int flag_result = 0, flag_diff_os = 0;
  size_t number = 0;
  for (int i = 1; i < flags_q + templs_q + 1; i++) {
    for (size_t j = 1; j < strlen(argv[i]); j++) {
      if (strstr(argv[0], "s21_cat") != NULL && strstr(argv[i], "--") != NULL) {
        flag_diff_os = -2;
        if (strcmp(argv[i], "--number-nonblank") == 0)
          pars_res[number] = 'b';
        else if (strcmp(argv[i], "--number") == 0)
          pars_res[number] = 'n';
        else if (strcmp(argv[i], "--squeeze-blank") == 0)
          pars_res[number] = 's';
        else if (strcmp(argv[i], "--show-nonprinting") == 0)
          pars_res[number] = 'v';
      } else if (strstr(argv[0], "s21_cat") != NULL && flag_diff_os != -2 &&
                 argv[i][0] == '-' &&
                 (argv[i][j] == 'b' || argv[i][j] == 'n' || argv[i][j] == 's' ||
                  argv[i][j] == 'v' || argv[i][j] == 'e' || argv[i][j] == 't' ||
                  argv[i][j] == 'E' || argv[i][j] == 'T')) {
        pars_res[number] = argv[i][j];
        number++;
        if ((argv[i][j] == 'e' || argv[i][j] == 't') && flag_diff_os != -1)
          flag_diff_os = 1;
        else if ((argv[i][j] == 'E' || argv[i][j] == 'T') && flag_diff_os != 1)
          flag_diff_os = -1;
        else if (((argv[i][j] == 'e' || argv[i][j] == 't') &&
                  flag_diff_os == -1) ||
                 ((argv[i][j] == 'E' || argv[i][j] == 'T') &&
                  flag_diff_os == 1))
          flag_result = -1;
      } else if (strstr(argv[0], "s21_grep") != NULL && argv[i][0] == '-' &&
                 (argv[i][j] == 'e' || argv[i][j] == 'i' || argv[i][j] == 'v' ||
                  argv[i][j] == 'c' || argv[i][j] == 'l' || argv[i][j] == 'n' ||
                  argv[i][j] == 'h' || argv[i][j] == 's' ||
                  argv[i][j] == 'o')) {
        pars_res[number] = argv[i][j];
        number++;
      } else if (strstr(argv[0], "s21_grep") != NULL && argv[i][0] == '-' &&
                 argv[i][j] == 'f') {
        pars_res[number] = argv[i][j];
        number++;
        *fflag = i;
      }
      if (flag_result == -1)
        break;
    }
  }
  return flag_result;
}
