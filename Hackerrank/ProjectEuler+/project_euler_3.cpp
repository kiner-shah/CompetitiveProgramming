// Largest prime factor
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*vector<long long int> sieve_of_eratosthenes(long int lim) {
    bool *isprime=new bool[lim];
    vector<long long int> primes;
    fill(isprime, isprime + lim, true);
    isprime[0] = isprime[1] = false;
    primes.push_back(2);
    for(int i = 4; i <= lim; i += 2) isprime[i] = false;
    for(int i = 3; i <= lim ; i += 2) {
        if(isprime[i]) {
            primes.push_back(i);
            for(int j = 3; j * i < lim; j += 2) isprime[j * i] = false;
        }
    }
    return primes;
}*/
int main() {
    int t;
    cin >> t;
    while(t-- > 0) {
        long long int n, e, cnt = 2;
        cin >> n; e = n;
        while(e > 1) {
            if(e % cnt == 0) e /= cnt;
            else if(cnt == 2) cnt++;
            else cnt += 2;
            if(cnt > sqrt(n)) break;
        }
        if(e == 1) cout << cnt << endl;
        else cout << e << endl;
    }
    return 0;
}
