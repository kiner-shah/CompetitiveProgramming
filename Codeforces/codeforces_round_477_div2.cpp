// Codeforces Round #477 (Div. 2, based on VK cup round 3)
#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <map>
#include <vector>
#include <set>
#define MOD 1000000007
using namespace std;

void mind_the_gap() {
	int n, s;
	cin >> n >> s;
	int h[n + 1], m[n + 1];
	h[0] = m[0] = 0;
	for(int i = 0; i < n; i++) {
		cin >> h[i + 1] >> m[i + 1];
	}
	bool ans_found = false;
	for(int i = 1; i < n + 1; i++) {
		int time1 = h[i - 1] * 60 + m[i - 1];
		int time2 = h[i] * 60 + m[i];
		if(i == 1 && time2 - time1 >= s + 1) {
			cout << h[i - 1] << " " << m[i - 1];
			ans_found = true;
			break;
		} 
		if(time2 - time1 >= 2 * s + 2) {
			int ans_time = time1 + s + 1;
			cout << ans_time / 60 << " " << ans_time % 60;
			ans_found = true;
			break;
		}
	}
	if(!ans_found) {
		int time = h[n] * 60 + m[n] + s + 1;
		cout << time / 60 << " " << time % 60;
	}
}
void watering_system() {
	int n, a, b;
	cin >> n >> a >> b;
	int s[n], sum = 0;
	for(int i = 0; i < n; i++) { cin >> s[i]; sum += s[i]; }
	if((s[0] * a) / sum >= b) cout << 0;
	else {
		sort(s + 1, s + n);
		int j = n - 1, count = 0;
		while(j >= 1) {
			sum -= s[j];
			count++;
			if((s[0] * a) / sum >= b) { cout << count; break; }
			j--;
		}
	}
}
int main() {
	// mind_the_gap();
	// watering_system();
	return 0;
}
