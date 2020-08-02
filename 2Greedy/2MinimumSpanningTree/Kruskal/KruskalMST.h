#pragma once


typedef struct{
	int src;
	int dest;
	int weight;

} vertex;

typedef struct{
	vertex* arr;
	int size;
}
tree;



//insertion sort
tree sortWeight(tree mst){
	
	for (int i = 1; i < mst.size; i++){
		//
		vertex temp = mst.arr[i];
		int j = i - 1;
		for (; j >= 0; j--){
			//
			if (temp.weight < mst.arr[j].weight){
				//
				mst.arr[j + 1] = mst.arr[j];
			}
			else{
				break;
			}
		}
		//
		mst.arr[j + 1] = temp;
	}


	return mst;


}