// Codeforces Round #485 (Div. 2)
#include <bits/stdc++.h>
using namespace std;

void infinity_gauntlet() {
	int n;
	cin >> n;
	/*
	the Power Gem of purple color,
	the Time Gem of green color,
	the Space Gem of blue color,
	the Soul Gem of orange color,
	the Reality Gem of red color,
	the Mind Gem of yellow color.
	*/
	int power = 0, time = 0, space = 0, soul = 0, reality = 0, mind = 0;
	string x;
	for(int i = 0; i < n; i++) {
		cin >> x;
		if(x == "purple") power = 1;
		else if(x == "green") time = 1;
		else if(x == "blue") space = 1;
		else if(x == "orange") soul = 1;
		else if(x == "red") reality = 1;
		else if(x == "yellow") mind = 1;
	}
	cout << 6 - n << endl;
	if(!power) cout << "Power\n";
	if(!time) cout << "Time\n";
	if(!space) cout << "Space\n";
	if(!soul) cout << "Soul\n";
	if(!reality) cout << "Reality\n";
	if(!mind) cout << "Mind\n";
}
void high_school_become_human() {
	long long x, y;
	cin >> x >> y;
	long double val1 = (long double) y * log(x);
	long double val2 = (long double) x * log(y);
	// cout << fixed << val1 << " " << val2 << endl;
	if(val1 > val2) cout << ">";
	else if(val1 < val2) cout << "<";
	else cout << "=";

}
int main() {
	// infinity_gauntlet();
	// high_school_become_human();
	return 0;
}
