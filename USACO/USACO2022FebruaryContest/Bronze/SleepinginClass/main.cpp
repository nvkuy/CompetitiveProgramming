#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n;
vector<int> a;

int cal(int fs) {
    int cs = 0, j = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        cs += a[i];
        if (cs < fs)
            continue;
        if (cs == fs) {
            cs = 0;
            ans += (i - j);
            j = i + 1;
        } else
            break;
    }
    return ((cs == 0) ? ans : 1e9);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, am, sa;
    cin >> t;
    while (t--) {
        cin >> n;
        a.resize(n);
        am = sa = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            am = max(am, a[i]);
            sa += a[i];
        }
        int ans = n;
        for (int i = am; i <= sa; i++)
            if (i == 0 || sa % i == 0)
                ans = min(ans, cal(i));
        cout << ans << endl;
    }

    return 0;
}
