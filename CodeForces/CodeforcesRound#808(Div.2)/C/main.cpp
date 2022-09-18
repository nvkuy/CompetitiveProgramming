#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool check(int q, int p, vector<int> &a) {
    for (int i = p; i < a.size(); i++) {
        if (a[i] > q)
            q--;
    }
    return q >= 0;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, q;
    cin >> t;
    while (t--) {
        cin >> n >> q;
        vector<int> a(n), ans(n, 0);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int l = 0, r = n - 1, m;
        while (l < r) {
            m = (l + r) / 2;
            if (check(q, m, a))
                r = m;
            else
                l = m + 1;
        }
        for (int i = 0; i < r; i++) {
            if (a[i] <= q)
                ans[i]++;
        }
        for (int i = r; i < n; i++) {
            if (q == 0)
                break;
            ans[i]++;
        }
        for (int i = 0; i < n; i++)
            cout << ans[i];
        cout << endl;
    }

    return 0;
}
