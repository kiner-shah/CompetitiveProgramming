// Smallest multiple
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a,int b) {
    int r=a%b;
    if(r==0)
        return b;
    else
        return gcd(b,r);
}
int lcm(int a,int b) {
    return (a*b)/gcd(a,b);
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,n;
    cin>>t;
    while(t-- > 0) {
        cin>>n; int ans=1;
        for(int i=2;i<=n;i++) {
            ans=lcm(ans,i);
        }
        cout<<ans<<endl;
    }
    return 0;
}
