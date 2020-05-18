#include <stdio.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void heapify(int *arr, int root_idx, int sz)
{
	int parent = root_idx, left = (2 * root_idx) + 1, right = (2 * root_idx) + 2, largest = root_idx;

	if (left < sz && arr[largest] < arr[left])
	{
		largest = left;
	}
	if (right < sz && arr[largest] < arr[right])
	{
		largest = right;
	}
	if (largest != parent)
	{
		swap(&arr[parent], &arr[largest]);
		heapify(arr, largest, sz);
	}
}
void heap_sort(int *arr, int sz)
{
	int max = sz - 1;
	for (int i = 0; i < sz; i++)
		heapify(arr, i, sz - i);

	while (sz)
	{
		heapify(arr, 0, sz--);
		swap(&arr[0], &arr[sz]);
	}
	printf("max node in tree: %d\n", arr[max]);
}

void print(int *arr, int sz)
{
	for(int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[10] = {-1,-995,6,8,-99,7,10,4,2,-3000};
	//int arr[4] = {1,5,2,3};
	print(arr, 10);
	heap_sort(arr, 10);
	print(arr, 10);
	return 0;
}
