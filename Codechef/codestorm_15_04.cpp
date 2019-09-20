#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
void two_friends_at_the_zoo() {
	unsigned long long int t,f,m,i;
	cin>>t;
	for(i=0;i<t;i++) {
	cin>>f>>m;
	if(m%f==0)
		cout<<"CORRECT"<<endl;
	else
		cout<<"WRONG"<<endl;
	}
}
int main()
{
	// two_friends_at_the_zoo();
	return 0;
}
