#include <bits/stdc++.h>
using namespace std;

void cats_and_dogs() {
	int t; long long c, d, l;
	scanf("%d", &t);
	while(t-- > 0) {
		scanf("%lld %lld %lld", &c, &d, &l);
		long long total_legs = c * 4 + d * 4;
		long long min_legs;
		if(2*d >= c) min_legs = d * 4;
		else min_legs = (c - d) * 4;
		if(l == total_legs) printf("yes\n");
		else if(l >= min_legs && l <= total_legs && l % 4 == 0) printf("yes\n");
		else printf("no\n");
	}
}
int main() {
	// your code goes here
	// cats_and_dogs();
	return 0;
}
