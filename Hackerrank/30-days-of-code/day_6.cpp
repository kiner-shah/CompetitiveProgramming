// Let's review
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
        int t;
    cin >> t;
    string x;
    vector<char> even, odd;
    while(t-- > 0) {
        cin >> x;
        int l = x.length();
        for(int i = 0; i < l; i++) {
            if(i % 2 == 0) even.push_back(x[i]);
            else odd.push_back(x[i]);
        }
        for(char a : even) cout << a;
        cout << " ";
        for(char a : odd) cout << a;
        cout << endl;
        even.clear(); odd.clear();
    }
    return 0;
}