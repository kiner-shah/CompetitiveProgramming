// Weighted mean
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, i;
    cin>>n;
    int x[n], w[n], sump = 0, sumw = 0;
    for(i = 0; i < n; i++) cin>>x[i];
    for(i = 0; i < n; i++) {
        cin>>w[i]; sumw += w[i];
    }
    for(i = 0; i < n; i++) {
       sump += x[i] * w[i];
    }
    printf("%0.1f", (float) sump / sumw);
    return 0;
}