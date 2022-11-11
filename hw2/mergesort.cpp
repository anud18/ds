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

    template<class BiDirIt, class Compare = std::less<>>
void merge_sort(BiDirIt first, BiDirIt last, Compare cmp = Compare{})
{
    auto const N = std::distance(first, last);
    if (N <= 1) return;                   
    auto const middle = std::next(first, N / 2);
    merge_sort(first, middle, cmp); // assert(std::is_sorted(first, middle, cmp));
    merge_sort(middle, last, cmp);  // assert(std::is_sorted(middle, last, cmp));
    std::inplace_merge(first, middle, last, cmp); // assert(std::is_sorted(first, last, cmp));
}

void run_kSize(int k,int n){
    unsigned int seed = k + 100*n;
    mt19937 gen(seed);
    uniform_int_distribution<> r_val(1,1000);

    vector<short> arr;
    arr.reserve(1 << k);
    clock_t start, stop;
    //start = clock();//開始計算新增所需時間
    for(int i = 0; i < (1 << k) ; i++)
        arr.push_back(r_val(gen));
    //stop = clock();//結束計算新增所需時間
    //cout << "k: "<< k << ' '<< "add needs "<< fixed << setprecision(6) <<double(stop - start) / CLOCKS_PER_SEC << endl;
    start = clock();//開始計算新增所需時間

    merge_sort(arr.begin(), arr.end());

    stop = clock();//結束計算新增所需時間
    cout << "seed: " << seed << ' ' <<"k: "<< k << ' '<< "Merge sort needs "<< fixed << setprecision(6) <<double(stop - start) / CLOCKS_PER_SEC << endl;
    //for(int i = 0; i < 1 << 10; ++i)
    //cout << arr[i] << ' ';
    vector<short>().swap(arr);
}
int main(){
    for(int j = 0; j < 10; ++j)
        for(int i = 15; i < 31; ++i)
            run_kSize(i,j);

}


