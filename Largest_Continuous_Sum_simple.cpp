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
	int prev = big;
	int flag = 1;
	for (int i = 0; i < n; i++){
		prev += hey.at(i);
		if (imm < prev){
			imm = prev;
			check = i;
			flag = 1;
		}
		else if(flag == 1) { 
			flag = 0;
			prev = big;
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