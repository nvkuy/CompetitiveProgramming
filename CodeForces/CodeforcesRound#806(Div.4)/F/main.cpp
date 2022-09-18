#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool isInv(int ai, int i) {
    if (ai < i)
        return true;
    return false;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n + 1), ps(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        long long ans = 0;
        ps[1] = ps[0] = 0;
        for (int i = 2; i <= n; i++) {
            ps[i] = ps[i - 1] + isInv(a[i - 1], i - 1);
            if (isInv(a[i], i))
                ans += ps[a[i]];
        }
        cout << ans << endl;
    }

    return 0;
}
