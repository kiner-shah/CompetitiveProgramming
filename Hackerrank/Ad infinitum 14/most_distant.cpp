#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long int n,i;
    double x,y,maxx=-1000000001,minx=1000000001,maxy=-1000000001,miny=1000000001;
    double d=-1000000001,d2;
    cin>>n;
    for(i=0;i<n;i++) {
        cin>>x>>y; //cout<<x<<" "<<y<<endl;
        if(y==0 && x>maxx) maxx=x;
        if(y==0 && x<minx) minx=x;
        if(x==0 && y>maxy) maxy=y;
        if(x==0 && y<miny) miny=y;
    }
    /*cout<<minx<<" "<<miny<<endl;
    cout<<maxx<<" "<<maxy<<endl;*/
    cout.precision(12);
    if(abs(maxx-minx) > d) d=abs(maxx-minx);
    if(abs(maxy-miny) > d) d=abs(maxy-miny);
    d2 = sqrt(maxy*maxy + minx*minx);
    if(d2 > d) d=d2;
    d2 = sqrt(maxy*maxy + maxx*maxx);
    if(d2 > d) d=d2;
    d2 = sqrt(miny*miny + minx*minx);
    if(d2 > d) d=d2;
    d2 = sqrt(miny*miny + maxx*maxx);
    if(d2 > d) d=d2;
    cout<<fixed<<d<<endl;
    return 0;
}
