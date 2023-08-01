#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

long long needDay(const vector<long long> &a, long long last) {
    if (a[0] != 1)
        return 1e18;
    long long res = 0;
    while (last > 0) {
        int pos = lower_bound(a.begin(), a.end(), last) - a.begin();
        if (pos == a.size() || a[pos] > last) pos--;
        long long cnt = (last - a[pos]) / (1LL + pos) + 1;
        res += cnt;
        last -= (1LL + pos) * cnt;
    }
    return res;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        long long l = 1, r = n * k + 1, m;
        while (l < r) {
            m = (l + r) / 2;
            if (needDay(a, m) > k)
                r = m;
            else
                l = m + 1;
        }
        cout << r << endl;
    }

    return 0;
}
