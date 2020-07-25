#pragma once
#include<stdlib.h>

//	Time complexity: O(N) = merge using temporary array
void MergeConquer(int* arr, int left, int dropped_middle, int right){
	int dropped_size = right - left;
	int size = dropped_size + 1;
	int middle = dropped_middle + 1;	//we can't have arr[left_i] == arr[right_i]

	//temporary array for merge
	int* temparr = (int*)malloc(sizeof(int)* size);

	//conquer
	int left_i = left;
	int right_i = middle;	//we can't have arr[left_i] == arr[right_i]

	int i = 0;
	for (; left_i < middle && right_i < right + 1; i++){	//we need to count upto 'right'

		if (arr[left_i] < arr[right_i]){
			temparr[i] = arr[left_i];
			left_i++;
		}
		else{
			temparr[i] = arr[right_i];
			right_i++;
		}
	}

	//leftover(only one will happen)
	for (; left_i < middle; i++, left_i++) temparr[i] = arr[left_i];
	for (; right_i < right + 1; i++, right_i++) temparr[i] = arr[right_i];	//we need to count upto 'right'

	//copy back
	for (int i = 0; i < size; i++) arr[left + i] = temparr[i];

	free(temparr);
}

//	Time complexity: O(logN) = binary recursion
void MergeDivide(int* arr, int left, int right){
	int dropped_size = right - left;
	int size = dropped_size + 1;
	int dropped_middle = dropped_size / 2 + left;

	if (left < right){
		//divide(recursion)
		MergeDivide(arr, left, dropped_middle);	//we can't have infinite (0, 1) recursion
		MergeDivide(arr, dropped_middle + 1, right);

		MergeConquer(arr, left, dropped_middle, right);
	}
}