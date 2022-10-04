#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

vector<int> nextc, dd;

int dfs(int u) {
    dd[u] = 1;
    if (nextc[u] == -1)
        return 1e6;
    if (dd[nextc[u]] == 1)
        return 1;
    return 1 + dfs(nextc[u]);
}

bool isValid(int root) {
    dd.assign(26, 0);
    return dfs(root) >= 26;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        getline(cin, s);
        nextc.assign(26, -1);
        string ans;
        vector<int> used(26, 0);
        for (char c : s) {
            if (nextc[c - 'a'] == -1) {
                for (int i = 0; i < 26; i++) {
                    if (used[i] == 1)
                        continue;
                    nextc[c - 'a'] = i;
                    if (isValid(i)) {
                        used[i] = 1;
                        break;
                    }
                    nextc[c - 'a'] = -1;
                }
            }
            ans.push_back(nextc[c - 'a'] + 'a');
        }
        cout << ans << endl;
    }

    return 0;
}
