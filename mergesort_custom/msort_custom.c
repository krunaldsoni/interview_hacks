/*
 * merge.c
 *
 *  Created on: Mar 14, 2020
 *      Author: krunal.soni
 */
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void print_arr(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d --", arr[i]);
	}
	printf("\n");
}
void merge(int *arr, int sidx, int midx, int eidx)
{
	int k = 0, i = 0, j = 0;
	int *l = (int *)malloc(sizeof(int) * ((midx - sidx) + 1));
	int *r = (int *) malloc(sizeof(int) * ((eidx - (midx + 1)) + 1));

	for (i = sidx; i <= midx; i++, k++)
		l[k] = arr[i];
	k = 0;
	for (j = midx + 1; j <= eidx; j++, k++)
		r[k] = arr[j];
	i = 0;
	j = 0;
    k = sidx;
	while (i <= (midx - sidx) && j <= (eidx - (midx + 1)))
	{
		if (l[i] > r[j])
		{
			arr[k] = r[j];
			j++;
		}
		else
		{
			arr[k] = l[i];
			i++;
		}
		k++;
	}
	while (i <= (midx - sidx))
	{
		arr[k] = l[i];
		k++;
		i++;
	}
	while (j <= (eidx - (midx + 1)))
	{
		arr[k] = r[j];
		k++;
		j++;
	}
	free(l);
	free(r);
}

void mergesort(int *arr, int sidx, int eidx)
{
	int middle;

	if ((sidx >= eidx) || (sidx < 0) || (eidx < 0))
		return;
	middle = sidx + ((eidx - sidx) / 2) ;
	mergesort(arr, sidx, middle);
	mergesort(arr, middle + 1, eidx);

	merge(arr, sidx, middle, eidx);
}
int main()
{
	int arr[10] = {5,2,3,1,4,8,7,10,9,6};

	print_arr(arr, 10);
	mergesort(arr, 0, 9);
	print_arr(arr, 10);

	return 0;
}


