// 2D Arrays
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> a(6);
    for (int i = 0; i < 6; i++) {
        a[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> a[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int max1 = -1000, sum;
    for(int i = 1; i < 5; i++) {
        sum = 0;
        for(int j = 1; j < 5; j++) {
            sum = a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][j + 1] + a[i][j]
                + a[i + 1][j - 1] + a[i + 1][j] + a[i + 1][j + 1];
            max1 = max(max1, sum);
        }
    }
    cout << max1;
    return 0;
}