#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>

using namespace std;

template <typename T>
void generate_power_set(const vector<T> & S) {

	for(int i = 0; i < (1 << S.size()); i++) {
		int x = i;
		while(x) {
			int target = log2(x & ~(x - 1));
			cout << S[target];
			if(x &= (x - 1)) {
				cout << ",";
			}
		}
		cout<<endl;
	}	
}

template <typename T>
void powerSetHelper(vector<T> & setVector, int indx, vector<T> & result) {
	if(result.empty() == false) {
		copy(result.cbegin(), result.cend() - 1, ostream_iterator<T>(cout, ","));
		cout << result.back();
	}
	cout << endl;
	
	for(int i = indx; i < setVector.size(); i++) {
		result.push_back(setVector[i]);
		powerSetHelper(setVector, i + 1, result);
		result.pop_back();
	}
}


template <typename T>
void generatePowerSet(vector<T> & setVector) {
	vector<T> result;
	powerSetHelper(setVector, 0, result);
}
