#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n % 2 == 1 || n < 4) {
            cout << "-1" << endl;
            continue;
        }
        n /= 2LL;
        long long ans1, ans2;
        if (n % 2 == 1)
            ans1 = ((n - 3) / 2LL) + 1LL;
        else
            ans1 = (n / 2LL);
        if (n % 3 == 0)
            ans2 = (n / 3LL);
        else if (n % 3 == 1)
            ans2 = ((n - 4) / 3LL) + 2;
        else
            ans2 = ((n - 2) / 3LL) + 1;
        cout << ans2 << ' ' << ans1 << endl;
    }

    return 0;
}
