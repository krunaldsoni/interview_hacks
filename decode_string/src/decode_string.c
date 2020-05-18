/*
 ============================================================================
 Name        : decode_string.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void decode_string(char* string)
{
	int len = strlen(string), total = 0;
	/*
	 * 166
	 * 162634
	 * 1023
	 * 11233
	 */
	for (int i = 0; i < len; i++)
	{
		if (i + 1 < len) {
			if (string[i + 1] == '0') {
				i++;
			} else if ((string[i] <= '2' && string[i] >= '1') && string[i + 1] <= '6') {
				total++;
			}
		}
	}
	printf("total:%d\n", (1 << --total) + 1);
}
int main(void) {
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	decode_string("166"); // 1 6 6, 16 6
	decode_string("226"); //2 2 6, 22 6 , 2 26
	decode_string("16623"); // 10 2 3, 1 2 3, 1 23, 10 23
	return EXIT_SUCCESS;
}
