#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

set<int> dd;

bool check(int ai) {
    if (dd.find(ai) != dd.end())
        return false;
    if (ai <= 2)
        return true;
    if (ai % 2)
        return check((ai - 1) / 2);
    if (ai % 4 == 0)
        return check(ai / 4);
    return true;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, p, mod = 1e9 + 7, ans = 0;
    cin >> n >> p;
    vector<int> a, b(n);
    vector<int> f(p + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        if (!check(b[i]))
            continue;
        dd.insert(b[i]);
        a.push_back(b[i]);
    }
    int l = 0, r = -1, p2 = 1;
    for (int i = 1; i <= p; i++) {
        l = r + 1;
        p2 *= 2;
        while (r + 1 < a.size() && a[r + 1] < p2)
            r++;
        f[i] = (f[i - 1] + (r - l + 1)) % mod;
        if (i > 1)
            f[i] = (f[i] + f[i - 2]) % mod;
        ans = (ans + f[i]) % mod;
        //cout << ans << '|';
    }
    //cout << endl;
    cout << ans;

    return 0;
}
