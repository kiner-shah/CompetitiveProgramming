// Largest palindrome product
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool comp(long int i, long int j) { return i<j; }
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t; long long n,j,i,x;
    cin>>t;
    vector<long int> p;
    for(i=101;i<=999;i++) {
        for(j=i+1;j<=999;j++) {
            x=i*j;
            if(x>101100 && x<1000000) {
                string a=to_string(x);
                string b=a;
                reverse(a.begin(),a.end());
                if(b.compare(a)==0) p.push_back(x);
            }
        }
    }
    //cout<<endl;
    sort(p.begin(),p.end(),comp);
    while(t-- > 0) {
        cin>>n;
        for(i=0;i<p.size();i++) {
            //cout<<p[i]<<" ";
            if(p[i]>=n) break;
        }
        cout<<p[i-1]<<endl;
    }
    return 0;
}
