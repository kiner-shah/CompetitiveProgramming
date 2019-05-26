/*
 * File:   google_codejam_2019_qr.cpp
 * Author: Kiner Shah
 *
 * Created on 06 April, 2019, 12.44 PM
 */
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <climits>
using namespace std;
void foregone_solution() {
    int t;
    string n;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n;
        size_t len = n.length();
        stringstream x, y;
        string x_str, y_str;
        for (size_t j = 0; j < len; j++) {
            if (n[j] == '4') {
                x << '2';
                y << '2';
            }
            else {
                x << n[j];
                y << '0';
            }
        }
        x_str = x.str();
        y_str = y.str();
        int cnt = 0;
        for (int i = 0; i < len && y_str[i] == '0'; cnt++, i++);
        y_str = y_str.substr(cnt);
        cout << "Case #" << i << ": " << x_str << " " << y_str << endl;
    }
}
void you_can_go_your_own_way() {
    int t;
    int n;
    string l;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n >> l;
        stringstream ans;
        int two_n_minus_2 = 2 * n - 2;
        for (int i = 0; i < two_n_minus_2; i++) {
            if (l[i] == 'S') ans << 'E';
            else if (l[i] == 'E') ans << 'S';
        }
        cout << "Case #" << i << ": " << ans.str() << endl;
    }
}
//vector<int> get_primes(int n) {
//    vector<int> primes;
//    bool *flag = new bool[n];
//    memset(flag, true, sizeof(bool) * n);
//    flag[0] = flag[1] = false;
//    flag[2] = true;
//    primes.push_back(2);
//    for (int i = 4; i <= n; i += 2) flag[i] = false;
//    for (int i = 3; i <= n; i += 2) {
//        if (flag[i]) {
//            primes.push_back(i);
//            for (int j = 3; j * i < n; j += 2) {
//                flag[j * i] = false;
//            }
//        }
//    }
//    delete[] flag;
//    flag = NULL;
//    return primes;
//}
//int get_first_factor(uint64_t val, vector<int>& primes) {
//    if (val % 2 == 0) return 2;
//    size_t sz = primes.size();
//    for (size_t i = 0; i < sz; i++) {
//        if (val % primes[i] == 0) {
//            return primes[i];
//        }
//    }
//    return -1;
//}
typedef unsigned long long ULL;
static ULL gcd(ULL a,ULL b) { while(b>0) { b^=(a^=(b^=(a%=b))); } return a; }
void cryptopangrams() {
    int t, n, l;
    cin >> t;
//    vector<int> primes = get_primes(217286);
    for (int i = 1; i <= t; i++) {
        cin >> n >> l;
        vector<uint64_t> sequence(l);
        vector<uint64_t> unsorted(l + 1), sorted(l + 1);
        map<uint64_t, char> m;
        for (int j = 0; j < l; j++) {
            cin >> sequence[j];
        }
        unsorted[1] = gcd(sequence[0], sequence[1]); //get_first_factor(sequence[0], primes);
//        cout << unsorted[0] << " " << sequence[0] << " " << sequence[1] << endl;
        sorted[1] = unsorted[1];
        sorted[0] = sequence[0] / unsorted[1];  unsorted[0] = sorted[0];
        sorted[2] = sequence[1] / unsorted[1];  unsorted[2] = sorted[2];
//        for (int j = 1; j < l + 1; j++) {
//            unsorted[j] = sequence[j - 1] / unsorted[j - 1];
//            sorted[j] = unsorted[j];
//        }
        for (int j = 3; j < l + 1; j++) {
            sorted[j] = sequence[j - 1] / sorted[j - 1];
            unsorted[j] = sorted[j];
        }
        sort(sorted.begin(), sorted.end());
//        for (int j = 0; j < l + 1; j++) cout << sorted[j] << endl;
        m.insert(make_pair(sorted[0], 'A'));
        for (int j = 1, cnt = 1; j < l + 1; j++) {
            if (sorted[j] != sorted[j - 1]) {
                m.insert(make_pair(sorted[j], 'A' + cnt));
                cnt++;
            }
        }
        cout << "Case #" << i << ": ";
        for (int j = 0; j < l + 1; j++) {
//            cout << unsorted[j] << " " << m[unsorted[j]] << endl;
            cout << m[unsorted[j]];
        } cout << endl;
    }
}
int main() {
//    foregone_solution();          // Problem A
//    you_can_go_your_own_way();    // Problem B
//    cryptopangrams();             // Problem C // Not solved
    return 0;
}