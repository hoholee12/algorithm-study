#include<iostream>
#include<cstring>
using namespace std;

struct Node {
	string value;
	struct Node* next;
};

Node mempool[100000];
int mempoolptr = 0;
Node* allocMem() {
	return &mempool[mempoolptr++];
}


//buckets
Node* head[100];


Node* pushBack(Node** myhead, string& value) {
	Node* temp = nullptr;
	if (*myhead == nullptr) {
		*myhead = allocMem();
		temp = *myhead;
	}
	else {
		temp = *myhead;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = allocMem();
		temp = temp->next;
	}
	temp->next = nullptr;
	temp->value = value;
	return temp;
}

Node* pushFront(Node** myhead, string& value) {
	Node* temp = nullptr;
	if (*myhead == nullptr) {
		*myhead = allocMem();
		temp = *myhead;
		temp->next = nullptr;
	}
	else {
		temp = *myhead;
		*myhead = allocMem();
		(*myhead)->next = temp;
		temp = *myhead;
	}
	temp->value = value;
	return temp;
}


void initbucket() {
	memset(head, 0, sizeof(Node*) * 100);
}

int hashFunc(string& value) {	
	unsigned int sum = 1; //unsigned to remove negative value
	for (int i = 0; i < value.length(); i++) {
		sum *= value[i];
	}

	return sum % 100; /*0~99 slots*/
}

void insertNode(string& value) {
	int whereto = hashFunc(value);
	Node** inserthead = &head[whereto];
	pushBack(inserthead, value);
}

void printHead(Node* head) {
	if (head == nullptr) return;	//nothing is in the list
	Node* temp = head;
	while (temp->next != nullptr) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << temp->value << " ";
	cout << endl;
}

int findVal(Node** myhead, string& value) {
	if (*myhead == nullptr) return 0;
	Node* temp = *myhead;

	while (temp->next != nullptr) {
		if (temp->value == value) return 1;
		temp = temp->next;
	}
	if (temp->value == value) return 1;
	return 0;
}

int findNode(string& value) {
	int whereto = hashFunc(value);
	Node** findhead = &head[whereto];
	return findVal(findhead, value);
}

int main() {
	const int cnt = 10;
	string hello[cnt] = { "hi", "there", "how", "are", "you", "today", "?", "im", "fine", "thank" };

	for (int i = 0; i < cnt; i++) {
		insertNode(hello[i]);
	}

	for (int i = 0; i < 100; i++) {
		printHead(head[i]);
	}

	while (1) {
		string value;
		cout << "what to find?: ";
		cin >> value;
		if (findNode(value)) {
			cout << "Exists!" << endl;
		}
		else {
			cout << "Doesnt exist!" << endl;
		}

	}

	return 0;
}