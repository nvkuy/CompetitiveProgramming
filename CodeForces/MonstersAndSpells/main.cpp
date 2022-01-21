#include <bits/stdc++.h>

using namespace std;

long long calda(long long s, long long f) {
    return (s + f) * (f - s + 1) / 2;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<long long> k(n + 1), h(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> k[i];
        for (int i = 1; i <= n; i++)
            cin >> h[i];
        long long ans = 0LL;
        long long cx = 0LL, ct = 0LL;
        for (int i = 1; i <= n; i++) {
            if (ct < k[i] - h[i] + 1) {
                cx = 1;
                ct = k[i] - h[i] + 1;
            }
            ans += calda(cx, cx + (k[i] - ct + 1));
            cx += (k[i] - ct + 1);
            ct = k[i];
            //cout << ans << '|' << cx << '|' << ct << endl;
        }
        cout << ans << endl;
    }

    return 0;
}
