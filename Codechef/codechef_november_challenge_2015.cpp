#include <iostream>
#include <cmath>
using namespace std;
unsigned long long int fn(int val) {
	unsigned long long int sum=0;
	while(val>0) {
		sum+=(val%10);
		val/=10;
	}
	if(sum < 10) return sum;
	else return fn(sum);
}
void eugune_and_function() {
	unsigned long long int temp,i,sumd,sum,t,a,d,l,r;
	//vector<unsigned long long int> v;
	cin>>t;
	while(t-- > 0) {
		cin>>a>>d>>l>>r;
		sum=0;
		for(i=l;i<=r;i++) {
			temp=a+(i-1)*d; //cout<<temp<<" ";
			if(temp < 10) sum+=temp;
			else {
				sum+=fn(temp);
			}
		}
		cout<<sum<<endl;
	}
}
int main() {
	// your code goes here
	//eugune_and_function(); 	// partially solved for 15 pts
	return 0;
}
