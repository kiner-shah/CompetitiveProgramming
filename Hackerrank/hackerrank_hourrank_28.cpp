#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int clock_delay() {
	int t;
	int h1, int m1, int h2, int m2, int k;
	cin >> t;
	while (t-- > 0) {
		cin >> h1 >> m1 >> h2 >> m2 >> k;
		int newh = h1 + k;
		int newm = m1;

		int mindiff = newh * 60 + newm - h2 * 60 - m2;
		cout << mindiff << endl;
	}
}

int main()
{
    // clock_delay();
    return 0;
}
