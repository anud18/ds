#include<bits/stdc++.h>
using namespace std;

void partition(vector<int> a, int low, int high, int& i, int& j)
{
    // To handle 2 elements
    if (high - low <= 1) {
        if (a[high] < a[low])
            swap(a[high], a[low]);
        i = low;
        j = high;
        return;
    }

    int mid = low;
    int pivot = a[high];
    while (mid <= high) {
        if (a[mid] < pivot)
            swap(a[low++], a[mid++]);
        else if (a[mid] == pivot)
            mid++;
        else if (a[mid] > pivot)
            swap(a[mid], a[high--]);
    }

    // update i and j
    i = low - 1;
    j = mid; // or high+1
}

// 3-way partition based quick sort
void quicksort(vector<int> &a, int low, int high)
{
    if (low >= high) // 1 or 0 elements
        return;

    int i, j;

    // Note that i and j are passed as reference
    partition(a, low, high, i, j);

    // Recur two halves
    quicksort(a, low, i);
    quicksort(a, j, high);
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

    counting_sort(arr.begin(), arr.end());

    stop = clock();//結束計算新增所需時間
    cout << "seed: " << seed << ' ' <<"k: "<< k << ' '<< "Counting sort needs "<< fixed << setprecision(6) <<double(stop - start) / CLOCKS_PER_SEC << endl;
    //for(int i = 0; i < 1 << k; ++i)
    //cout << arr[i] << ' ';
    vector<short>().swap(arr);
}
int main(){
    for(int j = 0; j < 10; ++j)
        for(int i = 15; i < 31; ++i)
            run_kSize(i,j);

}


