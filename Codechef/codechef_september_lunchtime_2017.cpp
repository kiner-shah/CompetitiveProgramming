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
bool checkpalin(LL a[], int beg, int end, int size) {
	int i, j, l = size;
	bool palin = false;
	int mid = (end - beg) / 2;
	int count = 0;
	for(i = beg, j = end; count < mid; i++, j--) {
		// cout<<i<<" "<<j<<endl;
		if(a[i] == a[j]) palin = true;
		else { palin = false; break; }
		count++;
	} 
	return palin;
}
void chef_and_programming_contest_by_his_friend() {
	int t;
    cin>>t;
    while(t-- > 0) {
    	LL n, k, ans = 0, maxlen = 0;
    	cin>>n>>k;
    	LL str[n] = {0};
    	int idx; LL cc; 
    	for(int i = 0; i < k; i++) {
    		cin>>idx>>cc;
    		str[idx - 1] = cc; 
    	}
    	// for(int i = 0; i < n; i++) cout<<str[i]<<" ";
    	ans += n;
    	if(n % 2 == 0) maxlen = n - 1;
    	else maxlen = n;
    	int l = n;
    	LL count = 0;
    	for(int i = 3; i <= maxlen; i += 2) {
    		for(int j = 0; j <= l - i; j++) {
    			// cout<<j<<" "<<j + i - 1<<endl;
    			bool flag = checkpalin(str, j, j + i - 1, n);
    			if(flag) count++;
    		}
    	}
    	cout<<ans + count<<endl;
    }
}
int main() {
    // your code goes here 
    // chef_and_cook_off_contests();
	// chef_and_programming_contest_by_his_friend();	// partially solved for 9 pts
    return 0;
}
