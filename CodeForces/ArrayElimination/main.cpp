#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t, n, ai, cnt[30];
    cin >> t;
    while (t--) {
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++) {
            cin >> ai;
            bitset<30> bs(ai);
            for (int j = 0; j < 30; j++)
                cnt[j] += bs[j];
        }
        int ans = 0;
        for (int i = 0; i < 30; i++) {
            if (cnt[i] <= 0)
                continue;
            ans = gcd(cnt[i], ans);
        }
        for (int i = 1; i <= n; i++)
            if (ans % i == 0)
                cout << i << ' ';
        cout << endl;
    }

    return 0;
}
