#ifndef _ASA_H_
#define _ASA_H_

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
void mergeTwoSortedArray(vector<int>& v1, vector<int>& v2, vector<int>& v3);

class arrayOfSortedArray{
    public:
        arrayOfSortedArray();
        void insert(int element);//插入元素
        bool search(int target);//尋找元素
        void merge(int curLevel);
    public:
        vector<vector<int>> arr;
        vector<vector<int>> _arr;
};
arrayOfSortedArray::arrayOfSortedArray(){
    arr.reserve(32);
    _arr.reserve(32);
    //將一個capacity為1，size為0的一維int陣列放進arr
    arr.push_back(vector<int>(1));
    arr[0].clear();
    //將一個capacity為1，size為0的一維int陣列放進_arr
    _arr.push_back(vector<int>(1));
    _arr[0].clear();
}
void arrayOfSortedArray::insert(int element){
    //將要被新增的資料暫時放進_arr[0][0]
    _arr[0].push_back(element);
    //如果arr[0]為空則將_arr[0][0]放進去arr[0][0]
    //並清空_arr[0]
    if(arr[0].empty()){
        arr[0].push_back( _arr[0][0]);
        _arr[0].clear();
    }
    //如果arr[0]滿了則呼叫merge函數
    else{
        merge(0);
    }
}
void arrayOfSortedArray::merge(int curLevel){
    int nextLevel = curLevel + 1;
    //如果nextLevel等於arr的size則新增一個大小為2^nextLevel的陣列放進去arr[nextLevel]和_arr[nextLevel]
    //並將arr[curLevel]和_arr[curLevel] 透過mergeTwoSortedArray將兩者內容合併放進去arr[nextLevel]
    //並將arr[curLevel]及_arr[curLevel]清空
    if(nextLevel == arr.size()){
        arr.push_back(vector<int>(1 << nextLevel));
        _arr.push_back( vector<int>(1 << nextLevel));
        mergeTwoSortedArray(arr[curLevel], _arr[curLevel], arr[nextLevel]);
    }
    //如果arr[nextLevel]為空則將arr[curLevel]和_arr[curLevel] 透過mergeTwoSortedArray將兩者內容合併放進去arr[nextLevel]
    //並將arr[curLevel]及_arr[curLevel]清空
    else if(arr[nextLevel].empty()){
        mergeTwoSortedArray(arr[curLevel], _arr[curLevel], arr[nextLevel]);
    }
    //如果arr[nextLevel]滿了則將arr[curLevel]和_arr[curLevel] 透過mergeTwoSortedArray將兩者內容合併放進去_arr[nextLevel]
    //並將arr[curLevel]及_arr[curLevel]清空
    //接著再呼叫merge(nextLevel)
    else{
        mergeTwoSortedArray(arr[curLevel], _arr[curLevel], _arr[nextLevel]);
        merge(nextLevel);
    }
}
bool arrayOfSortedArray::search(int target){
    //以binary search查找arr中每一個陣列是否有想要被target的元素
    //如果有找到回傳true，到最後都沒有找到則回傳false
    for(auto &it : arr){
        if(it.empty()){
            continue;
        }
        if(binary_search(it.begin(), it.end(), target)){
            return true;
        }
    }
    return false;
}
void mergeTwoSortedArray(vector<int>& v1, vector<int>& v2, vector<int>& v3){
    //此函示將兩個排序好的陣列v1 v2合併到v3
    //合併完後將v1 v2清空
    v3.clear();
    int i = 0;
    int j = 0;
    int k = 0;
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
#endif
