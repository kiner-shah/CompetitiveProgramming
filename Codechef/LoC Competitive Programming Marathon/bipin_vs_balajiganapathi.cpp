#include <bits/stdc++.h>
using namespace std;
int main() {
	long int bl,b,n;
	cin>>n;
	while(n-- > 0) {
	cin>>b>>bl;
	if(bl > b) cout<<"Balaji "<<bl-b<<endl;
	else if(b > bl) cout<<"Bipin "<<b-bl<<endl;
	else cout<<"No Winner\n";
	}
	return 0;
}
