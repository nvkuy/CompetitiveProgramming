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

    int n;
    cin >> n;
    vector<int> ans, fac(10, 1);
    for (int i = 1; i < 10; i++)
        fac[i] = (fac[i - 1] * i);
    while (n > 0) {
        int num = lower_bound(fac.begin(), fac.end(), n) - fac.begin();
        if (fac[num] > n)
            num--;
        ans.push_back(num);
        n -= fac[num];
    }
    sort(ans.begin(), ans.end());
    for (int i = ans.size() - 1; i >= 0; i--)
        if (ans[i] == 1) ans[i] = 0;
    if (ans[0] == 0)
        ans[0] = 1;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i];

    return 0;
}
