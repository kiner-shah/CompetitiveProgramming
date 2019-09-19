#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
using namespace std;
typedef long int LI;
int findp(vector<int> a, int m) {
    int l = m;
    vector<int> b;
    for(int i = l - 1; i >= 0; i--) { b.push_back(a[i]); }
    int ll[l+1][l+1];
    for(int i = 0; i <= l; i++) { ll[i][0] = 0; ll[0][i] = 0; }
    for(int i = 1; i <= l; i++) {
        for(int j = 1; j <= l; j++) {
            if(a[i - 1] == b[j - 1]) ll[i][j] = ll[i - 1][j - 1] + 1;
            else ll[i][j] = max(ll[i - 1][j], ll[i][j - 1]);
        }
    }
    return ll[l][l];
}
int main() {
    int n, x, y, m; LI i, k;
    cin>>n>>k>>m;
    vector<int> a;
    vector<set<int>> v;
    set<int> ss;
    set<int>::iterator it;
    map<int, int> pos;
    //clock_t start = clock();
    for(i = 0; i < n; i++) { ss.insert(i); v.push_back(ss); ss.clear(); pos.insert(make_pair(i, i)); }
    for(i = 0; i < k; i++) {
        cin>>x>>y;
        int pos1 = pos[x - 1];
        int pos2 = pos[y - 1];
        if(pos1 != pos2) {
            if(v[pos1].size() > v[pos2].size()) {
                v[pos1].insert(v[pos2].begin(), v[pos2].end());
                for(it = v[pos2].begin(); it != v[pos2].end(); it++) pos[*it] = pos1;
                v[pos2].clear();
            }
            else {
                v[pos2].insert(v[pos1].begin(), v[pos1].end());
                for(it = v[pos1].begin(); it != v[pos1].end(); it++) pos[*it] = pos2;
                v[pos1].clear();
            }
        }
    }
    
    for(i = 0; i < m; i++) { cin>>x; a.push_back(pos[x - 1]); }
    /*int l = 0, r = m - 1, count = 0;
    while(l <= m) {
        if(l < m && a[l] == a[m]) { count += 2; l++; m--; }
        else if(l == m && a[l] == a[m]) { count++; l++; m--; }
        else if(l < m && a[l] == a[m - 1]) { 
            if(l == m - 1) count++;
            else count += 2; 
            m -= 2; l++; 
        }
        else if(l < m && a[l + 1] == a[m]) { 
            if(l + 1 == m) count++;
            else count += 2; 
            l += 2; m--; 
        }
        else if(find(a.begin() + l + 1, a.begin() + m, a[l]) != a.begin() + m) m--;
    }*/
    int count = findp(a, m);
    cout<<count;
    //clock_t end = clock();
    //printf("\n%0.4f\n", (double)(end - start) / 1000);
    return 0;
}
