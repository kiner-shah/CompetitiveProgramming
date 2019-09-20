// Codeforces Round #481 (Div. 3)
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ULL;
void remove_duplicates() {
	int n;
	cin >> n;
	int a[n];
	int f[1001];
	fill(f, f + 1001, 0);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> v;
	for(int i = n - 1; i >= 0; i--) {
		if(f[a[i]] == 0) { f[a[i]] = 1; v.insert(v.begin(), a[i]); }
	}
	cout << v.size() << endl;
	for(int x : v) cout << x << " ";
}
void file_name() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	string target = "xxx";
	int j = 0, ans = 0;
	for(int i = 0; i < n - 2; i++) {
		string b = s.substr(i, 3);
		if(b == target) ans++;
	}
	cout << ans;
}
void letters() {
	int n, m;
	cin >> n >> m;
	ULL a[n], b[m];
	vector<pair<ULL, ULL> > v;
	ULL prev = 0;
	vector<ULL> uppers;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		v.push_back(make_pair(prev + 1, prev + a[i]));
		prev += a[i];
		uppers.push_back(prev);
	}
	for(int i = 0; i < m; i++) {
		cin >> b[i];
		/*int cnt = 1;
		for(pair<ULL, ULL> p : v) {
			//cout << p.first << " " << p.second << "  ";
			if(p.second >= b[i] && p.first <= b[i]) {
				cout << cnt << " " << b[i] - p.first + 1 << endl;
				break;
			} 
			cnt++;
		}*/
		vector<ULL>::iterator low, up;
		low = lower_bound(uppers.begin(), uppers.end(), b[i]);
		// up = upper_bound(uppers.begin(), uppers.end(), b[i]);
		size_t pos = low - uppers.begin();
		cout << pos + 1 << " " << b[i] - v[pos].first + 1 << endl;
	}
}
int main() {
	// remove_duplicates();
	// file_name();
	// letters();
	return 0;
}
