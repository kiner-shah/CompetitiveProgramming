// Special Pythagorean triplet
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    LL a, b, c, n;
    int t;
    cin>>t;
    while(t-- > 0) {
        cin>>n;
        LL max = -1;
        for(a = 1; a < n/3; a++) {
            b = (n * n - 2 * a * n) / (-2 * a + 2 * n);
            c = n - b - a;
            if(a * a + b * b == c * c && b > 0 && c > 0) {
                if(max < a * b * c) max = a * b * c;
            }
        }
        cout<<max<<endl;
    }
    return 0;
}
