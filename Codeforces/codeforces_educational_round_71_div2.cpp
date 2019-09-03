// Codeforces Educational Round 71
#include <bits/stdc++.h>
using namespace std;
 
// A. There Are Two Types Of Burgers
void there_are_two_types_of_burgers() {
    int t, b, p, f, h, c;
    cin >> t;
    while (t-- > 0) {
        cin >> b >> p >> f;
        cin >> h >> c;
        int b_by_2 = b / 2;
        bool is_h_more_than_c = h > c;
        int cost = 0;
        while (b_by_2 > 0) {
            if (p > 0 && is_h_more_than_c) { cost += h; p--; }
            else if (f > 0) { cost += c; f--; }
            else if (p > 0) { cost += h; p--; }
            b_by_2--;
        }
        if (b_by_2 == 0) cout << cost << endl;
        else {
            if (f == 0 && p > 0) { while (b_by_2 > 0) { cost += h; p--; b_by_2--; } }
            else if (p == 0 && f > 0) { while (b_by_2 > 0) { cost += c; f--; b_by_2--; } }
            cout << cost << endl;
        }
    }
}
// B. Square Filling
void square_filling() {
    int n, m;
    cin >> n >> m;
    int a[n][m], b[n][m];
    bool all_zeros = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (all_zeros && a[i][j] == 1) all_zeros = false;
            b[i][j] = 0;
        }
    }
    if (all_zeros) { cout << 0 << endl; return 0; }
    vector<pair<int, int> > v;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (a[i][j] && a[i + 1][j] && a[i + 1][j + 1] && a[i][j + 1]) {
                v.push_back(make_pair(i + 1, j + 1));
                b[i][j] = 1;
                b[i + 1][j] = 1;
                b[i + 1][j + 1] = 1;
                b[i][j + 1] = 1;
            }
        }
    }
    bool flag = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //cout << b[i][j] << " ";
            if (a[i][j] != b[i][j]) { flag = false; break; }
        } //cout << endl;
    }
    if (!flag) cout << -1 << endl;
    else {
        cout << v.size() << endl;
        for (pair<int, int> p : v) cout << p.first << " " << p.second << endl;
    }
}

int main() {
    //there_are_two_types_of_burgers();
    //square_filling();
    return 0;
}
