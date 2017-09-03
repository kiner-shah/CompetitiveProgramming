#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int t, n, i = 0, limit;
	cin>>t;
	while(i < t) {
		cin>>n;
		long int a[n];
		limit = n - 2;
		long int sum1 = 0, sum2 = 0, actuals1 = 0, actuals2 = 0;
		vector<long int> equals;
		for(int j = 0; j < n; j++) cin>>a[j];
		sort(a, a + n);
		for(int j = 0; j < n; j++){
			if(j <= limit) { sum1 ^= a[j]; actuals1 += a[j]; }
			else { sum2 ^= a[j]; actuals2 += a[j]; }
		}
		//cout<<limit<<" "<<sum1<<" "<<sum2<<" "<<actuals1<<" "<<actuals2<<endl;
		if(sum1 == sum2) equals.push_back(actuals2);
		while(limit != 0) {
			sum1 ^= a[limit]; actuals1 -= a[limit];
			sum2 ^= a[limit]; actuals2 += a[limit];
			limit--;
			if(sum1 == sum2) equals.push_back(actuals2);
			//cout<<limit + 1<<" "<<sum1<<" "<<sum2<<" "<<actuals1<<" "<<actuals2<<endl;
		}
		cout<<"Case #"<<i + 1<<": ";
		if(equals.size() == 0) cout<<"NO\n";
		else {
			vector<long int>::iterator it = max_element(equals.begin(), equals.end());
			cout<<*it<<endl;
		}
		i++;
	}
	return 0;
}