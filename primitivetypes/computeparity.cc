#include <iostream>

// return 1 if number n has odd no of 1 bit or 0 otherwise
short computeParity(unsigned long n) {
	short result = 0;
	while(n != 0) {
		result ^= (n & 1); //odd times XOR to 1 return 1 and even times XOR returns 0
		n >>= 1;
	}
	return result;
}

int main() {
	unsigned long n = 0;
	std::cout<< "Enter the number: ";
	while(std::cin >> n) {
	if(computeParity(n))
		std::cout<< n << " has odd parity\n";
	else
		std::cout<< n << " has even parity\n";
	std::cout<< "Enter the number: ";
	}
	return 0;
}
