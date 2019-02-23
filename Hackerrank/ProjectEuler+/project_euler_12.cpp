// Highly divisible triangular number
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
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t, n;
    vector<long long int> primes = sieve_of_eratosthenes(10000);
    vector<long long int> sq_primes; // cout << primes[0] << " " << primes[1] << endl;
    long int len_vec = primes.size(); // cout << len_vec << endl;
    for(long int i = 0; i < len_vec; i++) sq_primes.push_back(primes[i] * primes[i]);
    cin >> t;
    while(t-- > 0) {
        cin >> n;
        for(int i = 1; ; i++) {
            long long int triangular_series_value = (i * (i + 1)) / 2;
            long long int temp = triangular_series_value;
            long long int p = 1;
            //cout << triangular_series_value << " ";
            for(long int j = 0; j < len_vec; j++) {
                long long int pp = primes[j];
                //cout << pp << " ";
                if(pp * pp * pp > triangular_series_value) { // Using counting divisors algorithm in O(n^(1/3)) time rather than O(n^(1/2))
                    break;
                }
                int count = 1;
                while(triangular_series_value % pp == 0) { triangular_series_value /= pp; count++; }
                p *= count; //cout << p << " ";
            }
            if(find(primes.begin(), primes.end(), triangular_series_value) != primes.end()) p *= 2;
            else if(find(sq_primes.begin(), sq_primes.end(), triangular_series_value) != sq_primes.end()) p *= 3;
            else if(triangular_series_value != 1) p *= 4;
            // cout << p << " " << (find(primes.begin(), primes.end(), triangular_series_value) != primes.end()) << " "
            //     << (find(sq_primes.begin(), sq_primes.end(), triangular_series_value) != sq_primes.end()) << " "
            //     << (triangular_series_value != 1) << endl;
            //cout << triangular_series_value << " " << p << "\n";
            if(p > n) { cout << temp << endl; break; }
        }
    }
    return 0;
}
