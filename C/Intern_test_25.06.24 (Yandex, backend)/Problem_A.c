//Недоделанная задача по форматированию текста для стажировки на бэкенд в Яндекс

#include <stdio.h>
#include <string.h>

#define MAX 100000

int main() {
	char str[MAX];
	char copy_str[MAX];
	fgets(str, MAX, stdin);
	str[strcspn(str, "\n")] = '\0';
	strcpy(copy_str, str);
	str[strlen(str)] = '\0';
	size_t max_length = 1;
	char* temp_word = strtok(copy_str, " ,");
	while (temp_word != NULL) {
		size_t length = strlen(temp_word);
		if (length > max_length) max_length = length;
		temp_word = strtok(NULL, " ,");
	}
	size_t len = max_length * 3;
	size_t i = 0;
	while (i < strlen(str)) {
		if (str[i] == ' ') {
			i++;
		}
		size_t j = 0, position_comma = 0, position_space = 0, position = 0, add_spaces = 0;
		while (str[i + j] != '\0') {
			if (str[i + j] == ',') {
				if (j + add_spaces < len) position_comma = j + add_spaces;
				else break;
			}
            j++;
        }
		j = 0;
		while (str[i + j] != '\0') {
			if (str[i + j] == ' ') {
				if (j + add_spaces < len + 1) position_space = j - 1 + add_spaces;
				else break;
			}
            j++;
        }
		j = 0;
		position = (position_comma > position_space) ? position_comma : position_space;
		position = (position == 0) ? len - 1: position;
		position = (strlen(str) - i - 1< len) ? strlen(str) - i - 1: position;
		size_t k = 0;
		while (k + add_spaces <= position && str[i + k] != '\0') {
			if(str[i + k - 1] == ',' && str[i + k] != ' ' && (i + k - 1 > 0) && (k + add_spaces + 1 < len)) {
					putchar(' ');
					putchar('1');
					putchar(str[i + k]);
					add_spaces++;
			}
			else if (str[i + k] == ' ' && str[i + k + 1] == ',') {
				putchar(str[i + 1 + k++]);
				add_spaces--;
			}
			else if ((i + k == strlen(str) - 1) && (str[i + k] == ' ')) break;
			else {
				putchar(str[i + k]);
			}
			k++;
		}
		i += position - add_spaces + 1;
		add_spaces = 0;
		k = 0;
		position = 0;
		if (i < strlen(str)) putchar('\n');
	}
	return 0;
}
