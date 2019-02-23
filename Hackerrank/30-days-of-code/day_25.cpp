// Running time and complexity
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t, n;
    cin >> t;
    while(t-- > 0) {
        cin >> n;
        int sqrt_n = sqrt(n);
        //cout << sqrt_n << endl;
        int cnt = 0;
        for(int i = 2; i <= sqrt_n; i++) {
            if(n % i == 0) cnt++;
        }
        if(n == 1 || cnt >= 1) cout << "Not prime\n";
        else cout << "Prime\n";
    }
    return 0;
}
