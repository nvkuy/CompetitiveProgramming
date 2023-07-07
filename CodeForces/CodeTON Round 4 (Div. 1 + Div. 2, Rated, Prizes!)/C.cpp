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

    int t;
    cin >> t;
    while (t--) {
        long long n, c, d;
        cin >> n >> c >> d;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        set<int> dd;
        long long sureCost = 0;
        for (int i = 0; i < n; i++) {
            if (dd.find(a[i]) == dd.end()) {
                dd.insert(a[i]);
                continue;
            }
            sureCost += c;
        }
        vector<long long> realNum;
        for (int ai : dd) realNum.push_back(ai);
        long long optCost = c * dd.size() + d;
        for (int i = 0; i < realNum.size(); i++) {
            long long needInsert = realNum[i] - (i + 1);
            long long needDel = realNum.size() - (i + 1);
            optCost = min(optCost, needDel * c + needInsert * d);
            // cout << needDel << '|' << needInsert << endl;
        }
        cout << sureCost + optCost << endl;
    }

    return 0;
}
