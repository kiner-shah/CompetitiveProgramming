// Round based on MemSQL Start[c]UP 3.0 - Round 2
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <map>
using namespace std;

void between_the_offices() {
	int n; 
	cin>>n;
	string str;
	cin>>str;
	int f2s = 0, s2f = 0;
	for(int i = 1; i < n; i++) {
		if(str[i - 1] == 'S' && str[i] == 'F') s2f++;
		else if(str[i - 1] == 'F' && str[i] == 'S') f2s++;
	}
	if(s2f > f2s) cout<<"YES";
	else cout<<"NO";
}
int main() {
	// between_the_offices();
	return 0;
}
