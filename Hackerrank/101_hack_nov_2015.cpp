#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void mystery_number() {
	int n,i;
    int *a,*b,x,y;
    cin>>n;
    a=new int[101]; b=new int[101];
    for(i=0;i<n;i++) {
        cin>>x;
        a[x]++;
    }
    for(i=0;i<n+1;i++) {
        cin>>y;
        b[y]++;
    }
    for(i=0;i<101;i++) {
        if(a[i] != b[i]) { cout<<i; break; }
    }
}
int main() {
    // mystery_number();
    return 0;
}
