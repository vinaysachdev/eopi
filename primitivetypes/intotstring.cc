#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string intToString(int x) {
	string s;
	if(x == 0) return "0";
	short isNeg = 0;
	if(x < 0) {
		isNeg = 1;
		s += '-';
		x *= -1;
	}

	while(x > 0) {
		int r = x % 10;
		s += (48+r); 
		x /= 10;
	}
	reverse(s.begin() + isNeg, s.end());
	return s;
}

int main() {
	int num;
	cout << "Enter the num: ";
	cin >> num;
	cout << "Num to string: " << intToString(num) << endl;
	return 0;
}
