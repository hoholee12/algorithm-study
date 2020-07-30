#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef enum {xside, yside} side;

typedef struct{
	int x;
	int y;
} vector;

typedef struct{
	vector a;
	vector b;
} pair;

int decideSide(vector* a, side myside){ return (myside == xside) ? a->x : a->y; }

//insertion sort
int MedianChooser(vector* arr, int left, int middle, int right, side myside){

	int temparr[3] = { left, middle, right };
	for (int i = 1; i < 3; i++){
		int temp = temparr[i];
		int j = i - 1;
		for (; j >= 0; j--){
			int x = temparr[j];
			if (decideSide(&arr[temp], myside) < decideSide(&arr[x], myside)){
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

void swap(vector* x, vector* y){ vector temp = *x; *x = *y; *y = temp; }

//pivot generator and sorter
int Conquer(vector* arr, int left, int right, side myside){
	int dropped_size = right - left;
	int size = dropped_size + 1;
	int middle = size / 2 + left;

	int left_i = left, right_i = right;

	//choose median for pivot: left, middle, right
	int pivot = MedianChooser(arr, left, middle, right, myside);

	//swap pivot with left
	swap(&arr[pivot], &arr[left]);
	pivot = left_i;
	left_i += 1;

	//swap numbers bigger than pivot to the right, smaller to the left
	while (left_i < right + 1 && right_i > left){	//we need to count upto 'right'

		while (decideSide(&arr[left_i], myside) <= decideSide(&arr[pivot], myside) && left_i <= right_i) left_i++;	//position left_i to next number bigger than pivot AND check interchange(end of the array)
		while (decideSide(&arr[right_i], myside) >= decideSide(&arr[pivot], myside) && left_i <= right_i) right_i--;	//position right_i to next number smaller than pivot AND check interchange

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

void Divide(vector* arr, int left, int right, side myside){

	if (left < right){
		int pivot = Conquer(arr, left, right, myside);

		Divide(arr, left, pivot - 1, myside);
		//leave out arr[pivot] itself
		Divide(arr, pivot + 1, right, myside);

	}


}