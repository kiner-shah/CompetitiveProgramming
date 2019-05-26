/*
 * File:   codeforces_round_524_div2.cpp
 * Author: Kiner Shah
 *
 * Created on 24 November, 2018, 12:51 PM
 */

// https://codeforces.com/blog/entry/63375  (alternate sites)
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

void petya_and_origami() {
    LL n, k;
    cin >> n >> k;
    const LL r = 2 * n, g = 5 * n, b = 8 * n;
    LL book_r = (r % k == 0 ? r / k : r / k + 1);
    LL book_g = (g % k == 0 ? g / k : g / k + 1);
    LL book_b = (b % k == 0 ? b / k : b / k + 1);
//    cout << book_r << " " << book_g << " " << book_b << endl;
    cout << book_r + book_g + book_b;
}
void margarite_and_the_best_present() {
    int q;
    cin >> q;
    LL l, r;
    while (q-- > 0) {
        cin >> l >> r;
        if (l == r) cout << (l % 2 == 0 ? l : -l) << endl;
        else if (l % 2 == 1) {
            if (r % 2 == 1) {
                int n_o = (r - l) / 2 + 1;
                int sum_o = (n_o * (l + r)) / 2;    // AP series with d = 2, for odd values
                int n_e = (r - 1 - l - 1) / 2 + 1;
                int sum_e = (n_e * (l + 1 + r - 1)) / 2;    // for even values
                cout << -sum_o + sum_e << endl;
            }
            else {
                int n_o = (r - 1 - l) / 2 + 1;
                int sum_o = (n_o * (l + r - 1)) / 2;    // AP series with d = 2, for odd values
                int n_e = (r - l - 1) / 2 + 1;
                int sum_e = (n_e * (l + 1 + r)) / 2;    // for even values
                cout << -sum_o + sum_e << endl;
            }
        }
        else {
            if (r % 2 == 1) {
                int n_o = (r - l - 1) / 2 + 1;
                int sum_o = (n_o * (l + 1 + r)) / 2;    // AP series with d = 2, for odd values
                int n_e = (r - 1 - l) / 2 + 1;
                int sum_e = (n_e * (l + r - 1)) / 2;    // for even values
                cout << -sum_o + sum_e << endl;
            }
            else {
                int n_o = (r - 1 - l - 1) / 2 + 1;
                int sum_o = (n_o * (l + 1 + r - 1)) / 2;    // AP series with d = 2, for odd values
                int n_e = (r - l) / 2 + 1;
                int sum_e = (n_e * (l + r)) / 2;    // for even values
                cout << -sum_o + sum_e << endl;
            }
        }
    }
}
int main() {
//    petya_and_origami();
//    margarite_and_the_best_present();
    return 0;
}
