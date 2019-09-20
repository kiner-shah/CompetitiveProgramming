#include <iostream>
using namespace std;

void elephant() {
	long int x,c=0;
	cin>>x;
	c+=(x/5);
	x%=5; //cout<<x;
	if(x>0) {
		c+=(x/4);
		x%=4;
	}
	if(x>0) {
		c+=(x/3);
		x%=3;
	}
	if(x>0) {
		c+=(x/2);
		x%=2;
		if(x==1) c+=x;
	}
	cout<<c;
}
void chocolate() {
	int n;
	long long int ans=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int prev=-1;
	for(int i=0;i<n;i++) {
		if(a[i]==1 && prev==-1) prev=i,ans=1;
		else if(a[i]==1) {
			//cout<<prev<<" "<<i<<endl;
			ans*=(i-prev); prev=i;
		}
	}
	cout<<ans;
}
int main() {
	// your code goes here
	// elephant();
	// chocolate();
	return 0;
}
