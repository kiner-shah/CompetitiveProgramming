/*
 * File:   codechef_november_challenge2018_div2.cpp
 * Author: Kiner Shah
 *
 * Created on 04 November, 2018, 12:11 PM
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
template<typename T> inline T Max(T a, T b) { return (a > b ? a : b); }
template<typename T> inline bool comp(T a, T b) { return a < b; }
static LL gcd(LL a,LL b) { while (b > 0) { b ^= (a ^= (b ^= (a %= b))); } return a; }
static LL power(LL a, LL b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    if (b%2 == 0) return power(a*a,b/2);
    else return a * power(a*a,(b-1)/2);
}
static void swap(char &a, char &b) { char temp = a; a = b; b = temp; }
static LL multiply(LL a, LL b, LL mod = 1000000007) {
    LL res = 0;
    while (b > 0) {
        if (b % 2 == 1) res = (res + a) % mod;
        a = (a + a) % mod;
        b /= 2;
    }
    return res;
}
static LL mpower(LL a, LL b, LL mod = 1000000007) {
    LL res = 1;
    while (b > 0) {
        if (b % 2 == 1) res = multiply(res, a, mod);
        a = multiply(a, a, mod);
        b /= 2;
    }
    return res;
}
void chef_and_difficult_contests() {
    int t;
    long int a, b;
    cin >> t;
    // a + m * d + n * (d - 1) = b + m * (d - 1) + n * d
    // Will never be NO, answer always exists
    while (t-- > 0) {
        cin >> a >> b;
        if (a == b) cout << "YES" << endl;
        else cout << "YES" << endl;
    }
}
void chef_and_happiness() {
    int t, n;
    cin >> t;
    const string yes_str = "Truly Happy";
    const string no_str = "Poor Chef";
    while (t-- > 0) {
        cin >> n;
        vector<int> v(n);
        map<int, vector<int> > m;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            if (m.find(v[i]) != m.end())
                m[v[i]].push_back(i + 1);
            else {
                vector<int> v1;
                v1.push_back(i + 1);
                m.insert(make_pair(v[i], v1));
            }
        }
        bool ans_found = false;
        for (pair<int, vector<int> > p : m) {
            int key = p.first;
            vector<int> v1 = p.second;
            if (m[key].size() >= 2) {
                int count = 0;
                for (int val : v1) {
                    if (m.find(val) != m.end()) count++;
                    if (count == 2) { ans_found = true; break; }
                }
                if (ans_found)
                    break;
            }
        }
        if (ans_found)
            cout << yes_str << endl;
        else
            cout << no_str << endl;

    }
}
void chef_and_ridges() {
    int dp[25][2];  // col1 = numerator, col2 = denominator
    dp[0][0] = 1; dp[0][1] = 2;
    dp[1][0] = 1; dp[1][1] = 4;
    dp[2][0] = 3; dp[2][1] = 8;
    for (int i = 3; i < 25; i++) {
        dp[i][0] = dp[i - 1][0] + 2 * dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] * 2;
    }
    int t, n;
    cin >> t;
    while (t-- > 0) {
        cin >> n;
        cout << dp[n - 1][0] << " " << dp[n - 1][1] << " ";
    }
}
void appy_loves_one() {
    int n, q, k;
    cin >> n >> q >> k;
    int *a = new int[n];
    deque<int> v;
    int count = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1)
            count++;
        else if (count > 0) {
            v.push_back(count);
            v.push_back(0);
            count = 0;
        }
        else v.push_back(0);
    }
    if (count > 0) {
        v.push_back(count);
    }
//    for (int i = 0; i < n; i++)
//        cout << a[i] << " ";
//    cout << endl;
//    for (int x : v)
//        cout << x << " ";
//    cout << endl;

    string queries;
    cin >> queries;
    for (int i = 0; i < q; i++) {
        if (queries[i] == '?') {    // longest contiguous subsequence of length at most k
            int max_len = -1;
            for (int x : v) {   // Optimization required here
                if (x > 0 && x > max_len)
                    max_len = x;
            }
            cout << (max_len >= k ? k : max_len) << endl;
        }
        else if (queries[i] == '!') {   // right shift
//            int temp = a[n - 1];
//            if (a[n - 1] == 1) {
            size_t v_sz = v.size() - 1;
            if (v[v_sz] > 0) {
                v[v_sz]--;
                if (v[v_sz] == 0) {
//                    v.erase(v.begin() + v_sz);
                    v.pop_back();
                }
                if (v[0] == 0) {
//                    v.insert(v.begin(), 1);
                    v.push_front(1);
                }
                else
                    v[0]++;
            }
            else {
//                v.erase(v.begin() + v_sz);
                v.pop_back();
//                v.insert(v.begin(), 0);
                v.push_front(0);
            }
//            memcpy(a + 1, a, sizeof(int) * (n - 1));
//            a[0] = temp;
//            for (int i = 0; i < n; i++)
//                cout << a[i] << " ";
//            cout << endl;
//            for (int x : v)
//                cout << x << " ";
//            cout << endl;
        }
    }
    delete[] a;
    a = NULL;
}
int main() {
//    chef_and_difficult_contests();
//    chef_and_happiness();
//    chef_and_ridges();
//    appy_loves_one();   // Partially solved for 30 pts
   return 0;
}