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

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    long long l = 0, r = accumulate(a.begin(), a.end(), 0), m;
    while (l < r) {
        m = (l + r + 1) / 2;
        multiset<int> canGet;
        int free = 1, i = 0;
        long long cur = 0, tans = 0;
        while (true) {
            if (i == n) break;
            while (free > 0 && i < n) {
                cur += a[i];
                canGet.insert(a[i]);
                i++, free--;
            }
            tans = max(tans, cur);
            if (tans >= m) break;
            if (canGet.size() == 0) break;
            int tmp = *canGet.begin();
            canGet.erase(canGet.begin());
            cur -= tmp;
            free += tmp;
        }
        if (tans >= m)
            l = m;
        else
            r = m - 1;
    }
    
    cout << l << endl;

    return 0;
}
