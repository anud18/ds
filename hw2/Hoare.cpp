#include<bits/stdc++.h>
using namespace std;
//int partition(vector<short> &arr, int begin, int end){
//Lomuto
//int pivot = arr[end-1];
//int i, j;
//for (i = j = begin; j < end - 1; j++)
//if (arr[j] <= pivot)
//swap(arr[i++], arr[j]);
//swap(arr[i], arr[end - 1]);
//return i;
//}
int partition(vector<short> &arr, int low, int high){
    int pivot = arr[low];
    int i = low - 1, j = high + 1;

    while (true) {
        // Find leftmost element greater than
        // or equal to pivot
        do {
            i++;
        } while (arr[i] < pivot);

        // Find rightmost element smaller than
        // or equal to pivot
        do {
            j--;
        } while (arr[j] > pivot);

        // If two pointers met.
        if (i >= j)
            return j;

        swap(arr[i], arr[j]);
    }
}

void quickSort(vector<short> &arr, int begin, int end){
    if(begin < end - 1){
        int mid = partition(arr, begin, end);
        quickSort(arr, begin, mid);
        quickSort(arr, mid + 1, end);
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

    template<class FwdIt, class Compare = std::less<>>
void insertion_sort(FwdIt first, FwdIt last, Compare cmp = Compare{})
{
    for (auto it = first; it != last; ++it) {
        auto const insertion = std::upper_bound(first, it, *it, cmp);
        std::rotate(insertion, it, std::next(it));
        assert(std::is_sorted(first, std::next(it), cmp));
    }
}
    template<typename ForwardIterator>
void counting_sort(ForwardIterator first, ForwardIterator last)
{
    if (first == last || std::next(first) == last) return;

    auto minmax = std::minmax_element(first, last);  // avoid if possible.
    auto min = *minmax.first;
    auto max = *minmax.second;
    if (min == max) return;

    using difference_type = typename std::iterator_traits<ForwardIterator>::difference_type;
    std::vector<difference_type> counts(max - min + 1, 0);

    for (auto it = first ; it != last ; ++it) {
        ++counts[*it - min];
    }

    for (auto count: counts) {
        first = std::fill_n(first, count, min++);
    }
}
void run_kSize(int k, int n){
    unsigned int seed = k + 100*n;
    mt19937 gen(seed);
    uniform_int_distribution<> r_val(1,1000);

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

