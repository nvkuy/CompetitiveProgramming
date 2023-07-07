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

    vector<pair<int, int>> lr(8);
    lr[1] = {1, 9};
    for (int i = 2; i < 8; i++)
        lr[i] = {lr[i - 1].first * 10, lr[i - 1].second * 10 + 9};

    int t;
    cin >> t;
    while (t--) {

        long long a, b, c, k;
        cin >> a >> b >> c >> k;

        long long ansA = -1, ansB = -1;
        for (int i = lr[a].first; i <= lr[a].second; i++) {

            long long low = max(lr[b].first, lr[c].first - i), high = min(lr[b].second, lr[c].second - i);
            long long have = max(high - low + 1, 0LL);
            if (have < k) {
                k -= have;
                continue;
            }
            ansA = i, ansB = low + k - 1;
            break;

        }

        if (ansA == -1) {
            cout << -1 << endl;
            continue;
        }
        cout << ansA << " + " << ansB << " = " << ansA + ansB << endl;

    }

    return 0;
}
