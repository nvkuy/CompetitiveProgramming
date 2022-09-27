#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool isOk(string &t, string &s, int p) {
    for (int i = 0; i < s.size(); i++) {
        int j = p + i;
        if (j >= t.length() || t[j] != s[i])
            return false;
    }
    return true;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("in", "r", stdin);

    int q, n;
    string t;
    cin >> q;
    while (q--) {
        cin >> t;
        cin >> n;
        vector<string> ss(n);
        for (int i = 0; i < n; i++)
            cin >> ss[i];
        int p = 0, can = true;
        vector<pair<int, int>> ans;
        while (p < t.length()) {
            int maxp = p - 1, id = -1;
            for (int i = 0; i < ss.size(); i++) {
                for (int j = 0; j <= p; j++) {
                    if (!isOk(t, ss[i], j))
                        continue;
                    int k = j + ss[i].size() - 1;
                    if (maxp < k) {
                        maxp = k;
                        id = i;
                    }
                }
            }
            if (maxp < p) {
                can = false;
                break;
            }
            p = maxp + 1;
            ans.push_back({id + 1, p - ss[id].size() + 1});
        }
        if (!can) {
            cout << -1 << endl;
            continue;
        }
        cout << ans.size() << endl;
        for (auto p : ans)
            cout << p.first << ' ' << p.second << endl;
    }

    return 0;
}