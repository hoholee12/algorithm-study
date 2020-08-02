#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"KruskalMST.h"


//bool recursion
int find(int* set, int size, int target, int temptarget){
	if (set[temptarget] == target) return 1;	//found temptarget as union.
	else if (set[temptarget] == -1) return 0;	//found temptarget non union.
	else return find(set, size, target, set[temptarget]);
}

//bool
int checkCycle(int oldsize, tree newtree, vertex a){
	int* set = malloc(oldsize * sizeof(int));
	memset(set, -1, oldsize * sizeof(int));

	//create set
	for (int i = 0; i < newtree.size; i++){
		set[newtree.arr[i].src] = newtree.arr[i].dest;
	}

	//add one vertex
	if (set[a.src] != -1) set[a.dest] = a.src;
	else set[a.src] = a.dest;

	//check if it loops
	int boolcheck = 0;
	for (int i = 0; i < oldsize; i++){
		boolcheck += find(set, oldsize, i, i);
	}

	free(set);
	return boolcheck;
}

tree KruskalMST(tree mst, int edgecount){
	//sort first
	mst = sortWeight(mst);

	
	//new tree
	vertex* arr = malloc(0 * sizeof(vertex));
	tree newtree = { arr, 0 };

	//dispose cycle while re-adding vertexes
	while (newtree.size < edgecount - 1){
		vertex temp = popFirst(&mst);

		//check cycle
		if (checkCycle(edgecount, newtree, temp) == 0){
			//push if no cycle
			pushFirst(&newtree, temp);
		}
		//disregard if cycle
	}

	return newtree;

}

int main(){
	enum{a, b, c, d, e, f};
	vertex arr[] = { { b, c, 1 }, { c, f, 1 }, { b, f, 2 },
	{ a, d, 2 }, { d, e, 3 }, {a, e, 4},
	{ b, d, 4 }, { d, f, 7 }, {a, b, 8}, 
	{e, f, 9}
	};
	tree mst = { arr, 10 };
	/*
	mst = sortWeight(mst);
	
	for (int i = 0; i < mst.size; i++){
		printf("(%d, %d, %d) ", mst.arr[i].src, mst.arr[i].dest, mst.arr[i].weight);
	}
	*/
	tree result = KruskalMST(mst, f + 1);

	for (int i = 0; i < result.size; i++){
		printf("(%c, %c, %d) ", 'a' + result.arr[i].src, 'a' + result.arr[i].dest, result.arr[i].weight);
	}
	
	free(result.arr);

	return 0;
}