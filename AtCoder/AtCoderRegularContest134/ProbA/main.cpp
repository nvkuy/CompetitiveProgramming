#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, l, w;
    cin >> n >> l >> w;
    vector<long long> a(n + 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a[n] = l;
    long long pc = 0LL, ans = 0LL, cor = a[0] + w;
    int ps = 0;
    for (int i = 1; i <= n; i++) {
        if (cor > a[i]) {
            if (i < n) {
                if (cor > a[i + 1])
                    continue;
            }
            pc += (a[i] - a[ps]);
            ps = i;
            cor = a[i] + w;
        } else {
            pc += (a[i] - a[ps]);
            ps = i;
            ans += ((a[i] - cor) / w);
            if ((a[i] - cor) % w > 0)
                ans++;
            cor = a[i] + w;
        }
    }
    l -= pc;
    ans += (l / w);
    if (l % w > 0)
        ans++;
    cout << ans << endl;

    return 0;
}
