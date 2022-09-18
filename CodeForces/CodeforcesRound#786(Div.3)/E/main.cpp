#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, ans = 1e9;
    cin >> n;
    vector<int> a(n), tmp;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    tmp = a;
    sort(tmp.begin(), tmp.end());
    for (int i = 2; i < n; i++) {
        int t1 = a[i] - 1, t2 = a[i - 2] - 1;
        ans = min(ans, 1 + ((t1 + 1) / 2) + ((t2 + 1) / 2));
    }
    ans = min(ans, ((tmp[0] + 1) / 2) + ((tmp[1] + 1) / 2));
    for (int i = 1; i < n; i++) {
        int t1 = max(a[i], a[i - 1]), t2 = min(a[i], a[i - 1]), t3 = t1 - t2;
        if (t3 * 2 >= t1)
            ans = min(ans, (t1 + 1) / 2);
        else {
            t2 -= t3;
            t1 = (t2 / 3) * 2 + (t2 % 3);
            ans = min(ans, t3 + t1);
        }
    }
    cout << ans;

    return 0;
}
