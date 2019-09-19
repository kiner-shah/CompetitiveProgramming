#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	static bool fa,fb,fc,fd,fe,ff,f1,f2,f3,flag;
	if(a<0) fa=true;
	if(b<0) fb=true;
	if(c<0) fc=true;
	if(d<0) fd=true;
	if(e<0) fe=true;
	if(f<0) ff=true;
	int min1=0,min2=0,min3=0;
	if(a+b+c+d < 0) {
		flag = true;
		min1 = -(a+b+c+d);
	}
	if(a+f+b < 0) {
		flag = true;
		min2 = -(a+b+f);
	}
	if(a+e+d < 0) {
		flag = true;
		min3 = -(a+d+e);
	}
	if(flag) {
		if(a+b+c+d+min1>=0 && a+f+b+min1>=0 && a+e+d+min1>=0) f1=true;
		if(a+b+c+d+min2>=0 && a+f+b+min2>=0 && a+e+d+min2>=0) f2=true;
		if(a+b+c+d+min3>=0 && a+f+b+min3>=0 && a+e+d+min3>=0) f3=true;
		if(f1 && f2 && f3) {
			if(min1<min2 && min1<min3) cout<<min1;
			else if(min2<min1 && min2<min3) cout<<min2;
			else if(min3<min1 && min3<min2) cout<<min3;
		}
		else if(f1 && f2) {
			if(min1<min2) cout<<min1;
			else cout<<min2;
		}
		else if(f1 && f3) {
			if(min1<min3) cout<<min1;
			else cout<<min3;
		}
		else if(f3 && f2) {
			if(min3<min2) cout<<min3;
			else cout<<min2;
		}
		else if(f1) cout<<min1;
		else if(f2) cout<<min2;
		else if(f3) cout<<min3;
		else cout<<-1;
	}
	else cout<<0;
	return 0;
}
