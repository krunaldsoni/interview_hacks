#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int compare(const void *a, const void *b)
{
	int a1 = *(int*)a, b1 = *(int *)b;
	return (a1 > b1) ? 1 : ((a1 - b1) == 0 ? 0: -1);
}
void print_arr(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d --", arr[i]);
	}
	printf("\n");
}

int pivot(int *arr, int sidx, int eidx)
{
	int curr = sidx;
	for (int i = sidx; i <= eidx; i++)
	{
		if (arr[i] < arr[eidx])
		{
			swap(&arr[i], &arr[curr]);
			curr++;
		}
	}
	swap(&arr[curr], &arr[eidx]);

	return curr;
}

void partition(int *arr, int sidx, int eidx)
{
	int p;

	if (sidx > eidx || (sidx < 0) || (eidx < 0))
		return;

	p = pivot(arr, sidx, eidx);
	partition(arr, sidx, p - 1);
	partition(arr, p + 1, eidx);
}

void custom_qsort(int *arr, int size)
{
	partition(arr, 0, size - 1);
}

int main()
{
	int arr[10] = {5,2,3,1,4,8,7,10,9,6};

	print_arr(arr, sizeof(arr)/sizeof(arr[0]));
	//qsort(arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), compare);
	custom_qsort(arr, 10);
	print_arr(arr, sizeof(arr)/sizeof(arr[0]));

	return 0;

}
