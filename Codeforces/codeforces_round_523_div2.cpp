/*
 * File:   codeforces_round_523_div2.cpp
 * Author: Kiner Shah
 *
 * Created on 22 November, 2018, 20:27 PM
 */

// https://codeforces.com/blog/entry/63375  (alternate sites))
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
template<typename T> inline T Max(T a, T b) { return (a > b ? a : b); }
template<typename T> inline bool comp(T a, T b) { return a < b; }
template<typename T> inline void swap_vals(T& a, T& b) { T temp = a; a = b; b = temp; }
static LL gcd(LL a,LL b) { while(b>0) { b^=(a^=(b^=(a%=b))); } return a; }
static LL power(int a, int b) {
    if(b == 0) return 1;
    if(b == 1) return a;
    if(b%2 == 0) return power(a*a,b/2);
    else return a * power(a*a,(b-1)/2);
}

void coins() {
    int n;
    LL S;
    cin >> n >> S;
    if (S % n > 0) cout << S / n + 1;
    else cout << S / n;
}
void views_matter() {
    /*
    int n;
    LL m;
    cin >> n >> m;
    vector<LL> v(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        LL min = 1000000007;
        for (int j = 0; j < n; j++) {
            if (v[j] < min) min = v[j];
        }
        for (int j = 0; j < n; j++) {
            if (v[j] != min) { v[j]--; ans++; }
        }
    }
    cout << ans;
     */

    // Editorial solution
    int n;
    LL m;
    cin >> n >> m;
    vector<LL> v(n);
    int ans = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < n; i++) {
        if (v[i] > v[i - 1])
            ans += v[i - 1];
    }
}
int main() {
   // coins();
   // views_matter(); // failed test cases - referred editorial solution
   return 0;
}