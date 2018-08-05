/*
 * File:   codeforces_round_501_div3.cpp
 * Author: Kiner Shah
 *
 * Created on 31 July, 2018, 19:55 PM
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
template<typename T> inline T Max(T a, T b) { return (a > b ? a : b); }
template<typename T> inline bool comp(T a, T b) { return a < b; }
static LL gcd(LL a,LL b) { while(b>0) { b^=(a^=(b^=(a%=b))); } return a; }
static LL power(int a, int b) {
    if(b == 0) return 1;
    if(b == 1) return a;
    if(b%2 == 0) return power(a*a,b/2);
    else return a * power(a*a,(b-1)/2);
}
static void swap(char &a, char &b) { char temp = a; a = b; b = temp; }
void points_in_segments() {
    int n, m, l, r;
    cin >> n >> m;
    int f[m + 1];
    fill(f, f + m + 1, 0);
    for(int i = 0; i < n; i++) {
        cin >> l >> r;
        for(int j = l; j <= r; j++) {
            if(!f[j]) f[j] = 1;
        }
    }
    int cnt = 0;
    vector<int> v;
    for(int i = 1; i <= m; i++) {
//        cout << f[i] << " ";
        if(!f[i]) { cnt++; v.push_back(i); }
    } // cout << endl;
    cout << cnt << endl;
    for(int x : v) cout << x << " ";
}
void obtaining_a_string() {
    int n;
    cin >> n;
    char a[n + 1], b[n + 1];
    cin >> a >> b;
    int cnt = 0;
    vector<int> v;
    bool f = false;
    while(true) {
        for(int i = 0; i < n; i++) {
            int j; bool ff = false;
            for(j = i; j < n; j++) {
//                cout << a[j] << " " << b[i] << " " << i << " " << j << endl;
                if(a[j] == b[i] && i != j) {
                    swap(a[j], a[j - 1]);
                    v.push_back(j);
                    break;
                }
                else if(a[j] == b[i]) { ff = true;  break; }
            }
//            cout << a << " " << b << endl;
            if(!ff && j < n) break;
        }
        cnt++;
        if(cnt == 10001) { f = true; break; }
        if(strcmp(a, b) == 0) break;
    }
    if(f) cout << "-1\n";
    else {
        cout << v.size() << endl;
        for(int x : v) cout << x << " ";
    }
}
typedef struct PROB_C { LL c, u; } ProbC;
bool ProbCCompare(ProbC a, ProbC b) {
    if(a.u  - a.c > b.u - b.c) return true;
    // else if(a.u - a.c == b.u - b.c && a.u > b.u) return true;
    else return false;
}
void songs_compression() {
    int n; LL m, sum = 0, cnt = 0;
    cin >> n >> m;
    ProbC *p = new ProbC[n];
    for(int i = 0; i < n; i++) {
        cin >> p[i].u >> p[i].c;
        sum += p[i].u;
    }
    sort(p, p + n, ProbCCompare);
    for(int i = 0; i < n; i++) {
        if(sum > m) {
            sum = sum - p[i].u + p[i].c;
            cnt++;
        }
        else { break; }
    }
    if(sum > m) cnt = -1;
    cout << cnt << endl;
    delete[] p;
}
int main() {
//    points_in_segments(); // Problem A
//    obtaining_a_string(); // Problem B
//    songs_compression(); // Problem C
   return 0;
}