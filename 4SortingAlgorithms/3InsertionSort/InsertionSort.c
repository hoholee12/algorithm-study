#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void InsertionSort(int* arr, int size){
	for (int i = 1; i < size; i++){
		int temp = arr[i];
		int j = i - 1;
		for (; j >= 0; j--){
			if (temp < arr[j]){
				arr[j + 1] = arr[j];
			}
			else break;
		}
		arr[j + 1] = temp;
	}


}

int main(){
#define ARRSIZE 100000
	int* arr = malloc(ARRSIZE * sizeof(int));

	srand(time(NULL));
	for (int i = 0; i < ARRSIZE; i++) arr[i] = rand() % ARRSIZE;

	//printf("before: ");
	//for (int i = 0; i < ARRSIZE; i++) printf("%d ", arr[i]);
	//printf("\n");

	time_t start = time(NULL);
	InsertionSort(arr, ARRSIZE);
	time_t end = time(NULL);

	//printf("after: ");
	for (int i = 0; i < ARRSIZE; i++) printf("%d ", arr[i]);

	printf("\ntook %d second(s).", end - start);

	free(arr);
	return 0;
}