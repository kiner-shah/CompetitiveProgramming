// Digit factorials
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> digits(long int x) {
    vector<int> v;
    while(x>0) {
        v.push_back(x%10);
        x/=10;
    }
    return v;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long int fact[10] = {1,1,2,6,24,120,720,5040,40320,362880};
    long int n,i,sum,sum1=0;
    cin>>n;
    for(i=10;i<n;i++) {
        vector<int> v = digits(i); sum=0;
        for(int j=0;j<v.size();j++) sum+=fact[v[j]];
        if(sum%i == 0) { sum1+=i; }
    }
    cout<<sum1;
    return 0;
}
