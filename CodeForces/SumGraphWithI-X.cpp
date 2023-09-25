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

map<pair<int, int>, int> f;
int n;

int query1(int x) {
    assert(x >= 2 && x <= 2 * n);
    f.clear();
    cout << "+ " << x << endl;
    cout.flush();
    int rp;
    cin >> rp;
    return rp;
}

int query2(int i, int j) {
    assert(min(i, j) > 0 && max(i, j) <= n);
    if (i == j) return 0;
    if (f[{i, j}] != 0) return f[{i, j}];
    cout << "? " << i << ' ' << j << endl;
    cout.flush();
    int rp;
    cin >> rp;
    f[{i, j}] = f[{j, i}] = rp;
    return rp;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n == 2) {
            cout << "! 1 2 2 1" << endl;
            cout.flush();
            int rp;
            cin >> rp;
            if (rp != 1) break;
            continue;
        }
        vector<int> s1, s2;
        if (query1(2) != 1) break; // two color => set odd, set even
        vector<pair<int, int>> dist_pos;
        for (int i = 1; i <= n; i++) {
            int dist = query2(1, i);
            if (dist == -1) s2.push_back(i);
            else {
                s1.push_back(i);
                dist_pos.push_back({dist, i});
            }
        }
        assert((abs((int)s1.size() - (int)s2.size()) <= 1));
        if (n == 3) {
            if (s1.size() < s2.size()) swap(s1, s2);
            vector<int> ans(n + 1);
            ans[s1[0]] = 1, ans[s1[1]] = 3, ans[s2[0]] = 2;
            cout << "! ";
            for (int i = 1; i <= 3; i++) cout << ans[i] << ' ';
            ans[s1[1]] = 1, ans[s1[0]] = 3;
            for (int i = 1; i <= 3; i++) cout << ans[i] << ' ';
            cout << endl;
            cout.flush();
            int rp;
            cin >> rp;
            if (rp != 1) break;
            continue;
        }
        sort(dist_pos.begin(), dist_pos.end(), greater<pair<int, int>>()); // find end point set 1
        vector<pair<int, int>> order1;
        for (int i = 0; i < dist_pos.size(); i++) {
            int dist = query2(dist_pos[0].second, dist_pos[i].second);
            order1.push_back({dist, dist_pos[i].second});
        }
        sort(order1.begin(), order1.end()); // ordered set 1
        if (query1(n - 1 - (n % 2)) != 1) break; // connect oposite endpoint of two set
        vector<pair<int, int>> order2;
        for (int node : s2) {
            int dist = query2(order1[0].second, node);
            order2.push_back({dist, node});
        }
        sort(order2.begin(), order2.end()); // ordered set 2
        if (n % 2) {
            if (order1.size() < order2.size())
                swap(order1, order2);
            reverse(order2.begin(), order2.end());
            // assert(order1.size() + order2.size() == n && order1.size() - order2.size() == 1);
            cout << "! ";
            vector<int> ans(n + 1);
            int cur = 1;
            for (auto node : order1) {
                ans[node.second] = cur;
                cur += 2;
            }
            cur = 2;
            for (auto node : order2) {
                ans[node.second] = cur;
                cur += 2;
            }
            for (int i = 1; i <= n; i++) {
                cout << ans[i] << ' ';
                // assert(ans[i] > 0 && ans[i] <= n);
            }
            reverse(order1.begin(), order1.end());
            reverse(order2.begin(), order2.end());
            cur = 1;
            for (auto node : order1) {
                ans[node.second] = cur;
                cur += 2;
            }
            cur = 2;
            for (auto node : order2) {
                ans[node.second] = cur;
                cur += 2;
            }
            for (int i = 1; i <= n; i++) {
                cout << ans[i] << ' ';
                // assert(ans[i] > 0 && ans[i] <= n);
            }
            cout << endl;
            cout.flush();
        } else {
            if (query2(order1[0].second, order2[0].second) != 1)
                reverse(order1.begin(), order1.end());
            reverse(order2.begin(), order2.end());
            // assert(order1.size() + order2.size() == n && order1.size() == order2.size());
            cout << "! ";
            vector<int> ans(n + 1);
            int cur = 1;
            for (auto node : order1) {
                ans[node.second] = cur;
                cur += 2;
            }
            cur = 2;
            for (auto node : order2) {
                ans[node.second] = cur;
                cur += 2;
            }
            for (int i = 1; i <= n; i++) {
                cout << ans[i] << ' ';
                // assert(ans[i] > 0 && ans[i] <= n);
            }
            cur = 2;
            for (auto node : order1) {
                ans[node.second] = cur;
                cur += 2;
            }
            cur = 1;
            for (auto node : order2) {
                ans[node.second] = cur;
                cur += 2;
            }
            for (int i = 1; i <= n; i++) {
                cout << ans[i] << ' ';
                // assert(ans[i] > 0 && ans[i] <= n);
            }
            cout << endl;
            cout.flush();
        }
        int rp;
        cin >> rp;
        if (rp != 1) break;
    }

    return 0;
}
