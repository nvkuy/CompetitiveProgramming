#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, l, r, ans, amax;
    cin >> t;
    while (t--) {
        cin >> l >> r;
        vector<int> a(r - l + 1);
        bool hasZero = false;
        amax = 0, ans = 0;
        for (int i = 0; i < r - l + 1; i++) {
            cin >> a[i];
            amax = max(amax, a[i]);
            if (a[i] == 0)
                hasZero = true;
        }
        if (!hasZero) {
            int highBit = 1;
            while (highBit * 2 <= amax)
                highBit *= 2;
            for (int i = 0; i < r - l + 1; i++) {
                if (a[i] >= highBit)
                    a[i] ^= highBit;
            }
            ans = highBit;
        }
        for (int i = 0; i < r - l + 1; i++) {
            bitset<22> bs(a[i]);
            if ((bs.count() <= 1) && ((ans & a[i]) == 0))
                ans += a[i];
        }
        cout << ans << endl;
        /*
        cout << "CHECK: ";
        for (int i = l; i <= r; i++)
            cout << (i ^ ans) << ' ';
        cout << endl;
        */
    }

    return 0;
}
