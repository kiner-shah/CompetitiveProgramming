// https://codeforces.com/gym/102397
// D, E are unsolved
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;

// A: Bashar and SHAWERMA!
void solution_a()
{
    int x;
    cin >> x;
    cout << x * 2 << endl;
}
// B: Calculate The Area
void solution_b()
{
    int n;
    cin >> n;
    cout << 1 << " " << n << endl;
}
// C: The Ending Point
void solution_c()
{
    int x, y;
    string s;
    cin >> x >> y >> s;
    for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
            case 'U': y++; break;
            case 'D': y--; break;
            case 'L': x--; break;
            case 'R': x++; break;
        }
    }
    cout << x << " " << y << endl;
}
// F: Weird Game
void solution_f()
{
    int n;
    cin >> n;
    if (n % 2 == 0) cout << "Mahmoud\n";
    else cout << "Bashar\n";
}
// G: Super Weird Game
void solution_g()
{
    int n, k;
    cin >> n >> k;
    int m, b;
    vector<int> cntm(k), cntb(k);
    for (int i = 0; i < n; i++) {
        cin >> m;
        if (m < k) cntm[m]++;
    }
    for (int i = 0; i < n; i++) {
        cin >> b;
        if (b < k) cntb[b]++;
    }
    int totm = 0, totb = 0;
    for (int i = 1, j = k - 1; i < j; i++, j--) {
        totm += cntm[i] * cntm[j];
        totb += cntb[i] * cntb[j];
    }
    cout << (totm > totb ? "MAHMOUD" : (totm == totb ? "DRAW" : "BASHAR")) << endl;
}
static LL mpower(LL a, LL b) {
    if(b == 0) return 1;
    else if(b == 1) return a;
    else if(b%2 == 0) {
        LL bb = mpower(a,b/2) * mpower(a,b/2);
        if(bb >= MOD) return bb % MOD;
        else return bb;
    }
    else {
        LL bb = a * mpower(a,b/2) * mpower(a,b/2);
        if(bb >= MOD) return bb % MOD;
        else return bb;
    }
}
// H: Mahmoud and the flagstones
void solution_h()
{
    int n, x;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        cin >> x;
        cnt[x]++;
    }
    LL total = n;
    for (pair<int, int> p : cnt) {
        if (p.second != 1) {
            LL val = mpower(2l, p.second) % MOD;
            val -= (1 + p.second);  // ((2^n) - 1) - n
            total += val;
        }
    }
    cout << total << endl;
}
// I: Dr.Hjjawi and the MCQ
void solution_i()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> cnt(5);
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }
    sort(cnt.begin(), cnt.end());
    cout << cnt[0] << " " << cnt[cnt.size() - 1] << endl;
}
// J: AbuTahun and Flash Memories
void solution_j()
{
    int n, x, a;
    cin >> n >> x >> a;
    // no. of solutions in one flash memory, y = floor(a / x)
    // no. of flash memories, z = floor(n / y) + (n % y == 0 ? 0 : 1);
    int y = a / x;
    if (n % y == 0) cout << n / y << endl;
    else cout << (n / y) + 1 << endl;
}
int main()
{
    // solution_a();
    // solution_b();
    // solution_c();
    // solution_f();
    // solution_g();
    // solution_h();
    // solution_i();
    // solution_j();
    return 0;
}
