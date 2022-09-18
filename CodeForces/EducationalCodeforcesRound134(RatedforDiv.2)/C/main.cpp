#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int findL(int ai, vector<int> &b) {
    int l = 0, r = b.size() - 1, m;
    while (l < r) {
        m = (l + r) / 2;
        if (b[m] >= ai)
            r = m;
        else
            l = m + 1;
    }
    return r;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        vector<pair<int, int>> f(n);
        int free = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (free > 0)
                f[i].second = f[i + 1].second;
            else
                f[i].second = i;
            f[i].first = findL(a[i], b);
            free = i - f[i].first;
        }
        for (int i = 0; i < n; i++)
            cout << b[f[i].first] - a[i] << ' ';
        cout << endl;
        for (int i = 0; i < n; i++)
            cout << b[f[i].second] - a[i] << ' ';
        cout << endl;
    }

    return 0;
}
