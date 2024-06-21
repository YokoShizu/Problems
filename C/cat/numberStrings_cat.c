#include <stdio.h>
#include <string.h>

void numberStrings_cat(char *pars_res, int *num_all_ptr, int *num_non_empty_ptr,
                       char previous, int *current) {
  if (strstr(pars_res, "n") != NULL) {
    if (*num_all_ptr == 1 && previous == '\0')
      printf("%6d\t", (*num_all_ptr)++);
    else if (previous == '\n')
      printf("%6d\t", (*num_all_ptr)++);
  } else if (strstr(pars_res, "b") != NULL &&
             ((previous == '\n' && *current != '\n') ||
              (previous == '\0' && *current != '\n' &&
               *num_non_empty_ptr == 1)))
    printf("%6d\t", (*num_non_empty_ptr)++);
}
