#include<bits/stdc++.h>
using namespace std;

int partition(vector<short> &arr, int begin, int end){
    int pivot = arr[end-1];
    int i, j;
    for (i = j = begin; j < end - 1; j++)
        if (arr[j] <= pivot)
            swap(arr[i++], arr[j]);
    swap(arr[i], arr[end - 1]);
    return i;
}

void quickSort(vector<short> &arr, int begin, int end){
    if(begin < end - 1){
        int mid = partition(arr, begin, end);
        quickSort(arr, begin, mid);
        quickSort(arr, mid, end);
    }

}
void run_kSize(int k, int n){
    unsigned int seed = k + n * 100;
    mt19937 gen(seed);
    uniform_int_distribution<> r_val(1,1000);

    vector<short> arr;
    arr.reserve(1 << k);
    clock_t start, stop;
    //start = clock();//開始計算新增所需時間
    for(int i = 0; i < (1<<k); i++)
        arr.push_back(r_val(gen));
    //cout << arr[0];
    //stop = clock();//結束計算新增所需時間
    //cout << "k: "<< k << ' '<< "add needs "<< fixed << setprecision(6) <<double(stop - start) / CLOCKS_PER_SEC << endl;
    start = clock();//開始計算新增所需時間

    quickSort(arr, 0, arr.size());

    stop = clock();//結束計算新增所需時間
    cout << "seed: " << seed <<" k: "<< k << ' '<< "Lomuto needs "<< fixed << setprecision(6) <<double(stop - start) / CLOCKS_PER_SEC << endl;
    vector<short>().swap(arr);
}
int main(){
    for(int j = 1; j < 10; ++j)
        for(int i = 15; i < 25; i++)
            run_kSize(i,j);

}


