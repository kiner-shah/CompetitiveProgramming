#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <stack>
#define MOD 1000000007
using namespace std;
typedef long long LL;
template<typename T> inline T Max(T a, T b) { return (a > b ? a : b); }
template<typename T> inline bool comp(T a, T b) { return a < b; }
inline LL gcd(LL a,LL b) { while(b>0) { b^=(a^=(b^=(a%=b))); } return a; }
inline LL power(int a, int b) { if(b == 0) return 1; if(b == 1) return a; if(b%2 == 0) return power(a*a,b/2); else return a * power(a*a,(b-1)/2); }
LL mpower(LL a, LL b) {
    if(b == 0) return 1;
    else if(b == 1) return a;
    else if(b%2 == 0) {
        LL bb = mpower(a,b/2) * mpower(a,b/2);
        if(bb >= MOD) return bb % MOD;
        else return bb;
    }
    else {
        LL bb = a * mpower(a,b/2) * mpower(a,b/2);
        if(bb >= MOD) return bb % MOD;
        else return bb;
    }
}
void smart_phone() {
	int n, i = 0, pos = 0;
    cin>>n;
    LL budget[n];
    while(i < n) { cin>>budget[i]; i++; }
    sort(budget, budget + n); i = 0;
    unsigned long long max1 = 0;
    while(i < n) { 
        unsigned long long cost = budget[i] * (n - pos); 
        if(cost > max1) { max1 = cost; }
        i++; pos++;
    }
    cout<<max1;
}
void video_game() {
	int i, n; LL h;
    cin>>n>>h;
    LL stack[n];
    for(i = 0; i < n; i++) cin>>stack[i];
    // 1 - Left, 2 - Right, 3 - Pick, 4 - Drop, 0 - Quit
    int x, pos = 0; bool box = false;
    while(true) {
        cin>>x;
        if(x == 0) break;
        if(x == 1) { if(pos > 0) pos--; }
        else if(x == 2) { if(pos < n - 1) pos++; }
        else if(x == 3) { 
            if(!box) {
                if(stack[pos] - 1 >= 0) {
                    stack[pos]--; 
                    box = true;
                }
            }
        }
        else if(x == 4) { 
            if(box) {
                if(stack[pos] + 1 <= h) {
                    stack[pos]++; 
                    box = false;
                }
            }
        }
        //for(i = 0; i < n; i++) cout<<stack[i]<<" "; cout<<"\t"<<box<<endl;
    }
    for(i = 0; i < n; i++) cout<<stack[i]<<" ";
}
void tournament() {
	long int i, n;
    cin>>n;
    long int a[n];
    long long suml = 0, sums = 0, sum = 0;
    for(i = 0; i < n; i++) { cin>>a[i]; suml += a[i]; }
    sort(a, a + n);
    for(i = 0; i < n; i++) {
        sums += a[i];
        sum += (suml - sums - a[i] * (n - i - 1));
    }
    cout<<sum;
}
void variation() {
	int i, j, n; LL k;
    cin>>n>>k;
    LL a[n];
    for(i = 0; i < n; i++) cin>>a[i];
    sort(a, a + n);
    LL sum = 0;
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            LL val = abs(a[i] - a[j]);
            if(val >= k) { sum += n - j; break; }
        }
    }
    cout<<sum;
}
void chewing() {
	int i, j, n; LL k;
    cin>>n>>k;
    LL a[n], count = 0;
    map<LL, int> counts;
    vector<LL> simplified;
    for(i = 0; i < n; i++) {
        cin>>a[i];
        if(a[i] < k) {
            //counts.insert(make_pair(a[i], 1));
            simplified.push_back(a[i]);
        }

    }
    sort(simplified.begin(), simplified.end());
    int l = simplified.size();
    /*for(i = 0; i < l; i++) {
        int val = counts[simplified[i]];
        if(val > 1 && simplified[i] * 2 < k) count += (val * (val - 1)) / 2;
    }*/
    int ll = 0, rr = l - 1;
    while(ll < rr) {
        if(simplified[ll] + simplified[rr] < k) { count += (rr - ll); ll++; }
        else rr--;
    }
    cout<<count;
}
void matched_brackets() {
	int n, max1 = -1, max2 = -1, spos1 = -1, pos1 = -1, pos = -1, cnt = 0, x;
	bool flag = false;
	cin >> n;
	stack<int> st;
	for(int i = 0; i < n; i++) {
		cin >> x;
		if(x == 1) {
			st.push(i);
			if(cnt == 0) spos1 = i;
			cnt++;
		}
		else if(x == 2) {
			if(max1 < (int) st.size()) {
				flag = true;
				max1 = st.size();
				pos = st.top();
			}
			cnt++;
			// cout << cnt << " " << max2 << " " << pos1 << endl;
			if(st.size() == 1) {
				if(cnt > max2) {
					max2 = cnt;
					pos1 = spos1;
				}
				cnt = 0;
			}
			st.pop();
		}
	}
	cout << max1 << " " << pos + 1 << " " << max2 << " " << pos1 + 1;
}
int main() {
    // your code goes here
    // smart_phone();
	// video_game();
	// tournament();
	// variation();
	// chewing();
	// matched_brackets();
    return 0;
}
