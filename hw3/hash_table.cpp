#include<bits/stdc++.h>

using namespace std;
const int minValue = 1;
const int maxValue = 1 << 30;
const int SearchSize = 100000;

void runKsize(int k){
    unsigned int seed = 1 + 100*1;
    mt19937 gen(seed);
    uniform_int_distribution<> r_val(minValue,maxValue);
    int n = 1 << k;
    
    vector<int> beSearched(SearchSize);
    for(int i = 0; i < SearchSize; ++i)
        beSearched.push_back(r_val(gen));

    clock_t start, stop;
    start = clock();
    unordered_set<int> hash_table(n);
    for(int times = 0; times < n; ++times){
        hash_table.emplace(r_val(gen));
    }
    stop = clock();
    cout << "k:" << k << ' '<< "construction needs "<< fixed << setprecision(6) <<double(stop - start) / CLOCKS_PER_SEC << endl;

    start = clock();
    for(auto &it : beSearched){
        hash_table.find(it);
    }
    stop = clock();
    cout << "k:" << k << ' '<< "search needs "<< fixed << setprecision(6) <<double(stop - start) / CLOCKS_PER_SEC << endl;

}


int main(){   
    for(int i = 10; i < 29; ++i){
        runKsize(i);
    }

}
