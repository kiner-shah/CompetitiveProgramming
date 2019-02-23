// Standard deviation
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
    int a[n];
    double sum1 = 0.0, sum2 = 0.0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum1 += a[i];
    }
    double mean = sum1 / n;
    for(int i = 0; i < n; i++) {
        sum2 += pow(a[i] - mean, 2.0);
    }
    printf("%.1lf", sqrt(sum2 / n));
    return 0;
}