#include <iostream>
#include <string>
#include <map>
using namespace std;
void distinct_codes() {
	int t,i; string s,a;
	cin>>t;
	while(t-- > 0) {
		cin>>s;
		map<string,int> m;
		map<string,int>::iterator it;
		for(i=0;i<s.length()-1;i++) {
			a=s.substr(i,2);
			it=m.find(a);
			if(it!=m.end()) m[a]++;
			else m.insert(pair<string,int>(a,1));
		}
		cout<<m.size()<<endl;
	}
}
int main() {
	// your code goes here
	// distinct_codes();
	return 0;
}
