#include<bits/stdc++.h>
using namespace std;

const int maxValue = 1 << 30;
const int minValue = 1;
void run_kSize(int k, int n){
    unsigned int seed = k + 100*n;
    mt19937 gen(seed);
    uniform_int_distribution<> r_val(minValue,maxValue);
    vector<int> beSearched(100000);

    vector<short> arr;
    arr.reserve(1 << k);
    clock_t start, stop;
    for(int i = 0; i < (1 << k) ; i++)
        arr.push_back(r_val(gen));
    start = clock();//開始計算新增所需時間

    quickSort(arr, 0, arr.size() - 1);
    //cout << arr.size() << ' ' << arr[arr.size() - 1];

    stop = clock();//結束計算新增所需時間
    cout << "seed: " << seed << ' ' <<"k: "<< k << ' '<< "Counting sort needs "<< fixed << setprecision(6) <<double(stop - start) / CLOCKS_PER_SEC << endl;
    vector<short>().swap(arr);
}
int main(){
    for(int j = 1; j < 10; ++j)
        for(int i = 15; i < 31; ++i)
            run_kSize(i, j);

}


