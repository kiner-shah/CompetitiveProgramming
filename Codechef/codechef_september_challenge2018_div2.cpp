/*
 * File:   codechef_september_challenge2018_div2.cpp
 * Author: Kiner Shah
 *
 * Created on 08 September, 2018, 11:54 AM
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
template<typename T> inline T Max(T a, T b) { return (a > b ? a : b); }
template<typename T> inline bool comp(T a, T b) { return a < b; }
static LL gcd(LL a,LL b) { while(b>0) { b^=(a^=(b^=(a%=b))); } return a; }
static LL power(LL a, LL b) {
    if(b == 0) return 1;
    if(b == 1) return a;
    if(b%2 == 0) return power(a*a,b/2);
    else return a * power(a*a,(b-1)/2);
}
static void swap(char &a, char &b) { char temp = a; a = b; b = temp; }
void magician_vs_chef() {
    int t, n, x, s, a, b, curpos;
    cin >> t;
    while(t-- > 0) {
        cin >> n >> x >> s;
        curpos = x;
        // cout << n << " " << x << " " << s << endl;
        while(s-- > 0) {
            cin >> a >> b;
            if(curpos == a) curpos = b;
            else if(curpos == b) curpos = a;
        }
        cout << curpos << endl;
    }
}
void chef_and_adventures() {
    int t; LL n, m, x, y;
    cin >> t;
    while(t-- > 0) {
        cin >> n >> m >> x >> y;
        if(x == 1 && y == 1
                || n == 1 && m == 1
                || n == 1 && y == 1
                || m == 1 && x == 1) cout << "Chefirnemo" << endl;
        else if(n == 1 && m > 1) {
            if((m - 1) % y == 0) cout << "Chefirnemo" << endl;
            else cout << "Pofik" << endl;
        }
        else if(n > 1 && m == 1) {
            if((n - 1) % x == 0) cout << "Chefirnemo" << endl;
            else cout << "Pofik" << endl;
        }
        else {
            LL N, M, N_minus_1, M_minus_1;
            N = (n - 1) % x;
            M = (m - 1) % y;
            N_minus_1 = (n - 2) % x;
            M_minus_1 = (m - 2) % y;
            if(N == 0 && M == 0) cout << "Chefirnemo" << endl;
            else if(N_minus_1 == 0 && M_minus_1 == 0) cout << "Chefirnemo" << endl;
            else cout << "Pofik" << endl;
        }
    }
}
int main() {
//  magician_vs_chef();
//	chef_and_adventures();

    return 0;
}