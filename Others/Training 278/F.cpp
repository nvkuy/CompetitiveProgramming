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

    long long n, d, c;
    cin >> n >> d >> c;

    if (d == 0) {
        cout << "YES" << endl;
        return 0;
    }

    vector<int> com;
    vector<vector<int>> ans(n + 1);
    for (int i = 1; i <= (c - 1) * (d + 1); i++) {
        com.push_back(i);
        if (com.size() <= d) continue;
        for (int n1 : com)
            for (int n2 : com)
                if (n1 != n2) ans[n1].push_back(n2);
        com.clear();
    }
    for (int i = (c - 1) * (d + 1) + 1; i <= n; i++) com.push_back(i);
    if (com.size() <= d) {
        cout << "No" << endl;
        return 0;
    }
    if (com.size() > 1 && d == 0) {
        cout << "No" << endl;
        return 0;
    }
    if (d == 1) {
        if (n > 2) {
            cout << "No" << endl;
            return 0;
        }
        ans[com[0]].push_back(com[1]);
        ans[com[1]].push_back(com[0]);
    } else {
        vector<int> cnt(n + 1, 2);
        for (int i = 1; i < com.size(); i++) {
            ans[com[i]].push_back(com[i - 1]);
            ans[com[i - 1]].push_back(com[i]);
        }
        ans[com[0]].push_back(com.back());
        ans[com.back()].push_back(com[0]);

        set<int> avai;
        if (d > 1) avai.insert(com.begin(), com.end());
        for (int n1 : com) {
            if (cnt[n1] < d) avai.erase(n1);
            auto it = avai.begin();
            while (true) {
                if (cnt[n1] == d) break;
                if (it == avai.end()) break;
                int n2 = *it;
                if (abs(n1 - n2) > 1 && !(n1 == com[1] && n2 == com.back()) && !(n2 == com[1] && n1 == com.back())) {
                    ans[n1].push_back(n2);
                    ans[n2].push_back(n1);
                    cnt[n1]++, cnt[n2]++;
                    // cout << n1 << ' ' << n2 << endl;
                }
                if (cnt[n2] == d)
                    it = avai.erase(it);
                else
                    it++;
            }
        }
    }

    cout << "Yes" << endl;
    for (int i = 1; i <= n; i++) {
        sort(ans[i].begin(), ans[i].end());
        for (int node : ans[i])
            cout << node << ' ';
        cout << endl;
    }
        

    return 0;
}
