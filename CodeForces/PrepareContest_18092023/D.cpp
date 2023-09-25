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

int n, k;
vector<int> a;

pair<int, int> findPair(int x) {
    map<int, vector<int>> mask_pos;
    for (int i = 0; i < n; i++) {
        int mask = 0;
        for (int j = 0; j < k; j++) {
            if ((x >> j) & 1)
                mask ^= (((a[i] >> j) & 1) << j);
        }
        auto &pos = mask_pos[mask];
        if (pos.size() < 2) pos.push_back(i);
    }
    for (auto &p : mask_pos) {
        if (p.second.size() > 1)
            return {p.second[0], p.second[1]};
    }
    return {-1, -1};
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        a.resize(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int x = 0;
        for (int i = k - 1; i >= 0; i--) {
            x ^= (1 << i);
            auto tmp = findPair(x);
            if (tmp.first == -1)
                x ^= (1 << i);
        }
        auto res = findPair(x);
        for (int i = 0; i < k; i++) {
            if (((a[res.first] >> i) & 1) == ((a[res.second] >> i) & 1) && ((a[res.first] >> i) & 1) == 1)
                x ^= (1 << i);
        }
        cout << res.first + 1 << ' ' << res.second + 1 << ' ' << x << endl;
    }

    return 0;
}
