#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
void swap(char &a, char &b) {
	char t = a;
	a = b;
	b = t;
}
void encoding_message() {
	int t, n;
	cin >> t;
	string s;
	//string source = "abcdefghijklmnopqrstuvwxyz";
	string dest =     "zyxwvutsrqponmlkjihgfedcba";
	while(t-- > 0) {
		cin >> n >> s;
		for(int i = 0; i < n; i += 2) {
			if(i + 1 < n) swap(s[i], s[i + 1]);
			s[i] = dest[s[i] - 'a'];
			if(i + 1 < n) s[i + 1] = dest[s[i + 1] - 'a'];
		}
		// if(n % 2 == 1) s[n - 1] = dest[s[n - 1] - 'a'];
		cout << s << endl;
	}
}
int main() {
	// encoding_message();
	return 0;
}
