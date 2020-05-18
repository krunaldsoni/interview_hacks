/*
 ============================================================================
 Name        : find_duplicate.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define ABSX(x) (x < 0 ? -x : x)

typedef struct ll {
	int data;
	struct ll *next;
}ll;

ll* add_node(int data)
{
	ll* node = (ll *)malloc(sizeof(ll));
	node->data = data;
	node->next = NULL;

	return node;
}

void print_list(ll* head)
{
	while(head)
	{
		printf("[%d]->", head->data);
		head = head->next;
	}
	printf("\n");
}

void find_duplicate(int *in, int len, ll **out)
{
	ll *output = NULL;
	//{1,2,2,3,3,4}
	for(int i = 0; i < len; i++)
	{
		if (in[ABSX(in[i]) - 1] < 0)
		{
			if (!output) {
				output = add_node(ABSX(in[i]));
				*out = output;
			}
			else
			{
				output->next = add_node(ABSX(in[i]));
				output = output->next;
			}
		}
		else
		{
			in[ABSX(in[i]) - 1] *= -1;
		}
	}
}

int main(void) {
	//puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	ll *head = NULL;
	int a[] = {1, 2, 3, 1, 3, 6, 6, 7, 8, 8, 9, 9};
	find_duplicate(a, sizeof(a)/sizeof(a[0]), &head);
	print_list(head);
	return EXIT_SUCCESS;
}
