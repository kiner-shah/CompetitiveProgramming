#include <iostream>
#include <algorithm>
#include <cmath>
#include <cassert>
using namespace std;
typedef unsigned long long ULL;
// 0 < d <= n
// g >= d
// pd = dwin / d * 100
// pg = (dwin + x) / (d + x) * 100  // assuming x games played before and won in all x games
// if x = 0, i. e. no games played before, today is first time
// then pd = (dwin / d) * 100   pg = (gwin / g) * 100   where gwin = dwin, d = g
// so if we want to find d, dwin, g, gwin, we find gcd of (100, pd), divide it from 100 and check if the value is less than n
// if yes, possible, else broken

ULL gcd(ULL a, ULL b) { while(b>0) { b^=(a^=(b^=(a%=b))); } return a; }
int main() {
    int t, i = 0, pd, pg;
    ULL n, d, g, dwin, gwin;
    cin>>t;
    while(i < t) {
        cin>>n>>pd>>pg;
        if(pg == 100 && pd < 100) { cout<<"Case #"<<i + 1<<": Broken\n"; i++; continue; }
        else if(pg == 0 && pd > 0) { cout<<"Case #"<<i + 1<<": Broken\n"; i++; continue; }
        else if(pg == 0 && pd == 0) { cout<<"Case #"<<i + 1<<": Possible\n"; i++; continue; }
        ULL gcdval = gcd(100, pd);
        d = 100 / gcdval;
        if(d <= n) cout<<"Case #"<<i + 1<<": Possible\n";
        else cout<<"Case #"<<i + 1<<": Broken\n";
        i++;
    }
    return 0;
}