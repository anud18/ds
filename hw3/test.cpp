#include<bits/stdc++.h>
#include"BTREE.h"

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
    BTree btree(512);
    for(int times = 0; times < n; ++times){
        //int i = r_val(gen);
        //cout << i <<endl;
        btree.insert(r_val(gen));
    }
    stop = clock();
    cout << "seed: " << seed << ' '  << "k:" << k << ' '<< "Hash table construction needs "<< fixed << setprecision(6) <<double(stop - start) / CLOCKS_PER_SEC << endl;

    start = clock();
    for(auto &it : beSearched){
        if(btree.search(it)){

        }
    }
    stop = clock();
    cout << "seed: " << seed << ' '  << "k:" << k << ' '<< "Hash table search needs "<< fixed << setprecision(6) <<double(stop - start) / CLOCKS_PER_SEC << endl;

}


int main(){   
    runKsize(20);


}



///1 4 7 8 8 9
//1 4 7
//8
//
//
//
//1
//4
//7
//
