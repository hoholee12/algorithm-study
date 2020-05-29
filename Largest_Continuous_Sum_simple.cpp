#include<vector>
#include<iostream>
#include<climits>

using vector = std::vector<int>;

int main(){
	vector hey;
	int n;

	std::cin >> n;
	
	int input;
	int big = INT_MAX;
	for (int i = 0; i < n; i++) { 
		std::cin >> input; hey.push_back(input);
		if (big > input) big = input;
	}
	
	int check = 0;	
	int imm = big;
	int loop = big;
	int prevloop = loop << 1;
	int flag = 1;
	for (int i = 0; i < n; i++){
		loop += hey.at(i);
		if (loop > prevloop){
			check = i;
			prevloop = loop;
		}
		if (imm < loop){
			imm = loop;
			flag = 1;
		}
		else if (flag == 1 || big > loop) {
			flag = 0;
			loop = big;
		}
	}

	vector left;
	vector right;
	big = INT_MIN;
	input = 0;
	for (int i = check - 1; i > -1; i--){
		input += hey.at(i);
		left.push_back(input);
		if (big < input) big = input;
	}
	input = 0;
	for (int i = check; i < n; i++){
		input += hey.at(i);
		right.push_back(input);
		if (big < input) big = input;
	}

	input = 0;
	for (int i = 0; i < left.size(); i++){
		for (int j = 0; j < right.size(); j++){
			input = left.at(i) + right.at(j);
			if (big < input) big = input;
		}
	}

	std::cout << big;

	return 0;

}