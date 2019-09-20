#include <iostream>
#include <climits>
using namespace std;

void workers() {
	// 1 translator - chef language to another language
	// 2 author - write text in Chef language
	// 3 author-transaltor - combination of above two
	// ith worker - ci coins
	int n;
	cin >> n;
	int c[n], t[n];
	// greedy - first look for workers of type 3 which have min cost
	// then look for worker of type 1 and 2 respectively which have min cost
	// compare both and select
	int type_3 = 100001, type_2 = 100001, type_1 = 100001;
	for(int i = 0; i < n; i++) cin >> c[i];
	for(int i = 0; i < n; i++) {
		cin >> t[i];
		if(t[i] == 3 && type_3 >= c[i]) type_3 = c[i];
		else if(t[i] == 2 && type_2 >= c[i]) type_2 = c[i];
		else if(t[i] == 1 && type_1 >= c[i]) type_1 = c[i];
	}
	/*if(type_2 == 100001 && type_1 != 100001) type_2 = 0;
	else if(type_1 == 100001 && type_2 != 100001) type_2 = 0;*/
	cout << (type_3 <= type_2 + type_1 ? type_3 : type_2 + type_1);
	/*int min1 = INT_MAX;
	for(int i = 0; i < n; i++) { cin >> t[i]; if(min1 > c[i]) min1 = c[i]; }
	cout << min1;*/
}
int main() {
	// workers();
	return 0;
}
