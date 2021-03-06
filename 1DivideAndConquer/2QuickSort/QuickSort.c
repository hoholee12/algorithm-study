#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//insertion sort
int MedianChooser(int* arr, int left, int middle, int right){
	
	int temparr[3] = { left, middle, right };
	for (int i = 1; i < 3; i++){
		int temp = temparr[i];
		int j = i - 1;
		for (; j >= 0; j--){
			int x = temparr[j];
			if (arr[temp] < arr[x]){
				temparr[j + 1] = temparr[j];
			}
			else{
				break;
			}
		}
		temparr[j + 1] = temp;
	}

	return temparr[1];
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

		while (arr[left_i] <= arr[pivot] && left_i <= right_i) left_i++;	//position left_i to next number bigger than pivot AND check interchange(end of the array)
		while (arr[right_i] >= arr[pivot] && left_i <= right_i) right_i--;	//position right_i to next number smaller than pivot AND check interchange
		
		//swap pivot and break just after left and right interchange
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

int test2(){
#define ARRSIZE 10000000
	int* arr = malloc(ARRSIZE * sizeof(int));
	srand(time(NULL));

	for (int i = 0; i < ARRSIZE; i++){
		arr[i] = rand()  *(RAND_MAX + 1) + rand();

	}

	//printf("before: ");
	//for (int i = 0; i < ARRSIZE; i++) printf("%d ", arr[i]);
	//printf("\n");

	time_t start = time(NULL);
	Divide(arr, 0, ARRSIZE - 1);
	time_t end = time(NULL);

	//printf("after: ");
	//for (int i = 0; i < ARRSIZE; i++) printf("%d ", arr[i]);

	printf("\ntook %d second(s).", end - start);

	free(arr);
	return 0;
}

int test1(){
	
	int arr[5] = { 5, 4, 3, 2, 1};
	srand(time(NULL));

	printf("before: ");
	for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
	printf("\n");

	time_t start = time(NULL);
	Divide(arr, 0, 4);
	time_t end = time(NULL);

	printf("after: ");
	for (int i = 0; i < 5; i++) printf("%d ", arr[i]);

	printf("\ntook %d second(s).", end - start);

	return 0;
}

int main(){
	test2();

	return 0;
}