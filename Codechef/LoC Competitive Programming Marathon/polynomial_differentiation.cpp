// Partially solved for 80 pts
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	unsigned long long n,c,e;
	cin>>t;
	while(t-- > 0) {
		cin>>n; long long int d = 0;
		while(n-- > 0) {
			cin>>c>>e;
			if(e == 0) continue;
			else if(c == 0) continue;
			else if(e == 1) {
				if(d == 0) cout<<c<<" ";
				else cout<<"+ "<<c<<" ";
			}
			else {
				if(d == 0) cout<<c * e<<"x";
				else cout<<"+ "<<c * e<<"x";
				cout<<"^"<<e-1<<" ";
			}
			d++;
		}
		cout<<endl;
	}
	return 0;
}
