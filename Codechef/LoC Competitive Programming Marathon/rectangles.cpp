#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	int l1,w1,l2,w2;
	cin>>t;
	while(t-- > 0) {
		cin>>l1>>w1>>l2>>w2;
		if(l1 == l2 && w1 == w2) {
			cout<<l1 * w1 + l2 * w2 - w1 * l2<<" ";
			cout<<l1 * w1 + l2 * w2<<endl;
		}
		else {
			if(l1 < l2) {
				if(w1 < w2) {
					cout<<l2 * w2<<" ";
					cout<<l1 * w1 + l2 * w2<<endl;
				}
				else {
					cout<<l2 * w2 + l1 * (w1 - w2)<<" ";
					cout<<l1 * w1 + l2 * w2<<endl;
				}
			}
			else {
				if(w1 > w2) {
					cout<<l1 * w1<<" ";
					cout<<l1 * w1 + l2 * w2<<endl;
				}
				else {
					cout<<l1 * w1 + l2 * (w2 - w1)<<" ";
					cout<<l1 * w1 + l2 * w2<<endl;
				}
			}
		}
	}
	return 0;
}
