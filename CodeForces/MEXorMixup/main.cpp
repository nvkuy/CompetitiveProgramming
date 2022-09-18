#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int xorOneToN(int n) {
    if (n % 4 == 0)
        return n;
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    return 0;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        int ans = a, t1 = xorOneToN(a - 1), t2;
        t2 = b ^ t1;
        if (t2 == a)
            ans += 2;
        else {
            if (t1 != b)
                ans++;
        }
        cout << ans << endl;
    }

    return 0;
}
