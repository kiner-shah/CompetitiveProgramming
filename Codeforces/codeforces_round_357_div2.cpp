#include <bits/stdc++.h>
using namespace std;

void a_good_contest() {
	int n; bool flag = false;
	string a,p,c; int before, after;
	cin>>n;
	for(int i = 0; i < n; i++) {
	    cin>>a>>before>>after;
	    if(before >= 2400 && after > before) { flag = true; }
	    //cout<<flag<<" ";
	}
	if(flag) cout<<"YES";
	else cout<<"NO";
}
int main()
{
	// a_good_contest();
	return 0;
}
