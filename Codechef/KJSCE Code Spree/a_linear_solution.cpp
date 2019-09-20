#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int i,j;
	int n,t,a[5000][2];
	cin>>t;
	while(t-- > 0) {
		cin>>n;
		for(i=0;i<n;i++) {
			for(j=0;j<2;j++)
			cin>>a[i][j];
		}
		int c=n-1,max=0;
		while(c!=1) {
			float m=(float)(a[c][1]-a[0][1])/(a[c][0]-a[0][0]);
			int count=2,x=a[0][0],y=a[0][1];
			for(i=1;i<c;i++) {
				if(a[i][1]-y == m*(a[i][0]-x)) {
					count++;
					//cout<<m*a[i][0]<<endl;
				}
			}
			if(max<count)
				max=count;
			c--;
		}
		cout<<max<<endl;
	}
	return 0;
}
