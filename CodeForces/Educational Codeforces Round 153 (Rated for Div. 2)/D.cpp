#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    
    int n = s.length(), zero = n * n;
    vector<vector<int>> pf(2 * zero, vector<int>(n + 1, 1e9)), f;
    pf[zero][0] = 0;
    for (int i = 1; i <= n; i++) {
        f.assign(2 * zero, vector<int>(n + 1, 1e9));
        for (int diff = max(0, zero - i * i); diff < min(2 * zero, zero + i * i); diff++) {
            for (int preOne = 0; preOne < i; preOne++) {
                if (diff + preOne < 2 * zero) // put zero
                    f[diff + preOne][preOne] = min(f[diff + preOne][preOne], pf[diff][preOne] + (s[i - 1] != '0'));
                if (diff - (i - preOne - 1) >= 0) // put one
                    f[diff - (i - preOne - 1)][preOne + 1] = min(f[diff - (i - preOne - 1)][preOne + 1], pf[diff][preOne] + (s[i - 1] != '1'));
            }
        }
        pf = f;
    }

    int one_cnt = 0;
    for (char c : s) one_cnt += c == '1';
    assert(f[zero][one_cnt] % 2 == 0);
    cout << f[zero][one_cnt] / 2 << endl;

    return 0;
}
