// Maximum path sum
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct temp_strct {
    int i, j, score;
} TempStruct;

inline bool compare(TempStruct a, TempStruct b) { return a.score > b.score; }

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t, n;
    cin >> t;
    int mat[15][15];
    while(t-- > 0) {
        cin >> n;
        vector<TempStruct> v;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) cin >> mat[i][j];
        }
        TempStruct first;
        first.i = 0; first.j = 0; first.score = mat[0][0];
        v.push_back(first);
        int max = -1;
        while(!v.empty()) {
            TempStruct temp = v[0];
            v.erase(v.begin());
            //cout << temp.i << " " << temp.j << " " << temp.score << endl;
            if(max < temp.score) { max = temp.score; }
            TempStruct t1, t2;
            if(temp.i == n - 1) continue;
            t1.i = temp.i + 1; t1.j = temp.j; t1.score = temp.score + mat[t1.i][t1.j]; //cout << mat[t1.i][t1.j] << " ";
            t2.i = temp.i + 1; t2.j = temp.j + 1; t2.score = temp.score + mat[t2.i][t2.j]; //cout << mat[t2.i][t2.j] << " ";
            v.push_back(t1); v.push_back(t2);
            sort(v.begin(), v.end(), compare);
            //for(TempStruct tt : v) cout << tt.i << " " << tt.j << " " << tt.score << endl; cout << temp.score << endl;
        }
        cout << max << endl;
    }
    return 0;
}
