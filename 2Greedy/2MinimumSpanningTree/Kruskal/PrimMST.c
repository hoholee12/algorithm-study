#include<stdio.h>
#include<stdlib.h>
#include"KruskalMST.h"

vertex getVertex(tree mst, int start, int end){
	vertex temp = { -1, -1, -1 };	//fail
	for (int i = 0; i < mst.size; i++){
		if ((mst.arr[i].src == start && mst.arr[i].dest == end)
			|| (mst.arr[i].dest == start && mst.arr[i].src == end))
			return mst.arr[i];
	}

	return temp;

}

//end is -1
int* unusedEdges(tree mst, int edgecount){
	int* arr = malloc((edgecount + 1) * sizeof(int));
	memset(arr, -1, (edgecount + 1) * sizeof(int));

	int x = 0;
	for (int i = 0; i < edgecount; i++){
		for (int j = 0; j < mst.size; j++){
			if (mst.arr[j].src == i || mst.arr[j].dest == i){
				arr[x++] = i;
				break;
			}
		}
	}

	return arr;
}

tree PrimMST(tree mst, int edgecount, int startpoint){
	
	//D: weight append arr
	int* D = malloc(edgecount * sizeof(int));

	D[startpoint] = 0;

	for (int i = 0; i < edgecount; i++){
		vertex temp = getVertex(mst, startpoint, i);
		if (temp.weight != -1) D[i] = temp.weight;
		else D[i] = INT_MAX;
	}

	int* arr = malloc(0);
	tree T = { arr, 0 };


	while (T.size < edgecount){
		//push nearest smallest weight
		int* checkarr = unusedEdges(mst, edgecount);
		int Vmin = INT_MAX;
		int Imin = -1;
		for (int i = 0; checkarr[i] != -1; i++){
			if (Vmin > D[checkarr[i]]){
				Vmin = D[checkarr[i]];
				Imin = i;
			}
		}
		pushFirst(&T, getVertex(mst, Imin, Vmin));
		free(checkarr);

		//refresh weightarr
		checkarr = unusedEdges(mst, edgecount);
		for (int i = 0; i < edgecount; i++){
			int tempw = getVertex(mst, Vmin, i).weight;
			if (tempw < D[i]){
				D[i] = tempw;
			}
		}
	}

	return T;
}


int main(){
	enum{ a, b, c, d, e, f };
	vertex arr[] = { { b, c, 1 }, { c, f, 1 }, { b, f, 2 },
	{ a, d, 2 }, { d, e, 3 }, { a, e, 4 },
	{ b, d, 4 }, { d, f, 7 }, { a, b, 8 },
	{ e, f, 9 }
	};
	tree mst = { arr, 10 };
	/*
	mst = sortWeight(mst);

	for (int i = 0; i < mst.size; i++){
	printf("(%d, %d, %d) ", mst.arr[i].src, mst.arr[i].dest, mst.arr[i].weight);
	}
	*/
	tree result = PrimMST(mst, 10, c);

	for (int i = 0; i < result.size; i++){
		printf("(%c, %c, %d) ", 'a' + result.arr[i].src, 'a' + result.arr[i].dest, result.arr[i].weight);
	}

	free(result.arr);

	return 0;
}