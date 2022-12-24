#include<bits/stdc++.h>
#include "ASA.h"
using namespace std;

int main(){
    arrayOfSortedArray ds;
    for(int i = 0; i < 100000; ++i)
        ds.insert(i);
    vector<int> v;
    for(int i = 99000; i < 119000; ++i)
        v.push_back(i);
    for(auto &it : v){
        if(ds.search(it))
            cout << it << endl;

    }
    
	
}


