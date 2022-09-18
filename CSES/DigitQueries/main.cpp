#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    long long k;
    cin >> q;
    while (q--) {
        cin >> k;
        long long ns = 1, ans, p10 = 1;
        while (ns * 9 * p10 <= k) {
            k -= (ns * 9 * p10);
            ns++;
            p10 *= 10;
        }
        ans = p10;
        ans += ((k / ns) - 1);
        if (k % ns == 0)
            ans = ans % 10;
        else {
            string tmp = to_string(ans + 1);
            ans = tmp[(k % ns) - 1] - '0';
        }
        cout << ans << endl;
    }

    return 0;
}
