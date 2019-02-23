// RegEx, Patterns and Intro to Databases
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string name, email;
    regex rgx("[a-z]+[.]?[a-z]*?@gmail.com");
    vector<string> names;
    while(n-- > 0) {
        cin >> name >> email;
        if(regex_match(email, rgx)) {
            names.push_back(name);
        }
    }
    sort(names.begin(), names.end());
    for(string x : names) cout << x << endl;
    return 0;
}