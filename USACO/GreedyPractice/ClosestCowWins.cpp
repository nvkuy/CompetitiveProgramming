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

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int k, m, n;
    cin >> k >> m >> n;
    vector<pair<int, int>> a(k);
    vector<pair<int, int>> b;
    vector<int> c(m);
    for (int i = 0; i < k; i++) {
        cin >> a[i].first >> a[i].second;
        b.push_back(a[i]);
    }
    for (int i = 0; i < m; i++) {
        cin >> c[i];
        b.push_back({c[i], -1});
    }
    sort(b.begin(), b.end());
    vector<pair<long long, vector<int>>> cost2;
    vector<long long> cost1;
    long long cost = 0;
    vector<int> subcost;
    for (int i = 0; i < b.size(); i++) {
        if (b[i].second < 0 || i + 1 == b.size()) {
            if (subcost.size() == 0) continue;
            if (subcost.size() == 1)
                cost1.push_back(cost);
            else {
                if ((cost1.size() + cost2.size() == 0 && b[0].second >= 0) || (i + 1 == b.size() && b[i].second >= 0))
                    cost1.push_back(cost);
                else
                    cost2.push_back({cost, subcost});
            }
            cost = 0;
            subcost.clear();
        } else {
            cost += b[i].second;
            subcost.push_back(b[i].second);
        }
    }
    sort(cost1.begin(), cost1.end());
    sort(cost2.begin(), cost2.end());
    // while (true) {
    //     if ()
    // }

    return 0;
}
