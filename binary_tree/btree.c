/*
 * btree.c
 *
 *  Created on: Feb 6, 2020
 *      Author: krunal.soni
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define MAX(a, b) (a > b ? a : b)


typedef struct btree
{
	int data;
	struct btree *left;
	struct btree *right;
} tree_t;

void swap(tree_t** left, tree_t** right)
{
	tree_t* tmp = *right;
	*right = *left;
	*left = tmp;
}

tree_t* tree_delete_node(tree_t* root, int data)
{
	tree_t *tmp;
	if (!root)
		return NULL;

	if (root->data == data)
	{
		if (!root->left && !root->right)
		{
			free(root);
			return NULL;
		} else if (!root->left) {
			tmp = root->right;
			free(root);
			return tmp;
		} else if (!root->right) {
			tmp = root->left;
			free(root);
			return tmp;
		} else {
			tree_t *new_root = root->right;
			tmp = root->left;
			while (new_root->left) {
				new_root = new_root->left;
			}
			new_root->left = tmp;
			return new_root;
		}
	} else if (root->data > data) {
		root ->left = tree_delete_node(root->left, data);
	} else {
		root ->right = tree_delete_node(root->right, data);
	}
	return root;
}
tree_t* tree_add_node(tree_t* root, int data)
{
	if (!root)
	{
		root = (tree_t *)malloc(sizeof(tree_t));
		root->data = data;
		root->left = root->right = NULL;
		return root;
	}
	if (root->data < data)
	{
		root->right = tree_add_node(root->right, data);
	}
	else
	{
		root->left = tree_add_node(root->left, data);
	}
	return root;
}

void tree_display(tree_t * root)
{
	if (!root)
		return;
	tree_display(root->left);
	printf("%d->", root->data);
	tree_display(root->right);
}

int depth(tree_t* root)
{
	if (!root)
		return 0;
	return MAX(1 + depth(root->left), 1 + depth(root->right));
}

tree_t* mirror_tree(tree_t* root)
{
	if (!root)
		return NULL;
	swap(&root->left, &root->right);
	mirror_tree(root->left);
	mirror_tree(root->right);

	return root;
}

int main(void)
{
	tree_t *root = NULL;
	int i;

	root = tree_add_node(root, 5);
	for (i = 1; i < 6; i++)
	{
		root = tree_add_node(root, 5 + i);
		root = tree_add_node(root, 5 - i);
	}
	root = tree_add_node(root,  20);
	root = tree_add_node(root,  30);

	tree_display(root);
	root = tree_delete_node(root, 0);
	printf("after deleting node 0\n");
	tree_display(root);
	printf("\n");
	root = mirror_tree(root);
	tree_display(root);
	printf("\n");
	if (root)
		printf("tree length:%d", depth(root) - 1);
	return 0;
}
