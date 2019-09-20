// Codeforces: Round #478 Div. 2 
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

void aramic_script() {
	int n;
#ifndef __FILEIO__
    cin >> n;
#else 
    input >> n;
#endif
    string ss[n];
    set<string> set_s;
    for(int i = 0; i < n; i++) {
#ifndef __FILEIO__
        cin >> ss[i];
#else 
        input >> ss[i];
#endif        
    }
    for(int i = 0; i < n; i++) {
        int l = ss[i].length();
        string code = "00000000000000000000000000"; //cout << code[24] << endl;
        for(int j = 0; j < l; j++) { int pos = ss[i][j] - 'a'; code[pos] = '1'; }
        set_s.insert(code);
    }
#ifndef __FILEIO__
    cout << set_s.size();
#else 
    output << set_s.size();
#endif
}
int main() {
	// aramic_script();
	return 0;
}
