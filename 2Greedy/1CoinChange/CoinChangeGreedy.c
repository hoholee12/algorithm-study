#include<stdio.h>

typedef struct{
	int* arr;
	int size;
} CoinTypes;

int CoinChangeGreedy(CoinTypes ctypes, int amount){
	int change = amount;
	int count = 0; //used coin count
	for (int i = 0; i < ctypes.size; i++){
		while (change >= ctypes.arr[i]){
			change -= ctypes.arr[i];
			count++;
		}
	
	}

	return count;
}

int main(){

	int arr[] = { 500, 100, 50, 10, 1 };

	CoinTypes ctype = { arr, 5 };

	printf("coin count: %d\n", CoinChangeGreedy(ctype, 1234));	//500 * 2 + 100 * 2 + 50 * 0 + 10 * 3 + 1 * 4 = 11

	return 0;
}