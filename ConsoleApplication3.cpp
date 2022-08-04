#include<iostream>
#include<cstdio>
#include<vector>	//heap is supported here
#include<list>
#include<deque>
#include<utility>	//pair
#include<set>
#include<map>
#include<stack>
#include<queue>		//queue, priority_queue
#include<unordered_map>	//this is basically hashtable


#pragma warning(disable:4996)

using namespace std;

//amortized: 대체적으로, 최악의경우 다를 수 있음.

void howto_string() {
	string s, s1;
	s = "hello";
	s1 = "hello";

	if (s.compare(s1) == 0) {
		printf("%s is equal to %s\n", s.c_str(), s1.c_str());
	}
	else {
		printf("%s is not equal to %s\n", s.c_str(), s1.c_str());
	}

	s.append(" world!");
	printf("%s\n", s.c_str());
}

//vector: sequence container (insert takes O(1)/O(n) if inserting on position other than end(in order to shift the rest of the values) and find takes O(n))
//COW -> slow, but its always sequential in addr, so pointer arith works anytime.
void howto_iterate_vector() {
	vector<int> v;
	vector<int>::iterator it;
	v.push_back(5);
	while (v.back() > 0)
		v.push_back(v.back() - 1);
	//5 4 3 2 1 0
	for (it = v.begin(); it != v.end(); it++) {
		printf("%d ", *it);
	}
	printf("\n");

	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v.at(i));
	}
	printf("\n");

	while (!v.empty()) {
		printf("%d ", v.back());
		v.pop_back();	// 0 1 2 3 4 5
	}
	printf("\n");
}

//list: sequence container (insert takes O(1) and find takes O(n))
// linked list, therefore no need to whole copy when allocating new.
//cannot find in the middle. however insert middle works O(1)
void howto_list() {
	list<int> l;
	list<int>::iterator it;

	l.push_back(4);
	l.push_back(5);
	// 4 5


	l.push_front(3);
	l.push_front(5);
	// 5 3 4 5

	it = l.begin();

	l.insert(it, 1); //insert in the beginning
	it = l.begin(); //because i am now 2nd
	for (; it != l.end(); it++) {
		printf("%d ", *it);	// 1 5 3 4 5
	}
	printf("\n");

	l.reverse();
	for (it = l.begin(); it != l.end(); it++) {
		printf("%d ", *it); // 5 4 3 5 1
	}
	printf("\n");

	l.remove(5);	// 4 3 1 remove all occurence of 5
	for (it = l.begin(); it != l.end(); it++) {
		printf("%d ", *it);
	}
	printf("\n");
}

//better than vector when inserting
// circular buffer, fast random access
//even can insert on start as O(1) compared to vector
//allocates mems in chunks, so addr wont be sequential, cant do pointer arith.
void howto_deque() {
	deque<int> dq;
	deque<int>::iterator it;
	deque<int>::reverse_iterator rit;
	for (int i = 0; i < 5; i++) {
		dq.push_back((i + 1) * 10);
	}

	for (it = dq.begin(); it != dq.end(); it++) {
		printf("%d ", *it);
	}
	printf("\n");

	dq.push_front(1);
	dq.push_front(2);
	dq.push_back(100);
	dq.push_back(200);

	for (it = dq.begin(); it != dq.end(); it++) {
		printf("%d ", *it);
	}
	printf("\n");

	for (rit = dq.rbegin(); rit != dq.rend(); rit++) {
		printf("%d ", *rit);
	}
	printf("\n");

	//insert in middle
	it = dq.begin() + 2;
	dq.insert(it, 1234);
	for (it = dq.begin(); it != dq.end(); it++) {
		printf("%d ", *it);
	}
	printf("\n");

	//delete in middle
	it = dq.end() - 1; //always ends at end - 1
	dq.erase(it);
	for (it = dq.begin(); it != dq.end(); it++) {
		printf("%d ", *it);
	}
	printf("\n");

}

void howto_pair() {
	pair<int, char> p;
	pair<int, char> p1(2, 'b');

	p = make_pair(1, 'a');
	printf("%d %c\n", p.first, p.second);
	printf("%d %c\n", p1.first, p1.second);
}

//uses rbtree so insert O(logN), find O(logN)
void howto_set() {
	set<int> s;
	set<int>::iterator it;
	int A[] = { 3, 5, 2, 1, 5, 4 };
	for (int i = 0; i < 6; i++) {
		s.insert(A[i]);
	}
	for (it = s.begin(); it != s.end(); it++) {
		printf("%d ", *it);	// 1 2 3 4 5
	}
	printf("\n");
}

//uses rbtree so same as set
void howto_map() {
	map<char, int> mp;
	map<char, int> mymap, mymap1;

	mp.insert(pair<char, int>('a', 2));
	mp.insert(make_pair('b', 1));
	mp.insert({ 'c', 43 });

	mymap.insert(mp.begin(), mp.end());

	map<char, int>::iterator it;

	it = mp.find('b');
	printf("%c -> %d\n", it->first, it->second);
	printf("%c -> %d\n", 'b', mp.at('b'));

	//alternative
	mymap1['x'] = 23;
	mymap1['y'] = 21;
	printf("\n");
	mymap.swap(mymap1); //swap elements
	for (it = mymap.begin(); it != mymap.end(); it++) {
		printf("%c -> %d\n", it->first, it->second);	//should print out x -> 23 and y -> 21
	}

	mymap1.erase('c');
	for (it = mymap1.begin(); it != mymap1.end(); it++) {
		printf("%c -> %d\n", it->first, it->second);	//should print without c
	}

	mymap1.erase(mymap1.begin(), mymap1.end());
	printf("is mymap1 empty?: %d\n", mymap1.empty());	//will return 1

	printf("num of elements with key = a: %d\n", mp.count('a'));	//will return 1
}

void howto_stack() {
	stack<int> s;

	for (int i = 0; i < 5; i++) {
		s.push(i);	// 0, 1, 2, 3, 4
	}

	printf("size = %d top element = %d\n", s.size(), s.top()); //5 4
	for (int i = 0; i < 5; i++) {
		printf("%d is popped out\n", s.top());	//do this before popping
		s.pop();
	}
	printf("is stack empty?: %d\n", s.empty());
}

void howto_queue() {
	char qu[4] = { 'a', 'b', 'c', 'd' };
	queue<char> q;
	char ch;
	for (int i = 0; i < 4; i++) {
		q.push(qu[i]);
	}
	for (int i = 0; i < 3; i++) {
		ch = q.front();
		q.push(ch);
		q.pop();
		//d, a, b, c
	}
	while (!q.empty()) {
		printf("%c", q.front());
		q.pop();
	}
	printf("\n");
}


class for_priorityqueue {
public:
	bool operator()(const int& lhs, const int& rhs) {
		return lhs < rhs;
	}

};
class for_priorityqueue2 {
public:
	bool operator()(const pair<int, string>& lhs, const pair<int, string>& rhs) {
		return lhs.first < rhs.first;
	}
};

//this code uses vector(sequential container), so insert O(1), find O(logN)
void howto_priorityqueue() {
	vector<int> v(vector<int>{5, 2, 6, 1, 8, 4});	//this is only copied.

	//new vector container and custom class needed for priority queue.
	priority_queue<int, vector<int>, for_priorityqueue> pq(v.begin(), v.end());
	//logarithmic insert, based on make_heap
	while (!pq.empty()) {
		printf("%d ", pq.top());
		pq.pop();
	}
	printf("\n");

	vector<pair<int, string>> s;
	s.push_back(make_pair(5, "이민주"));
	s.push_back(make_pair(3, "최우재"));
	s.push_back(make_pair(7, "한정우"));
	s.push_back(make_pair(2, "유상욱"));
	s.push_back(make_pair(4, "조상범"));

	priority_queue<pair<int, string>, vector<pair<int, string>>, for_priorityqueue2> pq2(s.begin(), s.end());
	while (!pq2.empty()) {
		printf("first: %d second: %s\n", pq2.top().first, pq2.top().second.c_str());
		pq2.pop();
	}

}
void howto_heap() {
	//heap uses vector container.
	vector<int> v(vector<int>{1, 6, 5, 2, 3, 8, 4, 9, 7});
	//before make_heap
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		printf("%d ", *it);
	}
	printf("\n");
	//after make_heap
	make_heap(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		printf("%d ", *it);
	}
	printf("\n");
	//to insert with heap algo, put on back
	v.push_back(10);
	push_heap(v.begin(), v.end());	//logN
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		printf("%d ", *it);
	}
	printf("\n");
	//popping puts it on back
	pop_heap(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		printf("%d ", *it);
	}
	printf("\n");
}

void howto_hashtable() {
	unordered_map<string, int> um;
	um.insert(make_pair("key", 1));
	um["banana"] = 2;
	um.insert({ "melon", 3 });

	printf("size: %d\n", um.size());
	for (auto elem : um) {	//pair<string, int> elem
		printf("k: %s, v: %d", elem.first.c_str(), elem.second);
	}
	printf("\n");

	if (um.find("banana") != um.end()) {
		um.erase("banana");
	}

	printf("size: %d\n", um.size());
	for (auto elem : um) {	//pair<string, int> elem
		printf("k: %s, v: %d", elem.first.c_str(), elem.second);
	}
	printf("\n");
}



int main() {
	howto_deque();

	return 0;

}