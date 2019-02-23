// Binomial distribution 2
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
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    double p = 0.12, sol1 = 0.0, sol2 = 0.0;
    for(int i = 0; i <= 2; i++) {
        sol1 += find_ncr(10, i) * pow(p, i) * pow(1 - p, 10 - i);
        if(i == 1)
            sol2 = sol1;
    }
    cout << setprecision(3) << sol1 << endl << 1 - sol2;
    return 0;
}