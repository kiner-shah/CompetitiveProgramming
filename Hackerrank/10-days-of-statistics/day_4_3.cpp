// Geometric distribution 1
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

double find_geometric_dist(int n, double p) {
    double q = 1 - p;
    double sol = pow(q, n - 1) * p;
    return sol;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    double p = 1.0 / 3.0;
    int n = 5;
    cout << setprecision(2) << find_geometric_dist(n, p);
    return 0;
}