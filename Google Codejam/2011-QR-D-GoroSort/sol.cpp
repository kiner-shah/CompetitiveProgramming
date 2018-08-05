#include <iostream>
#include <algorithm>
using namespace std;
/*
For this problem we keep all the values which are already in correct places as frozen such that only thos
values which are not in correct place move. 
If there are 3 values, say, 3, 2, 1, the no. of possibilities after 1 hit are 3! = 6
3 2 1	2 misplaces	P = 2/6
3 1 2	3 misplaces	P = 3/6
2 1 3	2 misplaces	P = 2/6
2 3 1	3 misplaces	P = 3/6
1 2 3	0 misplaces	P = 0/6
1 3 2	2 misplaces	P = 2/6
So, now if we multiply no. of misplaces with their respective probabilities, we get the expected value 
which is nothing but average no. of misplaces after 1 hit, which in this case is approx 2. 
If we subtract no. of misplaces after 1 hit from no. of misplaces initially, then we get the no. 
of correct places after 1 hit which in this case is 1. If we generalize this to any number of elements,
we get the same result i.e. (n - 1) misplaces and 1 correct place after 1 hit.
So, the solution is nothing but, the no. of misplaces initially, as we will require that many hits to
correctly sort the elements.
*/
int main() {
	int t, n, i = 0;
	cin>>t;
	while(i < t) {
		cin>>n;
		int count_misplaces = 0, a[n], b[n];
		for(int j = 0; j < n; j++) { cin>>a[j]; b[j] = a[j]; }
		sort(b, b + n);
		for(int j = 0; j < n; j++) {
			if(a[j] != b[j]) count_misplaces++;
		}
		cout<<"Case #"<<i + 1<<": "<<count_misplaces<<endl;
		i++;
	}
	return 0;
}