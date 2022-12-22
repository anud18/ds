#include<vector>
#include<cstdlib>
#include<iostream>

using namespace std;

void Merge(const vector<int>& V1, const vector<int>& V2, vector<int>& out) {

};

bool BinarySearch(const vector<int>& V, int x) {
    return false;

};

class ASA {
public:
	vector<vector<int>> D, _D;
	ASA(): D(1), _D(1) {};

	void Insert(int x) {
		_D[0].push_back(x);
		for (int level = 0; ; level++) {
			if (D[level].empty()) {
				//copy _D[level] to D[level] 
				return;
			}
			else {
                Merge(D[level], _D[level], )
                //merge D[level] & _D[level] and save to _D[level+1]
			}
		}
	};

	void Print() {
	};

	bool Search(int x) {
        return false;
	};
};


int main() {
	vector<int> V1({ 1,3,5,7,9});
	vector<int> V2({ 2,4,6,8,10});
	vector<int> out(10);

	Merge(V1, V2, out);

	for(int i = 0; i <10; i++){
		cout << out[i] << " ";
	}
	cout << endl;
	system("pause");


	ASA A;
	for (int i = 0; i < 16; i++) {
		A.Insert(i);
		A.Print();
		system("pause");
	}

}
