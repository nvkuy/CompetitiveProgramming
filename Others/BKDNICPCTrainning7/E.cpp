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

    int n, preOne = 0;
    cin >> n;
    vector<int> a(n);
    queue<int> nextOne;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1)
            nextOne.push(i);
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] == 1) {
            nextOne.pop();
            preOne = i;
            ans = max(ans, 1);
            continue;
        }
        int t1 = 1e9;
        if (nextOne.size() > 0)
            t1 = nextOne.front();
        int t2 = preOne;
        ans = max(ans, min(i - t2 + (t2 != 0), t1 - i + 1));
    }
    cout << ans;

    return 0;
}