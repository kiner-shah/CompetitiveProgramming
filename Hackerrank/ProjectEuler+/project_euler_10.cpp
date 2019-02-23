// Summation of primes
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<long long int> sieve_of_eratosthenes(long int lim) {
    bool *isprime=new bool[lim];
    vector<long long int> primes;
    fill(isprime, isprime + lim, true);
    isprime[0] = isprime[1] = false;
    primes.push_back(2);
    for(long int i = 4; i <= lim; i += 2) isprime[i] = false;
    for(long int i = 3; i <= lim ; i += 2) {
        if(isprime[i]) {
            primes.push_back(i);
            for(long int j = 3; j * i < lim; j += 2) isprime[j * i] = false;
        }
    }
    return primes;
}

int main() {
    vector<long long int> primes = sieve_of_eratosthenes(1000001);   
    long int vec_size = primes.size();
    int t;
    cin >> t;
    while(t-- > 0) {
        long int n;
        cin >> n;
        long long int sum = 0;
        for(long int i = 0; i < vec_size; i++) {
            if(primes[i] <= n) sum += primes[i];
            else break;
        }
        cout << sum << endl;
    }
    return 0;
}
