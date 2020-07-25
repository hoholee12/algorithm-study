#include<stdio.h>
#include<stdlib.h>
#include"nonimportant.h"

//lol merge sort
int MedianChooser(int* arr, int left, int middle, int right){
	int temparr[3] = { arr[left], arr[middle], arr[right] };
	MergeDivide(temparr, 0, 2);
	if (temparr[1] == arr[left]) return left;
	else if (temparr[1] == arr[middle]) return middle;
	else return right;
}

void swap(int* x, int* y){ int temp = *x; *x = *y; *y = temp; }

//pivot generator and sorter
int Conquer(int* arr, int left, int right){
	int dropped_size = right - left;
	int size = dropped_size + 1;
	int middle = size / 2 + left;

	int left_i = left, right_i = right;

	//choose median for pivot: left, middle, right
	int pivot = MedianChooser(arr, left, middle, right);

	//swap pivot with left
	swap(&arr[pivot], &arr[left]);
	pivot = left_i;
	left_i += 1;

	//swap numbers bigger than pivot to the right, smaller to the left
	while(left_i < right + 1 && right_i > left){	//we need to count upto 'right'

		while (arr[left_i] < arr[pivot]) left_i++;	//position left_i to next number bigger than pivot
		while (arr[right_i] > arr[pivot]) right_i--;	//position right_i to next number smaller than pivot
		
		//swap pivot and break just after left and right interweave
		if (left_i > right_i){
			swap(&arr[pivot], &arr[right_i]);
			pivot = right_i;
			break;
		}
		//else swap left and right
		else swap(&arr[left_i], &arr[right_i]);
	}
	
	return pivot;

}

void Divide(int* arr, int left, int right){

	if (left < right){
		int pivot = Conquer(arr, left, right);
	
		Divide(arr, left, pivot - 1);
		//leave out arr[pivot] itself
		Divide(arr, pivot + 1, right);
	
	}

	
}

int main(){ 

	int arr[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	Divide(arr, 0, 9);

	//print
	for (int i = 0; i < 10; i++) printf("%d ", arr[i]);

	return 0;
}