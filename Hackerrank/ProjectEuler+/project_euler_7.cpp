// 10001st prime
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int i,j,*isprime=new int[217286];
    vector<int> v;
    fill(isprime, isprime + 217286, 1);
    isprime[0]=isprime[1]=0; isprime[2]=1;
    v.push_back(2);
    for(i=4;i<=217286;i+=2)
        isprime[i]=0;
    for(i=3;i<=217286;i+=2) {
        if(isprime[i]==1) {
            v.push_back(i);
            for(j=3;j*i<217286;j+=2)
                isprime[j*i]=0;
        }
    }
    vector<int>::iterator it;
    /*for(it=v.begin();it!=v.end();it++)
        cout<<*it<<" ";*/
    int t,n;
    cin>>t;
    while(t-- > 0) {
        cin>>n;
        cout<<v.at(n-1)<<endl;
    }
    return 0;
}
