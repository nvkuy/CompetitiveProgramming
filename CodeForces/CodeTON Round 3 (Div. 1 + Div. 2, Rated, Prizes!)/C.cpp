#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n), b(n);
        int one_cnt = 0;
        set<int> xor_ab;
        cin >> s;
        for (int i = 0; i < n; i++) {
            a[i] = s[i] - '0';
            one_cnt += (a[i] == 1);
        }
        cin >> s;
        for (int i = 0; i < n; i++) {
            b[i] = s[i] - '0';
            xor_ab.insert(a[i] ^ b[i]);
        }
        if (xor_ab.size() > 1) {
            cout << "NO" << endl;
            continue;
        }
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; i++) {
            int flip_cnt = one_cnt;
            if (a[i] == 1) {
                ans.push_back({i, i});
                flip_cnt--;
            }
            b[i] += (flip_cnt % 2);
            b[i] %= 2;
        }
        if (b[0] == 1) {
            ans.push_back({0, 0});
            ans.push_back({1, n - 1});
            ans.push_back({0, n - 1});
        }
        cout << "YES" << endl;
        cout << ans.size() << endl;
        for (auto &p : ans)
            cout << p.first + 1 << ' ' << p.second + 1 << endl;
    }

    return 0;
}
