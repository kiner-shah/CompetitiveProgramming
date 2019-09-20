#include <iostream>
#include <cstdio>
#include <cmath>
#define MOD 1000000007
using namespace std;
typedef long long LL;
template<typename T> inline T Max(T a, T b) { return (a > b ? a : b); }
template<typename T> inline bool comp(T a, T b) { return a < b; }
inline LL gcd(LL a,LL b) { while(b>0) { b^=(a^=(b^=(a%=b))); } return a; }
inline LL power(int a, int b) { if(b == 0) return 1; if(b == 1) return a; if(b%2 == 0) return power(a*a,b/2); else return a * power(a*a,(b-1)/2); }
LL mpower(LL a, LL b) {
    if(b == 0) return 1;
    else if(b == 1) return a;
    else if(b%2 == 0) {
        LL bb = mpower(a,b/2) * mpower(a,b/2);
        if(bb >= MOD) return bb % MOD;
        else return bb;
    }
    else {
        LL bb = a * mpower(a,b/2) * mpower(a,b/2);
        if(bb >= MOD) return bb % MOD;
        else return bb;
    }
}
void bond_and_fond() {
	int t;
    unsigned long long n;
    cin>>t;
    while(t-- > 0) {
        cin>>n;
        int val = (double) (log(n) / log(2));
        unsigned long long a = (unsigned long long) (1 << val);
        unsigned long long b = (unsigned long long) (1 << (val + 1));
        unsigned long long x = n - a, y = b - n;
        if(x < y) cout<<x<<endl;
        else cout<<y<<endl;
    }
}
int main() {
    // your code goes here
    // bond_and_fond(); 	// partially solved for 30 pts
    return 0;
}
