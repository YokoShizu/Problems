#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "compareRegex_grep.h"
#include "core_grep.h"
#include "printCL_grep.h"

void applyOptions_grep(char *pars_res, int fflag, FILE *f, int argc,
                       char **argv, int i, int l, int min) {
  int trulse = 1, flag_no_name = 0, string_num = 0, ignor_reg = 0, quantity = 0;
  fseek(f, 0L, SEEK_END);
  long size = ftell(f);
  rewind(f);
  char *string = calloc(size + 1, sizeof(char));
  if (strstr(pars_res, "f") == NULL) {
    while (fgets(string, size, f), string_num++, !feof(f)) {
      for (int j = 1 + l; j < min; j += 2) {
        core_grep(pars_res, string, argv[j], argc, argv, f, i, j, string_num,
                  &trulse, &quantity, &ignor_reg, &flag_no_name, l, min);
      }
    }
    if (fgets(string, size, f) == NULL && strstr(string, "\n") == NULL) {
      string_num++;
      for (int n = 1 + l; n < min; n += 2) {
        core_grep(pars_res, string, argv[n], argc, argv, f, i, n, string_num,
                  &trulse, &quantity, &ignor_reg, &flag_no_name, l, min);
      }
    }
  } else {
    FILE *ff = fopen(argv[fflag + 1], "r");
    fseek(ff, 0L, SEEK_END);
    long sizeff = ftell(ff);
    char *templ = calloc(sizeff + 1, sizeof(char));
    while (rewind(ff), fgets(string, size, f), string_num++, !feof(f)) {
      while (fgets(templ, sizeff, ff), !feof(ff)) {
        core_grep(pars_res, string, templ, argc, argv, f, i, 0, string_num,
                  &trulse, &quantity, &ignor_reg, &flag_no_name, l, min);
        if (compareRegex_grep(string, templ, ignor_reg) == 0)
          break;
      }
    }
    if (fgets(string, size, f) == NULL && strstr(string, "\n") == NULL) {
      rewind(ff);
      string_num++;
      while (fgets(templ, sizeff, ff), !feof(ff)) {
        core_grep(pars_res, string, templ, argc, argv, f, i, 0, string_num,
                  &trulse, &quantity, &ignor_reg, &flag_no_name, l, min);
        if (compareRegex_grep(string, templ, ignor_reg) == 0)
          break;
      }
    }
    free(templ);
    fclose(ff);
  }
  printCL_grep(pars_res, argv[i], argc, min, quantity, i, flag_no_name);
  free(string);
}
