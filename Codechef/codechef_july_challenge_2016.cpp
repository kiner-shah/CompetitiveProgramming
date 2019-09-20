#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
template<typename T> inline T Max(T a, T b) { return (a > b ? a : b); }
template<typename T> inline bool comp(T a, T b) { return a < b; }
LL gcd(LL a,LL b) { while(b>0) { b^=(a^=(b^=(a%=b))); } return a; }
LL power(int a, int b) {
    if(b == 0) return 1;
    if(b == 1) return a;
    if(b%2 == 0) return power(a*a,b/2);
    else return a * power(a*a,(b-1)/2);
}
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
void andrash_and_stipendium() {
	int t,n,i;
    cin>>t;
    while(t-- > 0) {
    	cin>>n;
    	int a[n];
    	long int sum = 0;
    	bool five = false, two = false;
    	for(i = 0; i < n; i++) {
    		cin>>a[i];
    		sum += a[i];
    		if(a[i] == 5) five = true;
    		else if(a[i] == 2) two = true;
    	}
    	if(two) cout<<"No\n";
    	else if(five) {
    		double avg = (double) sum / n;
    		if(avg >= 4.0) cout<<"Yes\n";
    		else cout<<"No\n";
    	}
    	else cout<<"No\n";
    }
}
int main() {
    // your code goes here  
    // andrash_and_stipendium();
    return 0;
}
