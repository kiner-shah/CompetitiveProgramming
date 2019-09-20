#include <iostream>
using namespace std;

void two_vs_ten() {
	int t;
    long long int n;
    cin >> t;
    while(t-- > 0) {
        cin >> n;
        if(n % 10 == 0) cout << 0 << endl;
        else if(n % 5 == 0) cout << 1 << endl;
        else cout << -1 << endl;
    }
}
int main() {    
    // two_vs_ten();
    return 0;
}
