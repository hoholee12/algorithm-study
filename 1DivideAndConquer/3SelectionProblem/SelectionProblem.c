#include<stdio.h>
#include<stdlib.h>
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


/*ksmallest: kth smallest number*/
int Divide(int* arr, int left, int right, int ksmallest){
	int pivot = Conquer(arr, left, right);

	int lowerGroup = (pivot - 1) - left + 1;
	
	if (ksmallest <= lowerGroup) return Divide(arr, left, pivot - 1, ksmallest);
	else if (ksmallest == lowerGroup + 1) return arr[pivot];
	else return Divide(arr, pivot + 1, right, ksmallest - lowerGroup - 1);

	//no
	return 0;
}

int main(){

	int arr[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int result = Divide(arr, 0, 9, 3);

	//print
	for (int i = 0; i < 10; i++) printf("%d ", arr[i]);
	printf("\n%dth smallest value is %d.\n", 3, result);

	return 0;
}