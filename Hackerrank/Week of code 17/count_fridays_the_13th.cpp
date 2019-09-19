#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,i,d1,d2,m2,m1,y1,y2,y;
    cin>>t;
    int first[12] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    while(t-- > 0) {
        cin>>d1>>m1>>y1; int count=0;
        cin>>d2>>m2>>y2;
        if(d1>13 && m1==12) {
            m1=1; y1++; }
        if(d2<13 && m2==1) {
            m2=12; y2--; }
        if(d1>13)
            m1++;
        if(d2<13)
            m2--;
        //cout<<m2;
        for(i=m1;y1<=y2;) {
            y=y1;
            //cout<<i<<" "<<y1<<endl;
            y=y-(i<3);
            int ans=(y+y/4-y/100+y/400+first[i-1]+13)%7;
            if(ans == 5) {
                //cout<<"13 "<<i<<" "<<y1<<endl;
                count++;
            }
            if(y1==y2 && i==m2) {
                i=1; y1++; //cout<<i<<endl;
            }
            else if(i==12) {
                i=1; y1++; //cout<<i<<endl;
            }
            else
                i++;
        }
        cout<<count<<endl;
    }
    return 0;
}
