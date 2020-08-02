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

vertex popFirst(tree* mst){
	if (mst->size == 0){
		vertex temp = { 0, 0 };
		return temp;
	}

	vertex temp = mst->arr[0];
	for (int i = 0; i < mst->size - 1; i++){
		mst->arr[i] = mst->arr[i + 1];
	}
	mst->size -= 1;
	return temp;
}

void pushFirst(tree* mst, vertex a){

	//realloc
	vertex* newarr = malloc((mst->size + 1) * sizeof(vertex));
	newarr[0] = a;
	for (int i = 0; i < mst->size; i++){
		newarr[i + 1] = mst->arr[i];
	}
	free(mst->arr);

	mst->arr = newarr;
	mst->size += 1;
}


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