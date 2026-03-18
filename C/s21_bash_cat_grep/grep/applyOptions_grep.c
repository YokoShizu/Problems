#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "compareRegex_grep.h"
#include "core_grep.h"
#include "printCL_grep.h"
#include "searchTemplate_grep.h"

void applyOptions_grep(char *pars_res, int fflag, FILE *f, int argc,
                       char **argv, int i, int l, int min) {
  int trulse = 1, flag_no_name = 0, ignor_reg = 0, quantity = 0;

  if (strstr(pars_res, "i") != NULL) ignor_reg = 1;
  if (strstr(pars_res, "h") != NULL) flag_no_name = 1;
  if (strstr(pars_res, "v") != NULL) trulse = 0;

  fseek(f, 0L, SEEK_END);
  long size = ftell(f);
  rewind(f);

  char *string = calloc((size_t)size + 2, sizeof(char));
  if (!string) {
    fclose(f);
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }
  if (strstr(pars_res, "f") == NULL) {
    for (int j = 1 + l; j < min; j += 2) {
      rewind(f);
      int string_num = 0;
      while (fgets(string, (int)size + 1, f) != NULL) {
        string_num++;
        searchTemplate_grep(pars_res, string, argv[j], f, argc, argv, i, j,
                            string_num, trulse, ignor_reg, flag_no_name, l,
                            min);
      }
    }
  } else {
    FILE *ff = fopen(argv[fflag + 1], "r");
    if (!ff) {
      free(string);
      fprintf(stderr, "Cannot open file %s\n", argv[fflag + 1]);
      return;
    }
    fseek(ff, 0L, SEEK_END);
    long sizeff = ftell(ff);
    rewind(ff);

    char *templ = calloc((size_t)sizeff + 2, sizeof(char));
    if (!templ) {
      fclose(ff);
      free(string);
      fprintf(stderr, "Memory allocation failed\n");
      exit(1);
    }
    int string_num;
    rewind(f);
    while (fgets(string, (int)size + 1, f) != NULL) {
      string_num = 0;
      rewind(ff);
      int templ_num = 0;
      while (fgets(templ, (int)sizeff + 1, ff) != NULL) {
        templ_num++;
        searchTemplate_grep(pars_res, string, templ, f, argc, argv, i,
                            1 + l + (templ_num - 1), string_num, trulse,
                            ignor_reg, flag_no_name, l, min);
        if (compareRegex_grep(string, templ, ignor_reg) == 0) break;
      }
    }
    free(templ);
    fclose(ff);
  }
  free(string);
  printCL_grep(pars_res, argv[i], argc, min, quantity, i, flag_no_name);
}