#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*algorithm designed by hoholee12*/

typedef struct{
	int val;
	int dup;
} duplicates;

int ScoopSort(int* arr, int size, int buf){

	//subarr buffer size
	buf += size;

	int* bigarr = malloc(size * sizeof(int));
	duplicates* subarr = malloc(buf * sizeof(duplicates));	//x2 yield for element shift
	//subarr init: O(N)
	for (int i = 0; i < buf; i++) {
		subarr[i].val = INT_MIN;
		subarr[i].dup = 0;
	}

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

		//follow index: incr dup
		for (int i = 0; i < size; i++){
			int val = arr[i] - min;
			if (val < buf && val >= 0){
				subarr[val].val = arr[i];
				subarr[val].dup++;
			}
		}

		//scoop subarr to bigarr: O(N)
		for (int i = 0; i < buf; i++){
			if (subarr[i].val > initval){
				for (int x = 0; x < subarr[i].dup; x++) bigarr[j++] = subarr[i].val;
				subarr[i].dup = 0;
				if (lastsize < subarr[i].val) lastsize = subarr[i].val;
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

int test2(){
#define ARRSIZE 1000000
	int* arr = malloc(ARRSIZE * sizeof(int));
	srand(time(NULL));

	for (int i = 0; i < ARRSIZE; i++){
		arr[i] = rand() % ARRSIZE;
	
	}

	//printf("before: ");
	//for (int i = 0; i < ARRSIZE; i++) printf("%d ", arr[i]);
	//printf("\n");

	time_t start = time(NULL);
	int result = ScoopSort(arr, ARRSIZE, 0);
	time_t end = time(NULL);

	//printf("after: ");
	for (int i = 0; i < ARRSIZE; i++) printf("%d ", arr[i]);

	printf("\nlooped %d time(s).\ntook %d second(s).", result, end - start);

	free(arr);
	return 0;
}

int test1(){
	//3 0 3 2 6 3 1 4 1 7
	int arr[10] = { 8, 3, 4, 9, 4, 3, 9, 5, 4, 0 };
	srand(time(NULL));

	printf("before: ");
	for (int i = 0; i < 10; i++) printf("%d ", arr[i]);
	printf("\n");

	time_t start = time(NULL);
	int result = ScoopSort(arr, 10, 0);
	time_t end = time(NULL);

	printf("after: ");
	for (int i = 0; i < 10; i++) printf("%d ", arr[i]);

	printf("\nlooped %d time(s).\ntook %d second(s).", result, end - start);

	return 0;
}

int main(){
	test2();

	return 0;
}