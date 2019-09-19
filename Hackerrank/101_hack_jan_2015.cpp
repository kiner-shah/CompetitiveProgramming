#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void angry_professor() {
	int t,n,k,a[1000],j,i,count,count1;
    cin>>t;
    for(i=0;i<t;i++) {
        cin>>n>>k; count=count1=0;
        for(j=0;j<n;j++)
        {
            cin>>a[j];
            if(a[j]<=0)
                count++;
            else
                count1++;
        }   
        if(count<k)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    // angry_professor();
    return 0;
}
