#include<bits/stdc++.h>

using namespace std;

const int maxValue = 1 << 30;
const int minValue = 1;
const int maxTimes = 1 << 20;

int main(){   
    unsigned int seed = 1 + 100*1;
    mt19937 gen(seed);
    uniform_int_distribution<> r_val(minValue,maxValue);
    vector<int> beSearched(100000);

    for(auto &it : beSearched){
        it = r_val(gen);
    }

    unordered_map<int, int> hash_table;
    //vector<int> record;
    for(int times = 0; times < maxTimes; ++times){
        int i = r_val(gen);
        //record.push_back(i);
        hash_table.emplace(i,i);
    }
    //cout << record[50] << ' ' << hash_table.bucket(record[50]);

    //int count = 0; 
    for(auto &it : beSearched){
        if(hash_table[it])
        cout << hash_table[it] << endl;
    }

    //int i = 0;
    //for(auto &it : beSearched){
    //cout << i++  << ' '<< it << endl; 
    //}

}
