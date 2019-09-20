#include <bits/stdc++.h>
using namespace std;

void chef_detective() {
	int n,i;
	scanf("%d",&n);
	int a[n],count[n];
	fill(count,count+n,0);
	for(i=0;i<n;i++) {
		scanf("%d",a + i);
		if(a[i] == 0) continue;
		else count[a[i] - 1]++;
	}
	for(i=0;i<n;i++) {
		if(count[i] == 0) printf("%d ",i+1);
	}
}
int main() {
	// your code goes here
	// chef_detective();
	return 0;
}
