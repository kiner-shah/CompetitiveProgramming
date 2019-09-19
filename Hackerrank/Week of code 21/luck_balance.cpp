#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int i,n,k,x,y;
    cin>>n>>k;
    vector<pair<int, int>> v;
    for(i = 0; i < n; i++) {
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    int sum = 0;
    sort(v.begin(), v.end(), comp);
    for(i = 0; i < n; i++) {
        if(v[i].second == 1) {
            if(k > 0) {
                if(v[i].first < 0) sum -= v[i].first; //win if -ve
                else { sum += v[i].first; k--; }//lose if +ve
            }
            else {
                if(v[i].first < 0) sum += v[i].first; //lose if -ve
                else sum -= v[i].first; //win if +ve
            }
        }
        else {
            if(v[i].first < 0) sum -= v[i].first; //win if -ve
            else sum += v[i].first; //lose if +ve
        }
    }
    cout<<sum;
    return 0;
}
