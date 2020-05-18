#include <stdio.h>
#include <stdlib.h>

void swap(char *a, char *b)
{
	char c = *a;
	*a = *b;
    *b = c;
}

void swap_and_print(char *array, int start, int end)
{
	int i = start;
	if (start == end)
	{
		printf("%s\n", array);
		return;
	}

	while (i <= end) {
		swap(&array[start], &array[i]);
		swap_and_print(array, start + 1, end);
		swap(&array[start], &array[i]);
		i++;

	}
}

int main()
{
	char arr[4] = "cat";
	swap_and_print(&arr[0], 0, 2);
	return 0;
}
