#include <bits/stdc++.h>
using namespace std;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long i,n,c,m,j;
    cin>>c>>m>>n;
    long long cur = 0, next = c;
    vector<pair<long long,long long>> v;
    vector<pair<long long,long long>>::iterator it;
    set<long long> s1;
    for(i = 0; i < n; i ++) {
        cur = (cur + next) % m;
        next = (cur + next) % m;
        v.push_back(make_pair(cur,next));
    }
    for(i = 1; i < v.size(); i++) {
            
        long long temp = v[0].first * v[i].first + v[0].second * v[i].second;
            //cout<<temp<<endl;
        s1.insert(temp % m); //cout<<temp<<endl;
        if(i == v.size() - 1) break;
        temp = v[v.size() - 1].first * v[i].first + v[v.size() - 1].second * v[i].second;
        s1.insert(temp % m); //cout<<temp<<endl;
    }
    cout<<s1.size() % m;
    return 0;
}
