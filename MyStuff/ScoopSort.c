#include<stdio.h>
#include<stdlib.h>

/*algorithm designed by hoholee12*/

int ScoopSort(int* arr, int size, int buf){

	//subarr buffer size
	buf += size;

	int* bigarr = malloc(size * sizeof(int));
	int* subarr = malloc(buf * sizeof(int));
	//subarr init: O(N)
	for (int i = 0; i < size; i++) subarr[i] = INT_MIN;

	//will always have biggest number of section
	int lastsize = INT_MIN;

	//big loop(until all elements are scooped: O(count of 'diff bigger than size'))
	int j = 0;
	int loopcount = 0;
	while (1){

		//min check per iteration: O(N)
		int min = INT_MAX;
		for (int i = 0; i < size; i++){
			if (min > arr[i] && arr[i] > lastsize) min = arr[i];
		}

		//initval per iteration
		int initval = min - 1;

		//follow index: O(N)
		for (int i = 0; i < size; i++){
			int val = arr[i] - min;
			if (val < buf && val >= 0){
				int x = 0; for (; subarr[val + x] > initval; x++);
				subarr[val + x] = arr[i];
			}
		}

		//scoop subarr to bigarr: O(N)
		for (int i = 0; i < buf; i++){
			if (subarr[i] > initval){
				bigarr[j++] = subarr[i];
				if (lastsize < subarr[i]) lastsize = subarr[i];
			}
		}

		loopcount++;

		//break on all scooped
		if (j >= size) break;
	}

	//copy back: O(N)
	for (int i = 0; i < size; i++) arr[i] = bigarr[i];


	free(subarr);
	free(bigarr);

	return loopcount;

}

int main(){
	int arr[5] = { 1000, 123, 345, 123, 7 };

	int result = ScoopSort(arr, 5, 1000);

	for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
	printf("\nlooped %d time(s).\n", result);

	return 0;
}