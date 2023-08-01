#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int mod = 256;
const int base = 16;
map<char, int> f;

int toNum(char c1, char c2) {
    return (f[c1] * base + f[c2]) % mod; 
}

string hashing(int n1, int n2, int n3) {
    return to_string(n1) + "|" + to_string(n2) + "|" + to_string(n3);
}

map<string, int> cnt;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (char c = '0'; c <= '9'; c++)
        f[c] = c - '0';
    for (char c = 'A'; c <= 'F'; c++)
        f[c] = c - 'A' + 10;

    int n;
    cin >> n;
    vector<string> i1(n), i2(n);
    for (int i = 0; i < n; i++)
        cin >> i1[i];
    for (int i = 0; i < n; i++)
        cin >> i2[i];
    
    int max_cnt = 0;
    for (int i = 0; i < n; i++) {
        string tmp = hashing(
            (mod + toNum(i2[i][1], i2[i][2]) - toNum(i1[i][1], i1[i][2])) % mod, 
            (mod + toNum(i2[i][3], i2[i][4]) - toNum(i1[i][3], i1[i][4])) % mod,
            (mod + toNum(i2[i][5], i2[i][6]) - toNum(i1[i][5], i1[i][6])) % mod);
        cnt[tmp]++;
        max_cnt = max(max_cnt, cnt[tmp]);
    }

    double ans = (100.0 * max_cnt) / (1.0 * n);
    cout << setprecision(2) << fixed;
    cout << ans << "%" << endl;

    // for (auto p : cnt)
    //     cout << p.first << ' ' << p.second << endl;

    return 0;
}
