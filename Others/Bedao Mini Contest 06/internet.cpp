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

    int s, a, b, c;
    cin >> s >> a >> b >> c;
    vector<pair<int, int>> odd, even;
    if (a % 2 == 0) even.push_back({1, a});
    else odd.push_back({1, a});
    if (b % 2 == 0) even.push_back({2, b});
    else odd.push_back({2, b});
    if (c % 2 == 0) even.push_back({3, c});
    else odd.push_back({3, c});
    sort(odd.begin(), odd.end(), greater<pair<int, int>>());
    sort(even.begin(), even.end(), greater<pair<int, int>>());
    if (odd.size() > 1) {
        cout << "Bedao!" << endl;
        return 0;
    }
    deque<long long> ans;
    for (auto p : odd) {
        for (int i = 0; i < p.second; i++)
            ans.push_back(p.first);
    }
    for (auto p : even) {
        for (int i = 0; i < p.second / 2; i++) {
            ans.push_back(p.first);
            ans.push_front(p.first);
        }
    }
    long long mod = 727355608, num = 0, p4 = 1;
    for (int i = 0; i < ans.size(); i++) {
        num = (num + ans[i] * p4) % mod;
        p4 = (p4 * 4LL) % mod;
    }
    cout << num << endl;

    return 0;
}
