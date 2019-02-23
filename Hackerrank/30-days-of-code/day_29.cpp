// Bitwise AND
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t, n, k;
    cin >> t;
    map<pair<int, int>, int> m;
    while(t-- > 0) {
        cin >> n >> k;
        int cnt = 0, max1 = -1;
        for(int i = 1; i < n; i++) {
            for(int j = i + 1; j <= n; j++) {
                int val = i & j;
                if(val > max1 && val < k) max1 = val;
            }
        }
        cout << max1 << endl;
    }
    return 0;
}