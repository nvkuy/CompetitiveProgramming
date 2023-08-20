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

    int n;
    cin >> n;
    set<long long> a;
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        a.insert(ai);
    }
    long long max_val = *a.rbegin(), min_val = *a.begin();
    vector<long long> tmp;
    for (auto num : a) tmp.push_back(num * 2LL);
    a.clear();
    a.insert(tmp.begin(), tmp.end());
    long long val = 1e18, mid = min_val + max_val;
    auto it = a.lower_bound(mid);
    if (it != a.end())
        val = *it;
    if (it != a.begin()) {
        it--;
        if (abs(val - mid) >= abs(*it - mid))
            val = *it;
    }
    cout << val / 2LL << endl;

    return 0;
}
