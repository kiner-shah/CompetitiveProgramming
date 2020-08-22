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
// B: Anton and Lines
void solution_b()
{
    // Editorial solution:
    // First find the y coordinates(y1, y2) for x = x1, x2
    // Then check if for two lines if y1a > y1b and y2a < y2b
    int n, x1, x2;
    cin >> n >> x1 >> x2;
    
    vector<pair<long long, long long> > y_val;  // slope and intercept
    long long k, b;
    while (n-- > 0) {
        cin >> k >> b;
        long long y1 = x1 * k + b,
            y2 = x2 * k + b;
        y_val.push_back(make_pair(y1, y2));
    }
    // sort the vector in increasing order of y1 values
    sort(y_val.begin(), y_val.end());
    size_t len = y_val.size() - 1;
    for (size_t i = 0; i < len; i++) {
        // cout << i << " " << y_val[i].first << " " << y_val[i].second << " "
        //      << y_val[i+1].first << " " << y_val[i+1].second << endl;
        if (y_val[i].first < y_val[i + 1].first
            && y_val[i].second > y_val[i + 1].second) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main()
{
//     solution_a();
//     solution_b();
    return 0;
}
