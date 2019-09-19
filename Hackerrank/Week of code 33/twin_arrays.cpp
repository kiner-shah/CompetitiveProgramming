#include <cmath>
#include <cstdio>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n;
    cin>>n;
    int a[n], b[n], i;
    set<pair<int, int>> sa, sb;
    for(i = 0; i < n; i++) { cin>>a[i]; sa.insert(make_pair(a[i], i)); }
    for(i = 0; i < n; i++) { cin>>b[i]; sb.insert(make_pair(b[i], i)); }
    //for(pair<int, int> p : sa) cout<<p.first<<" "<<p.second<<endl; cout<<endl;
    //for(pair<int, int> p : sb) cout<<p.first<<" "<<p.second<<endl;
    pair<int, int> p1 = *sa.begin();
    pair<int, int> p2 = *sb.begin();
    if(p1.second != p2.second) cout<<p1.first + p2.first;
    else {
        set<pair<int, int>>::iterator it1 = sa.begin(), it2 = sb.begin();
        advance(it1, 1);
        advance(it2, 1);
        pair<int, int> q1 = *it1;
        pair<int, int> q2 = *it2;
        cout<<min(p1.first + q2.first, p2.first + q1.first);
    }
    return 0;
}
