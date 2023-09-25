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

    long long ans = 1, mod = 998244353;
    map<int, int> cnt1, cnt2;
    set<int> all_num;

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        int cnt_ai;
        cin >> cnt_ai;
        all_num.insert(a[i]);
        cnt1[a[i]] = cnt_ai;
    }
    int m;
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 0; i < m; i++) {
        int cnt_bi;
        cin >> cnt_bi;
        all_num.insert(b[i]);
        cnt2[b[i]] = cnt_bi;
    }

    for (auto num : all_num) {
        int min_val = cnt2[num], max_val = cnt1[num];
        if (min_val > max_val) {
            ans = 0;
            break;
        }
        if (min_val != max_val)
            ans = (ans * 2LL) % mod;
    }

    cout << ans << endl;

    return 0;
}
