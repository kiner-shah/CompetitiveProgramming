#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;

void chef_and_cook_off_contests() {
/*
exactly one "cakewalk";
exactly one "simple";
exactly one "easy";
one "easy-medium" or one "medium";
one "medium-hard" or one "hard".
*/
	long int t, n;
    cin>>t;
    while(t-- > 0) {
        cin>>n;
        string a[n]; int c = 0;
        bool cw = false, s = false, e = false, em = false, mh = false;
        for(long int i = 0; i < n; i++) {
            cin>>a[i]; //cout<<a[i]<<" ";
            if(a[i] == "cakewalk") cw = true;
            else if(a[i] == "simple") s = true;
            else if(a[i] == "easy") e = true;
            else if(a[i] == "easy-medium" || a[i] == "medium") em = true;
            else if(a[i] == "medium-hard" || a[i] == "hard") mh = true;
        }
        if(cw && e && s && em && mh) cout<<"Yes\n";
        else cout<<"No\n";
    }
}
int main() {
    // your code goes here 
    // chef_and_cook_off_contests();
    return 0;
}
