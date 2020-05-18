/*
 ============================================================================
 Name        : linklist.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct linklist
{
	int data;
	struct linklist *next;
}ll;

ll* add_node(int data)
{
	ll* node = (ll *)malloc(sizeof(ll));
	node->data = data;
	node->next = NULL;

	return node;
}

ll* delete_node(ll *cur, int data)
{

	ll *prev = NULL, *next = NULL, *head = NULL;

	while (cur)
	{
		if (cur->data == data)
		{
			next = cur->next;
			if (prev)
				prev->next = next;
			free(cur);
			cur = next;
			continue;
		}
		prev = cur;
		cur = cur->next;
		if (!head)
			head = prev;
	}
	return head;
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

ll* reverse_list(ll* head)
{
	ll *next = NULL, *prev = NULL, *cur = head;

	while (cur)
	{
		next = cur->next; //next = 2 //next = 3 //next = 4 //next = NULL
		cur->next = prev; //cur->next = NULL: 1-> NULL //cur->next = 1 : 2->1 // cur->next = 2 : 3->2->1 // 4: 4->3->2->1
		prev = cur; //prev = 1 // prev = 2 // prev = 3 // prev = 4
		cur = next; //cur = 2 // cur = 3 // cur = 4 // cur = NULL
	}
	return prev;
}

int main(void) {
	printf("!!!Hello World!!!\n"); /* prints !!!Hello World!!! */
	ll *head = add_node(1);
	head->next = add_node(2);
	head->next->next = add_node(3);
	head->next->next->next = add_node(4);
	print_list(head);
	head = reverse_list(head);
	print_list(head);
	head = delete_node(head, 3);
	print_list(head);

	return EXIT_SUCCESS;
}
