// Binomial distribution 1
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int fact(int x) {
    if(x == 0 || x == 1) return 1;
    else return x * fact(x - 1);
}

double find_ncr(int n, int x) {
    double val = (double) (fact(n)) / (fact(n - x) * fact(x));
    return val;
}

int main() {
    // ans = nCx p^x * (1 - p)^x
    double p = 1.09 / 2.09, q = 1.0, sol = 0.0;
    for(int i = 3; i <= 6; i++) {
        sol += find_ncr(6, i) * pow(p, i) * pow(1 - p, 6 - i);
    }
    cout << setprecision(3) << sol;
    return 0;
}