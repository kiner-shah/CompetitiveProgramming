// Dictionaries and maps
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    string a, b, line;
    cin >> n;
    map<string, string> m;
    while(n-- > 0) {
        cin >> a >> b;
        m[a] = b;
    }
    getline(cin, line);
    while(getline(cin, line)) {
        if(m.find(line) != m.end()) cout << line << "=" << m[line] << endl;
        else cout << "Not found\n";
    }
    return 0;
}