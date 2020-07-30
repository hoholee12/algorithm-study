#include"ClosestPair.h"
#include<math.h>

typedef struct{
	vector* arr;
	int left;
	int right;
} vecarr;

double dist(pair a){
	return sqrt(pow(a.a.x - a.b.x, 2) + pow(a.a.y - a.b.y, 2));
}

//insertion sort
pair threePairChooser(pair* temparr){
	double distarr[3] = { dist(temparr[0]), dist(temparr[1]), dist(temparr[2]) };
	for (int i = 1; i < 3; i++){
		double temp = distarr[i];
		pair temp2 = temparr[i];
		int j = i - 1;
		for (; j >= 0; j--){
			double x = distarr[j];
			if (temp < x){
				distarr[j + 1] = distarr[j];
				temparr[j + 1] = temparr[j];

			}
			else{
				break;
			}
		}
		distarr[j + 1] = temp;
		temparr[j + 1] = temp2;
	}

	return temparr[0];


}

pair ClosestPair(vecarr S){
	pair temp = { S.arr[S.left], S.arr[S.right] };
	pair temp2 = { S.arr[S.left + 1], S.arr[S.right] };
	pair temp3 = { S.arr[S.left], S.arr[S.right - 1] };
	pair temparr[3] = { temp, temp2, temp3 };
	//return 2 or 3 pairs
	switch (S.right - S.left + 1){
	case 3:
		return threePairChooser(temparr);
	case 2:
		return temp;
	}

	//cut S in half: SL, SR
	//if odd num: SL = SR + 1
	int half = (S.right - S.left) / 2 + S.left;
	vecarr SL = { S.arr, S.left, half };
	vecarr SR = { S.arr, half + 1, S.right };

	pair CPL = ClosestPair(SL);
	pair CPR = ClosestPair(SR);
	double d = min(dist(CPL), dist(CPR));

	//TODO

	return ;


}


int main(){
	vector temp[3] = { { 1, 5 }, { 2, 5 }, { 3, 2 }};
	vecarr S = { temp, 0, 2 };

	//sort x side first
	Divide(S.arr, S.left, S.right, xside);
	
	//for (int i = 0; i < 5; i++) printf("(%d, %d) ", S.arr[i].x, S.arr[i].y);
	
	pair result = ClosestPair(S);

	printf("\nresult = (%d, %d) -> (%d, %d)", result.a.x, result.a.y, result.b.x, result.b.y);

	return 0;
}