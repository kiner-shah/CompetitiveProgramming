// Interquartile range
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    int a[n], f[n];
    vector<int> v;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> f[i];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < f[i]; j++)
            v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    int sz = v.size(), half_sz = sz / 2;
    // for(int i = 0; i < sz; i++) cout << v[i] << " "; cout << endl;
    if(half_sz % 2 == 1) {
        float q1 = v[(int) floor(sz / 4.0)];
        float q3 = v[sz / 2 + (int) ceil(sz / 4.0)];
        printf("%.1f", q3 - q1);
    }
    else {
        float q1 = (v[sz / 4 - 1] + v[sz / 4]) / 2.0;
        float q3 = (v[sz / 2 + sz / 4] + v[sz / 2 + sz / 4 + 1]) / 2.0;
        // cout << sz / 2 + sz / 4 << endl;
        printf("%.1f", q3 - q1);
    }
    return 0;
}