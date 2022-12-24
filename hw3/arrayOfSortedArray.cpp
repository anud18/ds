#include<bits/stdc++.h>
using namespace std;
void mergeTwoSortedArray(vector<int>& v1, vector<int>& v2, vector<int>& v3);

class arrayOfSortedArray{
    public:
        arrayOfSortedArray();
        void insert(int element);
        bool search(int target);
        void merge(int curLevel);
    public:
        vector<vector<int>> arr;
        vector<vector<int>> _arr;
};
arrayOfSortedArray::arrayOfSortedArray(){
    arr.reserve(31);
    _arr.reserve(31);
    arr.push_back(vector<int>(1));
    _arr.push_back(vector<int>(1));
    arr[0].clear();
    _arr[0].clear();
}
void arrayOfSortedArray::insert(int element){
    //cout << "call insert " << element << endl;
    _arr[0].push_back(element);
    if(arr[0].empty()){
        arr[0].push_back( _arr[0][0]);
        _arr[0].clear();
    }
    else{
        //cout << "not empty call merge" << endl;
        //cout << "_arr: ";
        //for(auto it : _arr[0])
        //cout << it << ' ';
        //cout << endl;
        merge(0);
    }

}
void arrayOfSortedArray::merge(int curLevel){
    //cout << "call merge" << ' ' << _arr.size()<< endl;
    int nextLevel = curLevel + 1;
    if(nextLevel == arr.size()){
        arr.push_back(vector<int>(1 << nextLevel));
        _arr.push_back( vector<int>(1 << nextLevel));
        mergeTwoSortedArray(arr[curLevel], _arr[curLevel], arr[nextLevel]);
        //cout << "After merge arr.size: " << arr.size() << endl; 
    }
    else if(arr[nextLevel].empty()){
        //cout << "action2" <<endl;
        mergeTwoSortedArray(arr[curLevel], _arr[curLevel], arr[nextLevel]);
    }
    else{//_arr[curLevel] is full
        //cout << "action3" <<endl;
        mergeTwoSortedArray(arr[curLevel], _arr[curLevel], _arr[nextLevel]);
        merge(nextLevel);
    }
}
bool arrayOfSortedArray::search(int target){
    int i = 0;
    for(auto &it : arr){
        if(it.empty()){
            continue;
        }

        //cout << "search: ";
        //for(auto col : it){
            //cout << col << ' ';
        //}
        
        //cout << endl;
        if(binary_search(it.begin(), it.end(), target)){
            return true;
        }
    }
    return false;
}
void mergeTwoSortedArray(vector<int>& v1, vector<int>& v2, vector<int>& v3){
    v3.clear();
    int i = 0;
    int j = 0;
    int k = 0;

    //cout << "Merge" <<endl;
    //cout << "arr: ";
    //for(auto it : v1)
    //cout << it << ' ';
    //cout << endl;
    //cout << "_arr: ";
    //for(auto it : v2)
    //cout << it << ' ';
    //cout << endl;

    while(i < v1.size() && j < v2.size()){
        if(v1[i] < v2[j])
            v3.push_back(v1[i++]);
        else
            v3.push_back(v2[j++]);
    }
    while(i < v1.size())
        v3.push_back(v1[i++]);
    while(j < v2.size())
        v3.push_back(v2[j++]);
    v1.clear();
    v2.clear();
}


int main(){
    arrayOfSortedArray t;
    unsigned int seed = 1 + 100*1;
    mt19937 gen(seed);
    uniform_int_distribution<> r_val(minValue,maxValue);
    int n = 1 << k;
    vector<int> beSearched(SearchSize);
    for(int i = 0; i < SearchSize; ++i)
        beSearched.push_back(r_val(gen));
    //cout << 1;
    for(int i = 0; i < 1 << 23; ++i){
        t.insert(i);
    }
    for(auto &it : beSearched){
        if(ds.search(it)){
            cout << it << endl;

        }
    }
    //vector<int> it = {1,2,3,4,5};
    //cout << binary_search(it.begin(), it.end(), 5);
    //for(auto row : t._arr){
    //for(auto col : row){
    //cout << col << ' ';
    //}
    //cout << "size = "<< row.capacity() <<endl;
    //}
    //vector<int> v1 = {1,3,5,7,9};
    //vector<int> v2 = {2,4,6,8,10};
    //vector<int> out(10);
    //out.clear();
    //mergeTwoSortedArray(v1, v2, out);
    //for(auto &it : out)
    //cout << it << ' ' ;
    //cout << endl;

}


