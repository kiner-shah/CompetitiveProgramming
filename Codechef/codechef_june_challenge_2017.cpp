#include <bits/stdc++.h>
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
void a_good_set() {
	int t, n;
    cin>>t;
    int b[6] = {1, 25, 49, 81, 9, 121};
    int a[94] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499};
    while(t-- > 0) {
        cin>>n;
        if(n <= 94) for(int i = 0; i < n; i++) cout<<a[i]<<" ";
        else {
            for(int i = 0; i < 94; i++) cout<<a[i]<<" ";
            n -= 94;
            for(int i = 0; i < n; i++) cout<<b[i]<<" ";
        }
        cout<<endl;
    }
}
void xenny_and_coin_rankings() {
	int t;
    unsigned long long x, y, h, v;
    cin>>t;
    while(t-- > 0) {
        cin>>x>>y;
        /*while(y-- > 0) {
            v += c; c++;
        }
        while(x-- > 0) {
            h += d; d++;
        }
        h += (c - 1) * e;
        cout<<h + v + 1<<endl;*/
        v = (y * (y + 1)) / 2;
        h = (x * (x + 1)) / 2 + x + x * y;
        cout<<v + h + 1<<endl;
    }
}
void chef_and_the_feast() {
	int t, i, n;
    cin>>t;
    while(t-- > 0) {
        cin>>n; int count = 0;
        LL a[n], sum = 0, happiness = 0;
        for(i = 0; i < n; i++) {
            cin>>a[i];
            if(a[i] < 0) {
                if(count > 0) { happiness += sum * count; count = 0; sum = 0; }
                happiness += a[i];
            }
            else { sum += a[i]; count++; }
        }
        happiness += sum * count;
        cout<<happiness<<endl;
    }
}
int main() {
    // your code goes here 
  	// a_good_set();
	// xenny_and_coin_rankings();
	// chef_and_the_feast();	// partially solved for 30 pts
    return 0;
}
