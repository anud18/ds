#include<bits/stdc++.h>
using namespace std;

ofstream ofs;

void show_k_powers_time(int k){
	list<int> values(1,1);
	int times = 1 << k;
	clock_t start;
	start = clock();
	values.emplace_back( rand());
	for(int i = 0; i < times - 1; ++i){
		values.emplace_back(rand());
	}
	clock_t stop = clock();
	int sum = 0;
	ofs << "k: "<< k << ' '<< "add needs "<< fixed << setprecision(6) <<double(stop - start) / CLOCKS_PER_SEC ;
	start = clock();
	for(int n : values)
		sum += n;	
	stop = clock();
	ofs << ' '<< "traversal needs "<< fixed << setprecision(6) <<double(stop - start) / CLOCKS_PER_SEC <<endl;
	if(k < 29)
		values.clear();
}
int main(){
	srand(time(NULL));
	ofs.open("list.txt", ios::app);
	for(int i = 15; i < 29; ++i)
		show_k_powers_time(i);
	ofs.close();
	return 0;
}


