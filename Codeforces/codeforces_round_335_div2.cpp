#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
using namespace std;
bool comp(int i, int j) { return i<j; }
void magic_spheres() {
	long long int a,b,c,x,y,z,d1,d2,d3,neg=0;
    cin>>a>>b>>c;
    cin>>x>>y>>z;
    if((a>=x && b>=y)&&(c>=z)) cout<<"Yes";
    else if(a<x &&(b<y && c<z)) cout<<"No";
    else {
        d1=a-x;
        d2=b-y; 
        d3=c-z;
        if(d1<0) neg+=abs(d1);
        if(d2<0) neg+=abs(d2);
        if(d3<0) neg+=abs(d3);
        if(neg>0 && d1>0) neg-=d1/2;
        if(neg>0 && d2>0) neg-=d2/2;
        if(neg>0 && d3>0) neg-=d3/2;
        //cout<<d1/2<<" "<<d2/2<<" "<<d3/2<<" "<<neg<<" ";
        if(neg>0) cout<<"No";
        else cout<<"Yes";
    }
}
int main() {
    // your code goes here  
    // magic_spheres();
    return 0;
}
