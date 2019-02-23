// Exceptions - String to Integer
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


int main(){
    string S;
    cin >> S;
    try {
        int x = stoi(S);
        cout << x;
    }
    catch(invalid_argument &e) {
        cout << "Bad String";
    }
    catch(out_of_range &e) {
        cout << "Bad String";
    }
    return 0;
}