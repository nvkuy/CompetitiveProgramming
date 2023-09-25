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

    int t;
    cin >> t;
    while (t--) {
        int n, full_xor = 0, xor_one = 0;
        cin >> n;
        vector<int> pf_xor(n + 1, 0), a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            full_xor ^= a[i];
            pf_xor[i] ^= (pf_xor[i - 1] ^ a[i]);
        }
        string s;
        cin >> s;
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '1')
                xor_one ^= a[i];
        }
        int q;
        cin >> q;
        while (q--) {
            int type;
            cin >> type;
            if (type == 1) {
                int l, r;
                cin >> l >> r;
                xor_one ^= (pf_xor[r] ^ pf_xor[l - 1]);
                continue;
            }
            int b;
            cin >> b;
            cout << (b ? xor_one : (full_xor ^ xor_one)) << ' ';
        }
        cout << endl;
    }

    return 0;
}
