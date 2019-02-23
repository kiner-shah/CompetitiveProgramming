// Poisson distribution 1
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int fact(int n) {
    if(n == 1 || n == 0) return 1;
    else return n * fact(n - 1);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    cout << setprecision(2) << pow(2.5, 5) * exp(-2.5) / fact(5);
    return 0;
}