#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    long long int t,n,i,x,y;
    cin>>t;
    while(t-- > 0) {
        cin>>n; long long int temp;
        temp=ceil((double)n/2);
        if(temp%2==0) {
            x=(-1)*temp;
        }
        else {
            x=temp;
        }
        if(n==1) {
            y=0;
        }
        else if(n%2==1) {
            if(((n-1)/2)%2==0)
                y=(-1)*((n-1)/2);
            else
                y=(n-1)/2+1;
        }
        else if(n%2==0) {
            if((n/2)%2==0)
                y=(-1)*n/2;
            else
                y=n/2+1;
        }
        cout<<x<<" "<<y<<endl;
            
    }
    return 0;
}
