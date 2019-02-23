// Mean, median and mode
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int sum = 0, n, a[2500], i;
    cin>>n;
    map<int, int> counts;
    for(i = 0; i < n; i++) {
        cin>>a[i];
        sum += a[i];
        if(counts.find(a[i]) != counts.end()) counts[a[i]]++;
        else counts.insert(make_pair(a[i], 1));
    }
    printf("%0.1f\n", (float) sum / n);
    sort(a, a + n);
    if(n % 2 == 0) {
        int b = a[n/2];
        int c = a[n/2 - 1];
        float val = (float) (c + b) / 2;
        printf("%0.1f\n", val);
    }
    else printf("%0.1f\n", (float) a[n/2]);
    int max = -100001, key;
    for(pair<int, int> p : counts) {
        int k = p.first;
        int val = p.second;
        if(val > max) {
            max = val;
            key = k;
        }
        else if(val == max && k < key) {
            key = k;
        }
    }
    printf("%d", key);
    return 0;
}
