#include<stdio.h>
#include<stdlib.h>

/*dropped_: drop decimals*/

//	Time complexity: O(N) = merge using temporary array
void Conquer(int* arr, int left, int dropped_middle, int right){
	int dropped_size = right - left;
	int size = dropped_size + 1;
	int middle = dropped_middle + 1;	//we can't have arr[left_i] == arr[right_i]
	
	//temporary array for merge
	int* temparr = malloc(sizeof(int)* size);

	//conquer
	int left_i = left;
	int right_i = middle;	//we can't have arr[left_i] == arr[right_i]

	int i = 0;
	for (; left_i < middle && right_i < right + 1; i++){	//we need to count upto 'right'

		if (arr[left_i] < arr[right_i]){
			temparr[i] = arr[left_i];
			left_i++;
		}
		else{
			temparr[i] = arr[right_i];
			right_i++;
		}
	}

	//leftover(only one will happen)
	for (; left_i < middle; i++, left_i++) temparr[i] = arr[left_i];
	for (; right_i < right + 1; i++, right_i++) temparr[i] = arr[right_i];	//we need to count upto 'right'

	//copy back
	for (int i = 0; i < size; i++) arr[left + i] = temparr[i];

	free(temparr);
}

//	Time complexity: O(logN) = binary recursion
void Divide(int* arr, int left, int right){
	int dropped_size = right - left;
	int size = dropped_size + 1;
	int dropped_middle = dropped_size / 2 + left;

	if (left < right){
		//divide(recursion)
		Divide(arr, left, dropped_middle);	//we can't have infinite (0, 1) recursion
		Divide(arr, dropped_middle + 1, right);

		Conquer(arr, left, dropped_middle, right);
	}
}

//	Total time complexity: O(NlogN) = O(N) * O(logN)
int main(){

	int arr[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	Divide(arr, 0, 9);

	//print
	for (int i = 0; i < 10; i++) printf("%d ", arr[i]);

	return 0;
}