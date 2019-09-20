#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
template<typename T> inline T Max(T a, T b) { return (a > b ? a : b); }
template<typename T> inline bool comp(T a, T b) { return a < b; }

void equator() {
	int n;
	cin >> n;
	int sum = 0, a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	int i, val = ceil(sum / 2.0);
	sum = 0;
	for(i = 0; i < n; i++) {
		if(sum + a[i] >= val) {
			break;	
		}
		sum += a[i];
	}
	cout << i + 1;
}
void students_in_a_railway_carriage() {
	int n, a, b;
	cin >> n >> a >> b;
	string s; cin >> s;
	char prev;
	int count = 0;
	for(int i = 0; i < n; i++) {
		if(i == 0) {
			if(s[i] == '*') prev = '*';
			else if(s[i] == '.' && a > b && a > 0) { prev = 'a'; a--; count++; }
			else if(s[i] == '.' && b > 0) { prev = 'b'; b--; count++; }
		} 
		else {
			if(prev == '*') {
				if(s[i] == '*') prev = '*';
				else if(a > b && a > 0) { prev = 'a'; a--; count++; }
				else if(b > 0) { prev = 'b'; b--; count++; }
			}
			else if(prev == 'b' && s[i] == '.') {
				if(a > 0) { prev = 'a'; a--; count++; }
				else { prev = '*'; } 
			}
			else if(prev == 'a' && s[i] == '.') {
				if(b > 0) { prev = 'b'; b--; count++; }
				else { prev = '*'; }
			}
			else if(s[i] == '*') prev = '*';
		} //cout << a << " " << b << " " << prev << endl;
	}
	cout << count;
}
int main() {
	// equator();
	// students_in_a_railway_carriage();
    return 0;
}
