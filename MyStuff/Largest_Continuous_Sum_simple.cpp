#include<iostream>
#include<vector>
#include<climits>
int main(){
	int n;
	std::vector<int> x;
	std::cin >> n;
	
	int input;
	for (int i = 0; i < n; i++) {
		std::cin >> input;
		x.push_back(input);
	}

	int result = INT_MIN;
	int temp = 0;
	for (int i = 0; i < n; i++){
		//append
		temp += x.at(i);
		//reset every big change
		if (x.at(i) > temp) temp = x.at(i);
		//get every big num
		if (result < temp) result = temp;
	}

	std::cout << result;

	return 0;

}