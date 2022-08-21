#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n, k;
vector<int> a;

bool check(int l, int r) {
    for (int i = 0; i < n; i++) {
        if (a[i] < l)
            return false;
        if (a[i] / k > r)
            return false;
        if (l == 0)
            continue;
        int tmp = a[i] / l;
        if (a[i] / tmp > r)
            return false;
    }
    return true;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        a.resize(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int ans = 1e9;
        for (int i = 0; i <= 3000; i++) {
            int l = i, r = 3000, m;
            while (l < r) {
                m = (l + r) / 2;
                if (check(i, m))
                    r = m;
                else
                    l = m + 1;
            }
            //cout << i << '|' << r - i << endl;
            if (check(i, r))
                ans = min(ans, r - i);
        }
        cout << ans << endl;
    }

    return 0;
}
