#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

void cricket_score() {
	long int n, i = 0;
	cin >> n;
	long int r[n];
	int w[n];
	while(i < n) {
		cin >> r[i] >> w[i];
		i++;
	}
	bool flag = true;
	for(int i = 1; i < n; i++) {
		if(r[i] >= r[i - 1] && w[i] == w[i - 1] && w[i] == 10) { flag = false; break; }
		else if(r[i] >= r[i - 1] && w[i] >= w[i - 1]) flag = true;
		else { flag = false; break; }
	}
	cout << (flag ? "YES" : "NO");
}
int main() {
	// cricket_score();
	return 0;
} 
