// Largest product in a series
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin>>t;
    while(t-- > 0) {
        int n,m; char *a;
        cin>>n>>m;
        a=new char[n+1];
        cin>>a;
        int max=0;
        for(int i=0;i<n-m;i++) {
            int prod=1;
            for(int j=i;j<i+m && a[i+m-1]!='\0';j++) {
                //cout<<a[j];
                prod*=a[j]-'0';
                //cout<<prod<<" ";
            }
            //cout<<" ";
            if(prod>=max)
                max=prod;
        }
        cout<<max<<endl;   
    }
    return 0;
}
