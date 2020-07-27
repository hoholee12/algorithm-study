#include<stdio.h>
#include<stdlib.h>

void IDontKnowWhatThisIs(int* arr, int size){
	int* minuscount = (int*)malloc(size * sizeof(int));	//new location chooser array
	int* valarr = (int*)malloc(size * sizeof(int));	//value backup array

	//compare all elements: size^2
	for (int i = 0; i < size; i++){
		valarr[i] = arr[i];
		minuscount[i] = 0;
		for (int j = 0; j < size; j++){
			if (i != j){
				//the one with the least amount(0) is the smallest value
				if (arr[i] - arr[j] > 0){
					minuscount[i] += 1;
				}
			}
		}
	}

	//O(size)
	for (int i = 0; i < size; i++){
		//place everything back in
		arr[minuscount[i]] = valarr[i];
	}

	//total time complexity: O(size^2)
}


int main(){
	int arr[10] = { 50, 2, 13, 33, 62, 11, 30, 66, 1, -101 };

	IDontKnowWhatThisIs(arr, 10);

	for (int i = 0; i < 10; i++) printf("%d ", arr[i]);

	return 0;
}