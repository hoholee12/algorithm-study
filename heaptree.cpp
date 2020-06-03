#include<iostream>
#include<random>

#define MAX_HEAP 100

//max heap
class HeapArray{
private:

	int arr[MAX_HEAP];
	int lim = 0;


	void sortDown(int index){
		if (index >= MAX_HEAP) return; //oob

		int leftChild = (index + 1) * 2 - 1; int rightChild = leftChild + 1;
		if (arr[leftChild] > arr[rightChild] && arr[index] < arr[leftChild]){
			swap(arr[index], arr[leftChild]);
			sortDown(leftChild);
		}
		else if (arr[leftChild] < arr[rightChild] && arr[index] < arr[rightChild]){
			swap(arr[index], arr[rightChild]);
			sortDown(rightChild);
		}

	}

	void swap(int& a, int& b){
		int temp = a;
		a = b;
		b = temp;
	}

	int intLog2(int a){
		int log = 0;
		while (a >>= 1) log++;
		return log;
	}
	int intPow(int a, int pow){
		if (pow < 1) return 1;
		return a <<= pow - 1;
	}

	void sortUp(int index){
		if (index == 0) return;
		if (arr[index / 2] < arr[index]){
			swap(arr[index / 2], arr[index]);
			sortUp(index / 2);
		}
	}
public:

	void init(){ for (int i = 0; i < MAX_HEAP; i++) arr[i] = -1; }
	HeapArray(){ init(); }
	HeapArray(int* copyArr, int size){ init();  for (int i = 0; i < size; i++) arr[i] = copyArr[i]; lim = size; }

	void insertElement(int a){
		
		if (lim == MAX_HEAP) return; //oob

		arr[lim++] = a;

		sortUp(lim - 1);
	}

	void deleteElement(){
		arr[0] = arr[lim - 1];
		arr[lim - 1] = -1;
		lim--;
		sortDown(0);
	}

	void printTree(){
		int height = intLog2(lim) + 1;
		for (int i = 0; i < height; i++){
			for (int j = height; j > i; j--){
				std::cout << "\t";
			}
			for (int j = intPow(2, i) - 1; (j < intPow(2, i + 1) - 1) && (arr[j] != -1); j++){
				std::cout << arr[j] << "\t";
			}
			std::cout << std::endl;
		}
	}
};

/*
			0
		1
	3
7
*/

int main(){
	int arr[10] = { 9, 7, 6, 5, 4, 3, 2, 2, 1, 3 };
	HeapArray heap(arr, 10);
	
	heap.insertElement(2);

	heap.deleteElement();

	heap.printTree();

	return 0;
}