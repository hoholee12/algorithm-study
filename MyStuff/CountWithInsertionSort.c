#include<stdio.h>
#include<stdlib.h>

void CountWithInsertionSort(int* arr, int size){
	//O(N)
	int min = arr[0];
	int max = arr[0];
	for (int i = 1; i < size; i++){
		if (min > arr[i]) min = arr[i];
		if (max < arr[i]) max = arr[i];
	}

	//O(N)
	int initval = min - 1;
	int* bigarr = malloc(size * sizeof(int));
	for (int i = 0; i < size; i++){
		bigarr[i] = initval;
	}

	//O(N)
	for (int i = 0; i < size; i++){
		
		if (arr[i] - min >= size){

			//insertion sort O(N^2)
			int temp = 0;
			for (int j = size - 1; j >= 0; j--){
				if (bigarr[j] < arr[i]){
					//reverse
					int x = j;
					for (; bigarr[x] != initval; x--);
					for (; x < j; x++){
						bigarr[x] = bigarr[x + 1];
					}
					temp = x;
					break;
				}
			}
			//place
			bigarr[temp] = arr[i];
		
		}
		else{

			//shift duplicate ones
			int j = 0;
			for (; bigarr[arr[i] - min + j] != initval; j++);
			bigarr[arr[i] - min + j] = arr[i];
		}
	}

	//O(N)
	for (int i = 0, j = 0; i < size; i++){
		if (bigarr[i] != initval) arr[j++] = bigarr[i];
	}

	free(bigarr);

	//total time complexity: O(N)
}

int main(){
	int arr[5] = { -101, 100, 3, 7, 6 };

	CountWithInsertionSort(arr, 5);

	for (int i = 0; i < 5; i++) printf("%d ", arr[i]);

	return 0;
}