// Codeforces Round #329 - Div 2
// Solved for practice after the contest ended
#include <bits/stdc++.h>
using namespace std;
// A: 2Char
void solution_a()
{
    int n;
    cin >> n;
    
    string a;
    map<string, int> total_cnt;
    set<char> s;
    int i = 0;
    while (n-- > 0) {
        cin >> a;
        map<char, int> cnt;
        // get all distinct characters and store them
        for (char x : a) {
            s.insert(x);
            cnt[x]++;
        }
        string str = "";
        int total = 0;
        for (pair<char, int> p : cnt) {
            str += p.first;
            total += p.second;
        }
        total_cnt[str] += total; 
    }
    
    int max_val = INT_MIN;
    for (auto it = s.begin(); it != s.end(); it++) {
        for (auto it1 = it; it1 != s.end(); it1++) {
            stringstream ss;
            ss << *it;
            string one = ss.str();
            ss.str("");
			
            if (*it == *it1) max_val = max(max_val, total_cnt[one]);
            else {
                ss << *it << *it1;
                string temp = ss.str();
                ss.str("");
				
                ss << *it1;
                string two = ss.str();
                ss.str("");
				
                int tot = total_cnt[one] + total_cnt[two] + total_cnt[temp];
                max_val = max(max_val, tot);
            }
        }
    }
    cout << max(max_val, 0) << endl;
}
int main()
{
    solution_a();
    return 0;
}
