// Codeforces Round #480 (Div 2)
#include <bits/stdc++.h>
using namespace std;

void link_and_pearls() {
	string necklace;
	cin >> necklace; 
	int l = necklace.length(), threads = 0, beads = 0;
	for(int i = 0; i < l; i++) {
	//	cout << necklace[i] << endl;
		if(necklace[i] == 'o') beads++;
		else if(necklace[i] == '-') threads++;
	}
	//cout << threads << " " << beads << endl;
	if(threads >= 0 && beads >= 0) {
		if(beads == 0) cout << "YES";
		else cout << (threads % beads == 0 ? "YES" : "NO");
	}
}
void marlin() {
	int n, k;
	cin >> n >> k;
	char str[4][n+1];
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < n; j++) str[i][j] = '.';
		str[i][n] = '\0';
	}
	int e = k;
	if(k > (n - 2) * 2) { cout << "NO"; exit(0); }
	else if(k % 2 == 0) {
		for(int j = 1; j < n - 1; j++) {
			for(int i = 1; i < 3; i++) {
				if(e > 0) {
					str[i][j] = '#';
					e--;
				}
			}
			if(e <= 0) break;
		}
		cout << "YES\n";
	}
	else if(k <= n - 2) {
		for(int j = n / 2 - k / 2; j <= n / 2 + k / 2; j++) {
			if(e > 0) {
				str[1][j] = '#';
				e--;
			}
			else break;
		}
		cout << "YES\n";
	}
	else {
		for(int j = 1; j < n - 1; j++) {
			if(e > 0) {
			    if(e == 3) {
			        str[1][j] = '#';
			        str[1][j + 1] = '#';
			        str[2][j + 1] = '#';
			        e -= 3;
			    }
			    else {
				    str[1][j] = '#'; e--;
				    if(e > 0) { str[2][j] = '#'; e--; }
			    }
			}
		}
		cout << "YES\n";
	}
	for(int i = 0; i < 4; i++) { for(int j = 0; j < n; j++) cout << str[i][j]; cout << endl; }
}
int main() {
	// link_and_pearls();
	// marlin();
	return 0;
}
