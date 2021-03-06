#include"ClosestPair.h"
#include<math.h>

typedef struct{
	vector* arr;
	int xleft;
	int xright;
} vecarr;

double dist(pair a){
	return sqrt(pow(a.a.x - a.b.x, 2) + pow(a.a.y - a.b.y, 2));
}

//insertion sort
pair nearestPairChooser(pair* temparr, int size){
	double* distarr = malloc(size * sizeof(double));
	for (int i = 0; i < size; i++){
		distarr[i] = dist(temparr[i]);
	}

	for (int i = 1; i < size; i++){
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

	free(distarr);

	return temparr[0];


}

pair ClosestPair(vecarr S){
	pair temp = { S.arr[S.xleft], S.arr[S.xright] };
	pair temp2 = { S.arr[S.xleft + 1], S.arr[S.xright] };
	pair temp3 = { S.arr[S.xleft], S.arr[S.xright - 1] };
	pair temparr[3] = { temp, temp2, temp3 };
	int Ssize = S.xright - S.xleft + 1;

	//return 2 or 3 pairs
	switch (Ssize){
	case 3:
		return nearestPairChooser(temparr, 3);
	case 2:
		return temp;
	}

	//cut S in half: SL, SR
	//if odd num: SL = SR + 1
	int half = (S.xright - S.xleft) / 2 + S.xleft;
	vecarr SL = { S.arr, S.xleft, half };
	vecarr SR = { S.arr, half + 1, S.xright };

	pair CPL = ClosestPair(SL);
	pair CPR = ClosestPair(SR);
	//immediate d calc for CPC
	int d = (int)min(dist(CPL), dist(CPR));

	//make an array of pairs within +-d range for CPC
	int scleft = half - d;
	int scright = half + d;
	if (scleft < S.xleft) scleft = S.xleft;
	if (scright > S.xright) scright = S.xright;
	vecarr SC = { S.arr, scleft, scright };
	int SCsize = SC.xright - SC.xleft + 1;
	//sort to y side first for faster filter
	Divide(SC.arr, SC.xleft, SC.xright, yside);

	int dmin = INT_MAX;
	pair CPC;
	//avoid one sided pairs(these pairs are already covered by SL SR recursion) by filtering with half
	//compares at most 6 times
	for (int i = SC.xleft; i <= SC.xright; i++){
		if (SC.arr[i].x <= half){
			for (int j = SC.xleft; j <= SC.xright; j++){
				if (SC.arr[j].x > half){

					//get nearest pair here: CPC
					pair tval = { SC.arr[i], SC.arr[j] };
					int tmin = (int)dist(tval);
					if (dmin > tmin){
						dmin = tmin;
						CPC = tval;
					}
				}
			}
		}
	}
	
	//compare CPL, CPR, CPC
	pair* tarr = malloc(3 * sizeof(pair));
	tarr[0] = CPL;
	tarr[1] = CPR;
	tarr[2] = CPC;
	return nearestPairChooser(tarr, 3);
}


int main(){
	vector temp[5] = { { 3, 2 }, { 5, 4 }, { 10, 1 }, { 1, 5 }, { 2, 5 } };
	vecarr S = { temp, 0, 4 };

	//sort x side first
	Divide(S.arr, S.xleft, S.xright, xside);
	
	//for (int i = 0; i < 5; i++) printf("(%d, %d) ", S.arr[i].x, S.arr[i].y);
	
	pair result = ClosestPair(S);

	printf("\nresult = (%d, %d) -> (%d, %d)", result.a.x, result.a.y, result.b.x, result.b.y);

	return 0;
}