#include <bits/stdc++.h>

using namespace std;

int main()
{

    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);

    long long k, n, x;
    vector<long long> f(1e5, 0);
    for (int i = 1; i <= 1e5; i++)
        f[i] = f[i - 1] + i;
    cin >> k >> n;
    while (n--) {
        cin >> x;
        long long ans = 0;
        long long max_speed = 0;
        for (int i = 1; i <= 1e5; i++) {
            long long dis = f[i];
            if (i > x) dis += (f[i - 1] - f[x - 1]);
            if (dis > k)
                break;
            max_speed = i;
        }
        long long dis = f[max_speed];
        ans += max_speed;
        if (max_speed > x) {
            dis += (f[max_speed - 1] - f[x - 1]);
            ans += (max_speed - x);
        }
        long long rm = k - dis;
        while (rm > 0) {
            ans += (rm / max_speed);
            rm %= max_speed;
            max_speed--;
        }
        cout << ans << endl;
    }

    return 0;
}
