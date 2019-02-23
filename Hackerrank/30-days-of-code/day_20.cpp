// Sorting
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
    	cin >> a[a_i];
    }
    // Write Your Code Here
    int no_of_swaps = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i] > a[j]) {
                int temp = a[i]; a[i] = a[j]; a[j] = temp; no_of_swaps++;
            }
        }
    }
    /*
    Array is sorted in 3 swaps.
    First Element: 1
    Last Element: 3
    */
    cout << "Array is sorted in " << no_of_swaps << " swaps.\n";
    cout << "First Element: " << a[0] << endl;
    cout << "Last Element: " << a[n - 1];
    return 0;
}