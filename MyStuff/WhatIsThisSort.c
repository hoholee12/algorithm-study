#include<stdio.h>
#include<stdlib.h>

void WhatIsThisSort(int* arr, int size){
	//O(N)
	int min = arr[0];
	int max = arr[0];
	for (int i = 1; i < size; i++){
		if (min > arr[i]) min = arr[i];
		if (max < arr[i]) max = arr[i];
	}

	//O(N)
	int bigsize = max - min + 1;
	int initval = min - 1;
	int* bigarr = malloc(bigsize * sizeof(int));
	for (int i = 0; i < bigsize; i++){
		bigarr[i] = initval;
	}

	//O(N)
	for (int i = 0; i < size; i++){
		//shift duplicate ones
		int j = 0;
		for (; bigarr[arr[i] - min + j] != initval; j++);
		bigarr[arr[i] - min + j] = arr[i];
	}

	//O(N)
	for (int i = 0, j = 0; i < bigsize; i++){
		if (bigarr[i] != initval) arr[j++] = bigarr[i];
	}

	free(bigarr);

	//total time complexity: O(N)
}

int main(){
	int arr[8] = { 50, 2, 13, 33, 33, -10, 999, 368 };

	WhatIsThisSort(arr, 8);

	for (int i = 0; i < 8; i++) printf("%d ", arr[i]);

	return 0;
}