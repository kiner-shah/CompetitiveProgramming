#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

void new_year_party() {
	int n,c=0;
    cin >> n;
    vector<int> t(n);
    cin>>t[0]; c=t[0];
    for(int i = 1;i < n;i++){
       cin >> t[i];
    }
    for(int i=1;i<n;i++) {
        if(t[i] <= c) c++;
        else if(t[i] > c) c+=(t[i]-c); 
    }
    cout<<c;
}
int main() {
    // new_year_party();
    return 0;
}
