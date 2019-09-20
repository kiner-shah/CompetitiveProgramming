#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int dist[230];
struct compare {
	bool operator()(const int&a, const int &b) {
		cout << "COMP: " << a << " " << b << endl;
		return dist[a] < dist[b];
	}	
};
// @return	vector containing distances from @code(src) to all other nodes
// @param	a	graph containing interconnections
// @param	src	source node
vector<int> dijsktra(int a[230][230], int c, int src) {
	set<int/*, compare*/> q;
	fill(dist, dist + c, 999999);
	dist[src] = 0;
	// cout << c << endl;
	for(int i = 0; i < c; i++) {
		q.insert(i);
	}
	int u = src;
	q.erase(u);
	while(!q.empty()) {
		for(int j = 0; j < c; j++) {
			if(a[u][j] > 0) {
				int val = dist[u] + a[u][j];
				if(val < dist[j]) {
					dist[j] = val;
				}
			}
		}
		int min1 = INT_MAX, pos = -1;
		for(int x : q) {
			if(dist[x] < min1) {
				min1 = dist[x];
				pos = x;
			}
		} 
		if(pos == -1) break;
		u = pos;
		q.erase(u);
	}
	vector<int> v(dist, dist + c);
	return v;
}
void free_ticket() {
	int a[230][230];
	int x, y, p, i, c, f;
	// c <= 230, f <= 23665
	cin >> c >> f;
	for(i = 0; i < c; i++) fill(a[i], a[i] + c, 999999);
	for(i = 0; i < f; i++) {
		cin >> x >> y >> p;
		a[x - 1][y - 1] = p;
		a[y - 1][x - 1] = p;
	}
	int max_min = -1;
	for(i = 0; i < c; i++) {
		vector<int> v = dijsktra(a, c, i);
		// for(int kk : v) cout << kk << " "; cout << endl;
		for(int j = i; j < c; j++) {
			if(max_min < v[j]) {
				max_min = v[j];
			}	
		}
	}
	cout << max_min;
}
int main() {
	// free_ticket();
	return 0;
}
