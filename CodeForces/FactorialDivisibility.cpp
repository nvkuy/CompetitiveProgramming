#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)
#define low_bit(x) __builtin_ctzll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> cnt(x + 1, 0);
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        if (ai < x) cnt[ai]++;
    }
    bool iok = true;
    for (int i = 0; i < x; i++) {
        if (cnt[i] % (i + 1) != 0) {
            iok = false;
            break;
        }
        cnt[i + 1] += cnt[i] / (i + 1);
    }
    cout << (iok ? "Yes" : "No") << endl;

    return 0;
}
