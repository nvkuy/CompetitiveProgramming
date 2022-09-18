#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long t, n, ai;
    cin >> t;
    while (t--) {
        cin >> n;
        long long ans = 1;
        while (ans < n - 1)
            ans *= 2;
        ans--;
        for (long long i = 0; i < n; i++) {
            //cout << i << '|' << ans << endl;
            cin >> ai;
            if (ai != i)
                ans &= ai;
        }
        cout << ans << endl;
    }

    return 0;
}
