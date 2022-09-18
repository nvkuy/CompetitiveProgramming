#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int mp = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            if (mp == 0)
                mp = a[i];
            else {
                if (mp > a[i]) {
                    mp = 0;
                    ans++;
                } else
                    mp = a[i];
            }
        }
        cout << ans << endl;
    }

    return 0;
}
