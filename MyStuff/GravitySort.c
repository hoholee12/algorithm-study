#include<stdio.h>
#include<stdlib.h>

/*algorithm designed by hoholee12*/

void GravitySort(int* arr, int size){
	int max = arr[0]; int min = arr[0];
	for (int i = 1; i < size; i++){
		if (max < arr[i]) max = arr[i];
		if (min > arr[i]) min = arr[i];
	}


	int maxBackup = max;
	int minBackup = min;
	//solution for zero or negative values
	max -= minBackup - 1;
	min -= minBackup - 1;
	for (int i = 0; i < size; i++) arr[i] -= minBackup - 1;

	int* temparr = calloc(max - min + 1, sizeof(int));

	for (int j = max; j >= min; j--){
		for (int i = 0; i < size; i++){
			if (arr[i] >= j) temparr[j - min] += 1;
		}
		

	}

	for (int i = size; i > 0; i--){
		arr[size - i] = 0;
		for (int j = min; j <= max; j++){
			if (i <= temparr[j - min]) arr[size - i] += 1;
		}
	}
	
	//solution for zero or negative values
	for (int i = 0; i < size; i++) arr[i] += minBackup - 1;

	free(temparr);
	
}

int main(){
	int arr[10] = { 50, 2, 13, 33, 62, 11,  30, 66, 0, -101 };

	GravitySort(arr, 10);

	for (int i = 0; i < 10; i++) printf("%d ", arr[i]);

	return 0;
}