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

struct pos {
    vector<int> odd, even;
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> pre_xor(n + 1, 0), a(n + 1), pre_zero(n + 1, 0);
    map<int, pos> xor_pos;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre_xor[i] = pre_xor[i - 1] ^ a[i];
        pre_zero[i] = pre_zero[i - 1] + (a[i] == 0);
        if (i % 2)
            xor_pos[pre_xor[i]].odd.push_back(i);
        else
            xor_pos[pre_xor[i]].even.push_back(i);
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (pre_zero[r] - pre_zero[l - 1] == r - l + 1) {
            cout << 0 << endl;
            continue;
        }
        if ((pre_xor[r] ^ pre_xor[l - 1]) != 0) {
            cout << -1 << endl;
            continue;
        }
        if ((r - l + 1) % 2 || a[l] == 0 || a[r] == 0) {
            cout << 1 << endl;
            continue;
        }
        if (l % 2) {
            auto it = upper_bound(xor_pos[pre_xor[l - 1]].odd.begin(), xor_pos[pre_xor[l - 1]].odd.end(), l);
            if (it == xor_pos[pre_xor[l - 1]].odd.end() || *it > r) {
                cout << -1 << endl;
                continue;
            }
        } else {
            auto it = upper_bound(xor_pos[pre_xor[l - 1]].even.begin(), xor_pos[pre_xor[l - 1]].even.end(), l);
            if (it == xor_pos[pre_xor[l - 1]].even.end() || *it > r) {
                cout << -1 << endl;
                continue;
            }
        }
        cout << 2 << endl;
    }

    return 0;
}
