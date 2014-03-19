#include <iostream>
#include <vector>

using namespace std;
// generate all primes upto N using Sieve of Eratosthenes with little optimization
// algorithm sees only odd numbers
// source http://programmingpraxis.com/programming-with-prime-numbers/
void generatePrimes(int n) {
    int noOfPrimes = (n - 1)/2;
    vector<unsigned> primes;
    primes.push_back(2);
    vector<bool> primeNumbers(noOfPrimes, true);
    
    for(int i = 0; i < noOfPrimes; ++i) {
        if(primeNumbers[i] == true) {
            int p = 2*i+3;
            primes.push_back(p);
            int j = 2*i*i + 6*i + 3;
            while(j < noOfPrimes) {
                primeNumbers[j] = false;
                j = j + 2*i + 3;
            }
        }
    }
    for(int k = 0; k < primes.size(); k++) {
        cout << primes[k] << " ";
    }
    cout << '\n';
}

int main() {
    int n = 0;
    cout << "Enter the no upto which you want to generate prime numbers: ";
    cin >> n;
    generatePrimes(n);
    return 0;
}
