#include<bits/stdc++.h>
using namespace std;
ofstream ofs;
void show_k_powers_time(int k){
	clock_t start, stop, t_start, t_stop;
	start = clock();
	vector<int> v(1);
	srand(time(NULL));
	int times = 1 << k;
	v[0] =  rand();
	for(int i = 0; i < times - 1; ++i){
		v.push_back(rand());
	}
	stop = clock();
	cout << "k: "<< k << ' '<< fixed << setprecision(6)<< double(stop - start) / CLOCKS_PER_SEC <<endl;
	int sum = 0;
	t_start = clock();
	for(int i = 0; i < v.size(); ++i)
		sum += v[i];
	t_stop = clock();
	ofs << "k: "<< k << "traversal need "<< double(t_stop - t_start) / CLOCKS_PER_SEC <<endl;
	//清除記憶體空間
	std::vector<int>().swap(v);
}
int main(){
	ofs.open("dyn_arr_output.txt",  ios::app);
	for(int i = 15; i <= 31; ++i){
		show_k_powers_time(i);
	}
	ofs.close();
}
