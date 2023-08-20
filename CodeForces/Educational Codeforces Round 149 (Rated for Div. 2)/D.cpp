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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        set<int> open, close;
        for (int i = 0; i < n; i++) {
            if (s[i] == ')') close.insert(i);
            else open.insert(i);
        }
        if (open.size() != close.size()) {
            cout << -1 << endl;
            continue;
        }
        vector<int> color(n, 0);
        while (true) {
            if (open.size() == 0) break;
            ans++;
            int type = 0;
            if (*close.begin() < *open.begin()) type = 1;
            if (type == 0) {
                auto it1 = open.begin();
                while (true) {
                    if (it1 == open.end()) break;
                    auto it2 = close.lower_bound(*it1);
                    if (it2 == close.end()) break;
                    color[*it1] = color[*it2] = ans;
                    it1 = open.erase(it1);
                    close.erase(it2);
                }
            } else {
                auto it1 = close.begin();
                while (true) {
                    if (it1 == close.end()) break;
                    auto it2 = open.lower_bound(*it1);
                    if (it2 == open.end()) break;
                    color[*it1] = color[*it2] = ans;
                    it1 = close.erase(it1);
                    open.erase(it2);
                }
            }
        }
        cout << ans << endl;
        for (int c : color) cout << c << ' ';
        cout << endl;
    }

    return 0;
}
