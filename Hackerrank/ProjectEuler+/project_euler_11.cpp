// Largest product in a grid
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int a[20][20], i, j;
    for(i = 0; i < 20; i++) {
        for(j = 0; j < 20; j++) cin >> a[i][j];
    }
    long long int maxp = -1; 
    for(i = 0; i <= 16; i++) {
        long long int p = 1;
        for(j = 0; j < 20; j++) { 
            p = (a[i][j] * a[i + 1][j] * a[i + 2][j] * a[i + 3][j]);
            if(p > maxp) maxp = p;
        }
    }
    for(i = 0; i < 20; i++) {
        long long int p = 1;
        for(j = 0; j <= 16; j++) { 
            p = (a[i][j] * a[i][j + 1] * a[i][j + 2] * a[i][j + 3]);
            if(p > maxp) maxp = p;
        }
    }
    for(i = 3; i < 20; i++) {
        long long int p = 1;
        for(j = 0; j <= 16; j++) { 
            p = (a[i][j] * a[i - 1][j + 1] * a[i - 2][j + 2] * a[i - 3][j + 3]);
            if(p > maxp) maxp = p;
        }
    }
    for(i = 3; i < 20; i++) {
        long long int p = 1;
        for(j = 19; j >= 3; j--) { 
            p = (a[i][j] * a[i - 1][j - 1] * a[i - 2][j - 2] * a[i - 3][j - 3]);
            if(p > maxp) maxp = p;
        }
    }
    cout << maxp;
    return 0;
}
