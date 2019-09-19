#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib> 
#include <ctime>
using namespace std;
bool isSorted(vector<int> v) {
    int i; bool flag = true;
    for(i = 1; i < v.size(); i++) {
        if(v[i] < v[i - 1]) {
            flag = false; break;
        }
    }
    return flag;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, i, x;
    cin>>n;
    vector<int> v;
    int a[101];
    fill(a, a+101, 0);
    for(i = 0; i < n; i++) {
        cin>>x;
        v.push_back(x);
        a[x]++;
    }
    long long c = 0;
    unsigned long long p[19] = {
        1, 1, 2 , 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 
        1307674368000, 20922789888000, 355687428096000, 6402373705728000
    };
    /*for(i = 1; i < 101; i++) {
        if(a[i] > 1) prob1 /= p[a[i]];
    }*/
    bool flag = isSorted(v);
    if(flag) cout<<"0.000000";
    else {
        double prob1 = p[n];
        for(i = 1; i < 101; i++) {
            if(a[i] > 1) {
                prob1 /= p[a[i]];
            }
        }
        
        printf("%0.6f",prob1);
    }
    return 0;
}
