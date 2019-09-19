#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
vector<int> sieve(int lim) {
    bool *isprime=new bool[lim];
    fill(isprime,isprime+lim,true);
    vector<int> primes;
    isprime[0]=isprime[1]=false;
    primes.push_back(2);
    for(int i=4;i<=lim;i+=2) isprime[i]=false;
    for(int i=3;i<=lim;i+=2) {
        if(isprime[i]==true) {
            primes.push_back(i);
            for(int j=3;j*i<lim;j+=2)
                isprime[j*i]=false;
        }
    }
    //for(int i=0;i<primes.size();i++) cout<<primes[i]<<" ";
    return primes;
}
bool func(int i,int j) { return i<j; }
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<int> v=sieve(32001);
    vector<string> v1;
    int i,n,x,c;
    cin>>n;
    while(n-- > 0) {
        cin>>x; c=0;
        for(i=0;i<v.size();i++) {
            if(binary_search(v.begin()+i,v.end(),x-v[i],func)) {
                string s=to_string(v[i])+"+"+to_string(x-v[i]);
                v1.push_back(s);
                c++;
            }
        }
        cout<<x<<" has "<<c<<" representation(s)\n";
        for(i=0;i<v1.size();i++) cout<<v1[i]<<endl;
        cout<<endl;
        v1.clear();
    }
    return 0;
}
