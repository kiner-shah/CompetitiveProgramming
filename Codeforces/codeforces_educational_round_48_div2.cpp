/*
 * File:   codeforces_educational_round_48_div2.cpp
 * Author: Kiner Shah
 *
 * Created on 03 August, 2018, 20:03 PM
 */
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
template<typename T> inline T Max(T a, T b) { return (a > b ? a : b); }
template<typename T> inline bool comp(T a, T b) { return a < b; }
static LL gcd(LL a,LL b) { while(b>0) { b^=(a^=(b^=(a%=b))); } return a; }
static LL power(int a, int b) {
    if(b == 0) return 1;
    if(b == 1) return a;
    if(b%2 == 0) return power(a*a,b/2);
    else return a * power(a*a,(b-1)/2);
}
static void swap(char &a, char &b) { char temp = a; a = b; b = temp; }
void death_note() {
    int n; LL m, x, sum = 0, prev = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> x;
        sum += x;
        cout << /*sum / m << " " << prev << " " <<*/ sum / m  - prev << " ";
        prev = sum / m;
    }
}
void segment_occurences() {
    int l, r, n, m, q;
    cin >> n >> m >> q;
    string s, t;
    cin >> s >> t;
    size_t pos = s.find(t, 0);
    vector<int> pos_vec;
    while(pos != string::npos) {
        pos_vec.push_back(pos + 1);
        pos = s.find(t, pos + 1);
    }
    while(q-- > 0) {
        cin >> l >> r;
//        cout << l << " " << r << endl;
        int cnt = 0;
        for(int x : pos_vec) {
//            cout << x << " ";
            if(x >= l && x + t.length() - 1 <= r)
                cnt++;
        }
        cout << cnt << endl;
    }
}
void vasya_and_the_mushrooms() {
    int n;
    cin >> n;
    LL a[2][n], visited[2][n];
    for(int i = 0; i < 2; i++) {
        fill(visited[i], visited[i] + n, 0);
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
//    for(int i = 0; i < 2; i++)
//        for(int j = 0; j < n; j++)
//            cout << a[i][j] << " ";
    LL min = 0, x = 0, y = 0, prevx, prevy, sumprod = 0, cnt = 0;
    while(true) {
        if(visited[x][y] == 0) {
            sumprod += (min * a[x][y]);
            visited[x][y] = 1;
            cnt++;
        }
//        else { prevx = x; prevy = y; }
        if(cnt == 2 * n) break;
//        cout << sumprod << " " << min << " " << cnt << " " << x << " " << y << " " << a[x][y] << endl;
        if(x == 0 && y == 0) {
            if(a[x][y + 1] < a[x + 1][y]) {
                if(visited[x][y + 1] == 0) y++;
                else if(visited[x + 1][y] == 0) x++;
            }
            else {
                if(visited[x + 1][y] == 0) x++;
                else if(visited[x][y + 1] == 0) y++;
            }
        }
        else if(x == 1 && y == 0) {
            if(a[x][y + 1] < a[x - 1][y]) {
                if(visited[x][y + 1] == 0) y++;
                else if(visited[x - 1][y] == 0) x--;
            }
            else {
                if(visited[x - 1][y] == 0) x--;
                else if(visited[x][y + 1] == 0) y++;
            }
        }
        else if(x == 0 && y == n - 1) {
            if(a[x][y - 1] < a[x + 1][y]) {
                if(visited[x][y - 1] == 0) y--;
                else if(visited[x + 1][y] == 0) x++;
            }
            else {
                if(visited[x + 1][y] == 0) x++;
                else if(visited[x][y - 1] == 0) y--;
            }
        }
        else if(x == 1 && y == n - 1) {
            if(a[x][y - 1] < a[x - 1][y]) {
                if(visited[x][y - 1] == 0) y--;
                else if(visited[x - 1][y] == 0) x--;
            }
            else {
                if(visited[x - 1][y] == 0) x--;
                else if(visited[x][y - 1] == 0) y--;
            }
        }
        else if(x == 0 && y < n - 1) {
            if(a[x][y + 1] < a[x + 1][y] && a[x][y + 1] < a[x][y - 1]) {
                if(visited[x][y + 1] == 0) y++;
                else if(a[x + 1][y] < a[x][y - 1] && visited[x + 1][y] == 0) x++;
                else if(visited[x][y - 1] == 0) y--;
            }
            else if(a[x + 1][y] < a[x][y + 1] && a[x + 1][y] < a[x][y - 1]) {
                if(visited[x + 1][y] == 0) x++;
                else if(a[x][y + 1] < a[x][y - 1] && visited[x][y + 1] == 0) y++;
                else if(visited[x][y - 1] == 0) y--;
            }
            else if(a[x][y - 1] < a[x + 1][y] && a[x][y - 1] < a[x][y + 1]) {
                if(visited[x][y - 1] == 0) y--;
                else if(a[x + 1][y] < a[x][y + 1] && visited[x + 1][y] == 0) x++;
                else if(visited[x][y + 1] == 0) y++;
            }
        }
        else if(x == 1 && y < n - 1) {
            if(a[x][y + 1] < a[x - 1][y] && a[x][y + 1] < a[x][y - 1]) {
                if(visited[x][y + 1] == 0) y++;
                else if(a[x - 1][y] < a[x][y - 1] && visited[x - 1][y] == 0) x--;
                else if(visited[x][y - 1] == 0) y--;
            }
            else if(a[x - 1][y] < a[x][y + 1] && a[x - 1][y] < a[x][y - 1]) {
                if(visited[x - 1][y] == 0) x--;
                else if(a[x][y + 1] < a[x][y - 1] && visited[x][y + 1] == 0) y++;
                else if(visited[x][y - 1] == 0) y--;
            }
            else if(a[x][y - 1] < a[x - 1][y] && a[x][y - 1] < a[x][y + 1]) {
                if(visited[x][y - 1] == 0) y--;
                else if(a[x - 1][y] < a[x][y + 1] && visited[x - 1][y] == 0) x--;
                else if(visited[x][y + 1] == 0) y++;
            }
        }
        min++;
    }
    cout << sumprod;
}
int main() {
//    death_note(); // Problem A
//    segment_occurences(); // Problem B
   vasya_and_the_mushrooms(); // Problem C // Unsolved
   return 0;
}
