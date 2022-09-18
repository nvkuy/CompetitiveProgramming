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
        int oc = 0, ec = 0, opGetOdd = 1e9;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2) {
                oc++;
                opGetOdd = 0;
            } else {
                ec++;
                int tc = 0;
                while (a[i] % 2 == 0) {
                    a[i] /= 2;
                    tc++;
                }
                opGetOdd = min(opGetOdd, tc);
            }
        }
        int ans = opGetOdd + ec;
        if (oc == 0)
            ans--;
        cout << ans << endl;
    }

    return 0;
}
