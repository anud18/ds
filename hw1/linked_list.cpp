#include<bits/stdc++.h>
using namespace std;
struct ListNode{
	int data;
	ListNode *next;
};
void insert(int k){
	ListNode values;
	values.data = 1;
	ListNode *now = &values;
	int times = 1 << k;
	for(int i = 0; i < times - 1; ++i){
		ListNode *newNode = new ListNode;
		now->next = newNode;
		now->data = 1;
	}
	ListNode *head = values.next;
	while(head){
		ListNode *tmp = head;
		head = head->next;
		delete tmp;
	}

}
void show_k_powers_time(int k){
	list<int> values(1);
	srand(time(NULL));
	int times = 1 << k;
	values.emplace_front( rand());
	for(int i = 0; i < times - 1; ++i){
		values.emplace_back(rand());
	}
	values.clear();

}
int main(){
	srand(time(NULL));
	for(int i = 15; i <= 29; ++i){
		clock_t start, stop;
		start = clock();
		insert(i);
		stop = clock();
		cout << "k: "<< i << ' '<<double(stop - start) / CLOCKS_PER_SEC <<endl;
	}
}


