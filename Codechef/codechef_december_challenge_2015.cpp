#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void chef_and_the_stones() {
	long long int t,n1,n2,m,min,i;
	cin>>t;
	while(t-- > 0) {
		cin>>n1>>n2>>m;
		vector<long long int> v(m);
		while(n1>0 && n2>0) {
			for(i=m-1;i>=0;i--) {
				if(v[i]!=1) {
					//cout<<"Pos: "<<i<<endl;
					if(i+1<=n1 && i+1<=n2){
						n1-=(i+1); n2-=(i+1);
						v[i]=1; break;	
					} 
				}
			}
			if(find(v.begin(),v.end(),0)==v.end()) break;
		}
		cout<<n1+n2<<endl;
	}
}
int main() {
	// your code goes here
	// chef_and_the_stones();	// partially solved for 30 pts
	return 0;
}
