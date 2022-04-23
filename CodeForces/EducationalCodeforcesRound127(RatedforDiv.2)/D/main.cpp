#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, x, n;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        vector<int> a(n);
        int amax = 0, amin = 1e9;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            amax = max(amax, a[i]);
            amin = min(amin, a[i]);
        }
        int l1 = 1, r1 = max(1, amin - 1), l2 = min(amax + 1, x), r2 = x;


    }

    return 0;
}
