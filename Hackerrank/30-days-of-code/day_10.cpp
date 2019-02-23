// Binary numbers
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    int max1 = -1, count = 0;
    while(n > 0) {
        if(n % 2 == 1) count++;
        else {
            max1 = max(max1, count);
            count = 0;
        }
        n >>= 1;
        //cout << n << " " << max1 << endl;
    }
    cout << max(max1, count);
    return 0;
}