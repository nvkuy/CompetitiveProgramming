#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        if (n > m)
            swap(n, m);
        if (n == 1 && m > 2) {
            cout << "-1" << endl;
            continue;
        }
        long long ans = 0;
        ans = (n - 1) * 2 + (m - n) * 2;
        if ((m - n) % 2)
            ans--;
        cout << ans << endl;
    }

    return 0;
}
