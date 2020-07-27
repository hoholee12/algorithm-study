#include<stdio.h>
#include<stdlib.h>

void ScoopSort(int* arr, int size){

	int* bigarr = malloc(size * sizeof(int));
	int* subarr = malloc(size * sizeof(int));
	//subarr init: O(N)
	for (int i = 0; i < size; i++) subarr[i] = INT_MIN;

	//will always have biggest number of section
	int lastsize = INT_MIN;

	//big loop(until all elements are scooped: O(count of 'diff bigger than size'))
	int j = 0;
	while (1){

		//min check per section: O(N)
		int min = INT_MAX;
		for (int i = 0; i < size; i++){
			if (min > arr[i] && arr[i] > lastsize) min = arr[i];
		}

		//initval per section
		int initval = min - 1;

		//follow index: O(N)
		for (int i = 0; i < size; i++){
			int val = arr[i] - min;
			if (val < size && val >= 0){
				int x = 0; for (; subarr[val + x] > initval; x++);
				subarr[val + x] = arr[i];
			}
		}

		//scoop subarr to bigarr: O(N)
		for (int i = 0; i < size; i++){
			if (subarr[i] > initval){
				bigarr[j++] = subarr[i];
				if (lastsize < subarr[i]) lastsize = subarr[i];
			}
		}
		if (j >= size) break;

	}

	//copy back: O(N)
	for (int i = 0; i < size; i++) arr[i] = bigarr[i];


	free(subarr);
	free(bigarr);

}

int main(){
	int arr[5] = { 0, -101, -200, -200, 6 };

	ScoopSort(arr, 5);

	for (int i = 0; i < 5; i++) printf("%d ", arr[i]);

	return 0;
}