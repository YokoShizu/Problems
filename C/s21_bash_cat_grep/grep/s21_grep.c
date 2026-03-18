#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/parser.h"
#include "../common/quantity.h"
#include "../common/searchRepeats.h"
#include "../common/strlensum.h"
#include "applyOptions_grep.h"

int main(int argc, char **argv) {
  int fflag = 0, pars_flag = 0;
  int flags_q = flags_quantity(argc, argv);
  int templs_q = templs_quantity(argc, argv, flags_q);
  int minmin = templs_q + flags_q + 1;

  char *pars_res = calloc((size_t)strlensum(argc, argv) + 1, sizeof(char));
  if (!pars_res) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }

  if (flags_q != 0)
    pars_flag = parser(flags_q, &fflag, templs_q, pars_res, argc, argv);

  int l = min((int)strlen(pars_res), flags_q);

  if (searchE(argc, argv) == 0) {
    char *tmp = realloc(pars_res, (size_t)strlensum(argc, argv) + 2);
    if (!tmp) {
      free(pars_res);
      fprintf(stderr, "Memory allocation failed\n");
      exit(1);
    }
    pars_res = tmp;
    strcat(pars_res, "e");
  }

  if (argc - minmin == 1) {
    char *tmp = realloc(pars_res, (size_t)strlensum(argc, argv) + 3);
    if (!tmp) {
      free(pars_res);
      fprintf(stderr, "Memory allocation failed\n");
      exit(1);
    }
    pars_res = tmp;
    strcat(pars_res, "h");
  }

  pars_res[strlen(pars_res)] = '\0';

  for (int i = minmin; i < argc; i++) {
    if (pars_res != NULL && argc > 2) {
      FILE *f = fopen(argv[i], "r");
      if (f != NULL)
        applyOptions_grep(pars_res, fflag, f, argc, argv, i, l, minmin);
      else if (strstr(pars_res, "s") == NULL)
        printf("grep: %s: No such file or directory\n", argv[i]);
      if (f) fclose(f);
    } else {
      if (pars_flag == -1 && strstr(pars_res, "s") == NULL)
        printf("grep: illegal option. Please, enter only appropriate flags.");
      else if (pars_res && strstr(pars_res, "s") == NULL)
        printf("ERROR! Allocation memory for the flags sequence is failed.");
      else if (strstr(pars_res, "s") == NULL)
        printf("grep: illegal option. Please, enter the name of the file.");
      break;
    }
  }

  free(pars_res);
  return 0;
}