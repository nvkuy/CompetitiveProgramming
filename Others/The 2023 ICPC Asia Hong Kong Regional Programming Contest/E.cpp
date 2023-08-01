#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, k;
    cin >> n >> k;
    vector<int> a(n), pos(1e6 + 1, 0);
    vector<vector<int>> b(1e6 + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]].push_back(i);
    }

    long long ans = 0, availL = 0;
    for (int i = 0; i < n; i++) {
        if (b[a[i]].size() - pos[a[i]] < k)
            availL++;
        else {
            long long last = n - 1;
            if (b[a[i]].size() - pos[a[i]] > k)
                last = b[a[i]][pos[a[i]] + k] - 1;
            ans += (availL + 1LL) * (last - b[a[i]][pos[a[i]] + k - 1] + 1LL);
            // cout << i << ' ' << availL + 1 << ' ' << last - b[a[i]][pos[a[i]] + k - 1] + 1LL << endl;
        }
        pos[a[i]]++;
        // cout << i << ' ' << availL << endl;
    }

    cout << (n * (n + 1LL)) / 2LL - ans << endl;

    return 0;
}
