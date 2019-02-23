// Quartiles
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int i, n; cin>>n;
    int x[n];
    for(i = 0; i < n; i++) cin>>x[i];
    sort(x, x + n);
    //for(i = 0; i < n; i++) cout<<x[i]<<" "; cout<<endl;
    int half = n / 2;
    if(n % 2) {
        int median = x[half];
        int q1 = (x[half / 2] + x[half / 2 - 1]) / 2;
        int q3 = (x[half + half / 2] + x[half + half / 2 + 1]) / 2;
        cout<<q1<<"\n"<<median<<"\n"<<q3;
    }
    else {
        int median = (x[half] + x[half - 1]) / 2;
        int half_by_2 = half / 2;
        if(half % 2) {
            int q1 = x[half_by_2];
            int q3 = x[half_by_2 + half];
            cout<<q1<<"\n"<<median<<"\n"<<q3;
        }
        else {
            int q1 = (x[half_by_2] + x[half_by_2 - 1]) / 2;;
            int q3 = (x[half_by_2 + half] + x[half_by_2 + half - 1]) / 2;
            cout<<q1<<"\n"<<median<<"\n"<<q3;
        }
    }
    return 0;
}