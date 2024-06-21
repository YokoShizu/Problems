#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void searchRepeats(char *pars_res, char **argv) {
  for (size_t i = strlen(pars_res) - 1; i > 0; i--) {
    for (size_t j = 0; j < i; j++) {
      if (pars_res[i] == pars_res[j] &&
          !(strstr(argv[0], "s21_grep") != NULL && pars_res[i] != 'e'))
        memmove(&pars_res[j], &pars_res[j + 1], strlen(pars_res) + j);
    }
  }
}

void searchBN(char *pars_res) {
  for (int i = (int)strlen(pars_res) - 1; i > -1; i--) {
    for (int j = 0; j < (int)strlen(pars_res); j++) {
      if (pars_res[i] == 'b' && pars_res[j] == 'n')
        memmove(&pars_res[j], &pars_res[j + 1], strlen(pars_res) + j);
    }
  }
}

void searchEV(char *pars_res) {
  for (int i = (int)strlen(pars_res) - 1; i > -1; i--) {
    for (size_t j = 0; j < strlen(pars_res); j++) {
      if (pars_res[i] == 'e' && pars_res[j] == 'v')
        memmove(&pars_res[j], &pars_res[j + 1], strlen(pars_res) + j);
    }
  }
}

void searchTV(char *pars_res) {
  for (int i = (int)strlen(pars_res) - 1; i > -1; i--) {
    for (size_t j = 0; j < strlen(pars_res); j++) {
      if (pars_res[i] == 't' && pars_res[j] == 'v')
        memmove(&pars_res[j], &pars_res[j + 1], strlen(pars_res) + j);
    }
  }
}

int searchE(int argc, char **argv) {
  int num_e = 0;
  for (int i = 1; i < argc - 1; i++) {
    if (argv[i][0] == '-' && argv[i][1] != '-' && strstr(argv[i], "e") != NULL)
      num_e++;
  }
  return num_e;
}

int searchF(int argc, char **argv) {
  int num_f = 0;
  for (int i = 1; i < argc - 1; i++) {
    if (argv[i][0] == '-' && argv[i][1] != '-' && strstr(argv[i], "f") != NULL)
      num_f++;
  }
  return num_f;
}
