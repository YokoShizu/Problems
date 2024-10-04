#include <stdio.h>
#include <string.h>

void printCL_grep(char *pars_res, char *file_name, int argc, int min,
                  int quantity, int i, int flag_no_name) {
  if (strstr(pars_res, "c") != NULL && strstr(pars_res, "l") == NULL) {
    if (argc - min > 1 && flag_no_name == 0)
      printf("%s:", file_name);
    printf("%d", quantity);
    if (i < argc)
      printf("\n");
  } else if (strstr(pars_res, "c") == NULL && strstr(pars_res, "l") != NULL &&
             quantity > 0) {
    printf("%s", file_name);
    if (i < argc)
      printf("\n");
  } else if (strstr(pars_res, "c") != NULL && strstr(pars_res, "l") != NULL) {
    if (argc - min > 1 && flag_no_name == 0 && quantity > 0)
      printf("%d\n%s", 1, file_name);
    else if (quantity == 0 && argc - min > 1)
      printf("%s:%d", file_name, (int)(quantity < 0));
    else {
      printf("%s:%d\n", file_name, (int)(quantity > 0));
      printf("%s", file_name);
    }
    if (i < argc)
      printf("\n");
  }
}
