// Codeforces Round #482 (Div. 2)
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

void pizza_pizza_pizza() {
	ULL n;
	cin >> n;
	// n + 1 slices, 0 <= n <= 10^18
	if(n == 0) cout << 0;
	else {
		if((n + 1) % 2 == 0) cout << (n + 1) / 2;
		else cout << n + 1;
	}
}
int main() {
	// pizza_pizza_pizza();
	return 0;
}
