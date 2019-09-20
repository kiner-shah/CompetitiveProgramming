// Codeforces Round #483 (Div. 2): A - Game
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
typedef long long LL;

void game() {
	long int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	if(n % 2 == 0) cout << a[n / 2 - 1];
	else cout << a[n / 2];
}
int main() {
	// game();
	return 0;
}
