#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define filename "macdata.txt"

#if 1
typedef struct obj {
	uint8_t mac_addr[6];
	uint32_t data;
} obj;
#endif

static FILE* read_line(FILE *fp, char *buf, int buf_len, int *end)
{
    int i;

	if (!fp)
		return NULL;

	for (i = 0; i < buf_len; i++)
	{
		char c = fgetc(fp);
		if (c == '\n')
			break;

		if (c == EOF)
		{
			*end = 1;
			break;
		}
		buf[i] = c;
	}
	buf[i] = '\0';

	return fp;
}

static void read_file_and_fill_array(char *file, obj *arr, int arr_size)
{
	FILE *fp = fopen(file, "rw");
	char buf[50] = {0};
	int end = 0, count =0;

	if (!fp)
		return;

	fp = read_line(fp, buf, 0, &end);

	while (fp && !end)
	{
		if (count == arr_size)
			break;
		fp = read_line(fp, buf, 50, &end);
		char *str = strtok(buf, " ");
		int bytes[6] = {0};
		sscanf(str, "%x:%x:%x:%x:%x:%x*c",
			   &bytes[0], &bytes[1],&bytes[2], &bytes[3],&bytes[4], &bytes[5]);
		for (int i = 0; i < 6; i++)
			 arr[count].mac_addr[i] = (uint8_t)bytes[i];
		str = strtok(NULL, " ");
		arr[count].data = atoi(str);
		count++;
		printf("%s\n", buf);
	}
	fclose(fp);
}

int main()
{
	obj arr[50] = {0};
	read_file_and_fill_array(filename, arr, 50);
	for (int i = 0; i < 50; i++)
	{
		printf("mac:%x:%x:%x:%x:%x:%x byte:%d\n",
				arr[i].mac_addr[0], arr[i].mac_addr[1], arr[i].mac_addr[2],
				arr[i].mac_addr[3], arr[i].mac_addr[4], arr[i].mac_addr[5],
				arr[i].data);
	}
	return 0;
}
