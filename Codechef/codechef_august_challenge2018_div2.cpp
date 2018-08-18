/*
 * File:   codechef_august_challenge2018_div2.cpp
 * Author: Kiner Shah
 *
 * Created on 03 August, 2018, 20:03 PM
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
static LL multiply(LL a, LL b, LL mod = 1000000007) {
    LL res = 0;
    while(b > 0) {
        if(b % 2 == 1) res = (res + a) % mod;
        a = (a + a) % mod;
        b /= 2;
    }
    return res;
}
static LL mpower(LL a, LL b, LL mod = 1000000007) {
    LL res = 1;
    while(b > 0) {
        if(b % 2 == 1) res = multiply(res, a, mod);
        a = multiply(a, a, mod);
        b /= 2;
    }
    return res;
}
void spell_bob() {
    int n;
    cin >> n;
    string cards[2];
    while(n-- > 0) {
        int cnt = 0, cntb = 2, cnto = 1;
        cin >> cards[0] >> cards[1];
        int o[3], b[3];
        o[0] = o[1] = o[2] = 0;
        b[0] = b[1] = b[2] = 0;
        for(int i = 0; i < 3; i++) {
            if(cards[0][i] == 'b') { b[i] = 1; /*cntb++;*/ }
            else if(cards[0][i] == 'o') { o[i] = 1; /*cnto++;*/ }
            if(cards[1][i] == 'o') { o[i] = 1; /*cnto++;*/ }
            else if(cards[1][i] == 'b') { b[i] = 1; /*cntb++;*/ }

            // if(o[i] == 1 && b[i] == 1) cnt++;
        }
        for(int i = 0; i < 3; i++) {
            if(cnto > 0 && o[i] == 1)
                cnto--;
            else if(cntb > 0 && b[i] == 1)
                cntb--;
        }
        if(cntb == 0 && cnto == 0)
            cout << "yes\n";
        else {
            cntb = 2; cnto = 1;
            for(int i = 0; i < 3; i++) {
                if(cntb > 0 && b[i] == 1)
                    cntb--;
                else if(cnto > 0 && o[i] == 1)
                    cnto--;
            }
            if(cntb == 0 && cnto == 0) cout << "yes\n";
            else cout << "no\n";
        }
    }
}
void sheokand_and_number() {
    /*int t; LL n;
    cin >> t;
    map<LL, LL> m;
    m[1] = 2; m[2] = 1; m[3] = 0; m[4] = 1;
    while(t-- > 0) {
        cin >> n;
        if(n == 1 || n == 2 || n == 3 || n == 4) {
            cout << m[n] << endl;
            continue;
        }
        if(m.find(n) != m.end()) {
            cout << m[n] << endl;
            continue;
        }
        int exp = (int) log2(n);
        LL val = n - (1 << exp);
        if(val > 0 && (val & (val - 1)) == 0) {
            cout << 0 << endl;
            m[n] = 0;
            continue;
        }
        LL minval;
        if(val == 0) minval = power(2, exp - 1);
        else minval = power(2, exp);
        LL maxval = power(2, exp + 1);
        LL c1, c2;
        // cout << "MAX: " << maxval << " MIN: " << minval << " ";
        for(LL j = n - 1; j >= minval; j--) {
            if(m.find(j) != m.end()) {
                c1 = m[j];
                break;
            }
            LL log2j = (LL) log2(j);
            LL m = j - (1 << log2j);
            if(m > 0 && (m & (m - 1)) == 0) {
                // cout << j << " ";
                c1 = n - j;
                break;
            }
        }
        for(LL j = n + 1; j <= maxval; j++) {
            // cout << "R1 " << j << " ";
            if(m.find(j) != m.end()) {
                // cout << "R2 ";
                c2 = m[j];
                break;
            }
            LL log2j = (LL) log2(j);
            LL m = (1 << (log2j + 1)) - j;
            if(m > 0 && (m & (m - 1)) == 0) {
                // cout << j << " ";
                c2 = j - n;
                break;
            }
        }
        cout << min(c1, c2) << endl;
    }*/
    // Editorial solution:
    vector<LL> good;
    for(int i = 0; i <= 30; i++) {
        for(int j = i + 1; j <= 30; j++) {
            LL val = (1LL << i) + (1LL << j);
            if(val <= 2000000000) good.push_back(val);
        }
    }
    int t, len = good.size(), n, min1;
    cin >> t;
    while(t-- > 0) {
        cin >> n; cout << n << " ";
        min1 = INT_MAX;
        for(int i = 0; i < len; i++) {
            int val = (good[i] - n) > 0 ? good[i] - n : n - good[i];
            if(min1 > val) min1 = val;
        }
        cout << min1 << endl;
    }
}
typedef struct ST {
    int sc, ns;
} SubTask;
typedef struct PROBC {
    pair<int , int> difficulty;
} ProbC;
bool sccomp(SubTask a, SubTask b) { return a.sc < b.sc; }
bool diffcomp(ProbC a, ProbC b) {
    if(a.difficulty.first < b.difficulty.first) return true;
    else if(a.difficulty.first > b.difficulty.first) return false;
    else return (a.difficulty.second < b.difficulty.second);
}
void problem_sort() {
    int p, s, x;
    cin >> p >> s;
    ProbC prob[p];
    SubTask st[s];
    for(int i = 0; i < p; i++) {
        for(int j = 0; j < s; j++) {
            cin >> x;
            st[j].sc = x;
        }
        for(int j = 0; j < s; j++) {
            cin >> x;
            st[j].ns = x;
        }
        sort(st, st + s, sccomp);
        int cnt = 0;
        for(int j = 0; j < s - 1; j++) {
            if(st[j].ns > st[j + 1].ns) cnt++;
        }
        prob[i].difficulty = make_pair(cnt, i + 1);
//        cout << prob[i].difficulty.first << " " << prob[i].difficulty.second << endl;
//        for(SubTask s : prob[i].v) cout << s.sc << " " << s.ns << endl;
    }
    sort(prob, prob + p, diffcomp);
    for(int i = 0; i < p; i++) cout << prob[i].difficulty.second << endl;
}
void modular_gcd() {
    /*int t; LL a, b, n;
    cin >> t;
    map<LL, LL> m;
    while(t-- > 0) {
        cin >> a >> b >> n;
        LL an, bn;
        if(m.find(a) != m.end()) an = m[a];
        else { an = mpower(a, n, 1000000007); m.insert(make_pair(a, an)); }
        if(m.find(b) != m.end()) bn = m[b];
        else { bn = mpower(b, n, 1000000007); m.insert(make_pair(b, bn)); }
        LL modsum = (an + bn) % 1000000007;
        LL diff = (abs(a - b)) % 1000000007;
        cout << gcd(modsum, diff) % 1000000007 << endl;
    }*/
    // Editorial solution:
    // Use property: gcd(x, y) = gcd(x % y, y)
    int t; LL a, b, n, ans;
    cin >> t;
    while(t-- > 0) {
        cin >> a >> b >> n;
        if(a == b) ans = (mpower(a, n) + mpower(b, n)) % 1000000007;
        else ans = gcd(mpower(a, n, (a - b)) + mpower(b, n, (a - b)), (a - b)) % (a - b);
        cout << gcd(ans, (a - b)) << endl;
    }
}
int main() {
//    spell_bob();
//    sheokand_and_number();
//    problem_sort();
//    modular_gcd();
    return 0;
}