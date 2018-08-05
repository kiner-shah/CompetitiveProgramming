/*
 * File:   hackerrank_hourrank_29.cpp
 * Author: Kiner Shah
 *
 * Created on 02 August, 2018, 20:21 PM
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
template<typename T> inline T Max(T a, T b) { return (a > b ? a : b); }
template<typename T> inline bool comp(T a, T b) { return a < b; }
template<typename T> inline void swap(T &a, T &b) { T temp = a; a = b; b = temp; }
static LL gcd(LL a,LL b) { while(b>0) { b^=(a^=(b^=(a%=b))); } return a; }
static LL power(int a, int b) {
    if(b == 0) return 1;
    if(b == 1) return a;
    if(b%2 == 0) return power(a*a,b/2);
    else return a * power(a*a,(b-1)/2);
}
void customized_chess_board() {
    int t;
    cin >> t;
    while(t-- > 0) {
        int n, e;
        cin >> n;
        e = n;
        n *= n;
        int *a = new int[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            // cout << a[i] << " ";
        } // cout << endl;
        if(n % 2 == 0) {
            int f = a[0], ff = 1;
            for(int i = 1; i < n; i++) {
                if(i % e != 0 && a[i] == f) {
                    ff = 0; break;
                }
                else if(i % e == 0 && a[i] != f) {
                    ff = 0; break;
                }
                else f = a[i];
                // cout << f << " " ;
            }
            if(ff == 0) cout << "No\n";
            else cout << "Yes\n";
        }
        else {
            int f = a[0], ff = 1;
            for(int i = 1; i < n; i++) {
                if(a[i] == f) { ff = 0; break; }
                else f = a[i];
                // cout << f << " " ;
            }
            if(ff == 0) cout << "No\n";
            else cout << "Yes\n";
        }
        delete[] a;
    }
}
int main() {
   customized_chess_board(); // solution function for first problem
   return 0;
}