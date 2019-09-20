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

void naive_chef() {
	int t, n, a, b;
	int x[10000];
	int c[10000];
    cin >> t;
    while(t-- > 0) {
        cin >> n >> a >> b;
        fill(c, c + 10000, 0);
        fill(x, x + 10000, 0);
        for(int i = 0; i < n; i++) {
            cin >> x[i];
            c[x[i]]++;
        }
        double proba = (double) c[a] / n;
        double probb = (double) c[b] / n;
        //cout << c[a] << " " << proba << " " << c[b] << " " << probb << endl;
        printf("%.6lf\n", proba * probb);
        //cout << proba * probb << endl;
    }
}
int main() {
    // naive_chef();
    return 0;
}
