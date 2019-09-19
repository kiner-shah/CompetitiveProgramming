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
#define MAX 100000
using namespace std;

void emmas_notebook() {
	int t;
    cin >> t;
    // your code goes here
    long int temp,i,sum;
    temp=1; sum=1;
    for(i=1;i<t;i++) {
        if(i%2 == 1)
            temp=temp+1;
        else
            temp=temp;
        sum+=temp;
    }
    cout<<sum<<endl;
}
void save_quantumland() {
	int t,i;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n,c=0;
        cin >> n;
        vector<int> a(n);
        for(int a_i = 0;a_i < n;a_i++){
           cin >> a[a_i];
        }
        for(i=1;i<n-1;i+=2) {
            if((a[i] == 0 && a[i-1] == 0) && (a[i] == 0 && a[i+1] == 1)) {
                a[i-1]=1; c++;
            }    
            else if((a[i]==0 && a[i+1]==0) && (a[i]==0 && a[i-1]==1)) {
                a[i+1]=1; c++;
            }
            else if(a[i]==0 && (a[i-1]==0 && a[i+1] ==0)) {
                a[i]=1; c++;
            }
       }
        if(n%2 == 0) {
            if(a[i]==0 && a[i-1]==0) c++;
        }
        cout<<c<<endl;
    }
}
int main(){
    // emmas_notebook();
	// save_quantumland();
    return 0;
}
