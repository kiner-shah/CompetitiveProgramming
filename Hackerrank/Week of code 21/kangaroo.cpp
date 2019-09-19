#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int x1, v1, x2, v2;
    cin>>x1>>v1>>x2>>v2;
    if(x1 < x2 && v1 <= v2) cout<<"NO";
    else {
        float n = (float) (x1 - x2) / (v2 - v1);
        int t1 = (int)n;
        int t2 = (int)ceil(n);
        if(t1 == t2) cout<<"YES";
        else cout<<"NO";
    }
    return 0;
}
