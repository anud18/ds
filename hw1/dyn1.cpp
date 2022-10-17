#include<bits/stdc++.h>
using namespace std;

ofstream ofs;

void show_k_powers_time(int k){
	vector<int> values(1,1);
	int times = 1 << k;
	clock_t start;
	start = clock();//開始計算新增所需時間
	values.emplace_back( rand());
	for(int i = 0; i < times - 1; ++i){
		values.emplace_back(rand());
	}
	clock_t stop = clock();//結束計算新增所需時間
	int sum = 0;
	ofs<< "k: "<< k << ' '<< "add needs "<< fixed << setprecision(6) <<double(stop - start) / CLOCKS_PER_SEC ;
	start = clock();//開始計算加總所需時間
	for(int n : values)
		sum += n;	
	stop = clock();//結束計算加總所需時間
	ofs << ' '<< "traversal needs "<< fixed << setprecision(6) <<double(stop - start) / CLOCKS_PER_SEC <<endl;
	values.clear();

}
int main(){
	srand(time(NULL));
	ofs.open("dynamic_array.txt", ios::app);
	for(int i = 15; i < 31; ++i)
		show_k_powers_time(i);
	ofs.close();
	return 0;
}


