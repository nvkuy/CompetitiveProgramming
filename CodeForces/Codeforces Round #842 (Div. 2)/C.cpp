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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a;
        vector<int> p(n, -1), q(n, -1);
        set<int> s1, s2;
        for (int i = 0; i < n; i++) {
            int ai;
            cin >> ai;
            a.push_back({ai, i});
            s1.insert(i + 1);
            s2.insert(i + 1);
        }
        sort(a.begin(), a.end());
        bool iok = true;
        for (int i = 0; i < n; i++) {
            if (!iok) break;
            auto it1 = s1.find(a[i].first);
            if (it1 != s1.end()) {
                p[a[i].second] = a[i].first;
                s1.erase(it1);
                q[a[i].second] = *s2.begin();
                s2.erase(s2.begin());
                continue;
            }
            auto it2 = s2.find(a[i].first);
            if (it2 == s2.end()) {
                iok = false;
                continue;
            }
            q[a[i].second] = a[i].first;
            s2.erase(it2);
            p[a[i].second] = *s1.begin();
            s1.erase(s1.begin());
        }
        for (int i = 0; i < n; i++) {
            if (max(q[a[i].second], p[a[i].second]) != a[i].first)
                iok = false;
        }
        if (!iok) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for (int ai : p) cout << ai << ' ';
        cout << endl;
        for (int ai : q) cout << ai << ' ';
        cout << endl;
    }

    return 0;
}
