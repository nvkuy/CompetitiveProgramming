#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n, ai, ans = -1e18, cs = 0LL;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ai;
        cs += ai;
        ans = max(ans, cs);
        if (cs < 0)
            cs = 0LL;
    }
    cout << ans;

    return 0;
}
