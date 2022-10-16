#include<bits/stdc++.h>
using namespace std;
	vector<int> values(1, 1);
struct ListNode{
	int data;
	ListNode *next;
};
void insert(int k){
	ListNode values;
	values.data = rand();
	ListNode *now = &values;
	int times = 1 << k;
	for(int i = 0; i < times - 1; ++i){
		ListNode *newNode = new ListNode;
		now->next = newNode;
		now->data = rand();
	}
	//ListNode *head = values.next;
	//while(head){
	//ListNode *tmp = head;
	//head = head->next;
	//delete tmp;
	//}

}
void show_k_powers_time(int k){
	list<int> values(1,1);
	srand(time(NULL));
	int times = 1 << k;
	values.emplace_back( rand());
	for(int i = 0; i < times - 1; ++i){
		values.emplace_back(rand());
	}
	values.clear();

}
int main(){
	int times= 1, k = 15;
	srand(time(NULL));
	clock_t start;
	start = clock();
	while(k <= 30){
		while(times < (1 << k)-100){
			values.emplace_back(rand());
			times++;
		}
		clock_t stop = clock();
		cout << "k: "<< k << ' '<<double(stop - start) / CLOCKS_PER_SEC <<endl;
		cout << values.size();
		k++;
	}

	//for(int i = 15; i <= 30; ++i){
	//srand(time(NULL));
	//clock_t start, stop;
	//start = clock();
	//show_k_powers_time(i);
	//}
}


