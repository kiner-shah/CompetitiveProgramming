// Even Fibonacci numbers
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    unsigned long long  t,i,j,f,n,f0=0,f1=1,c,sum,x,y;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n; j=3; f=2; c=2; sum=0;
        if(n<2) cout<<"0"<<endl;
        else {
        while(f<=n) {
            if(f%2==0) sum+=f;
            f=j;
            j+=c;
            c=f;
        }
        cout<<sum<<endl;
        }
    }
    return 0;
}
