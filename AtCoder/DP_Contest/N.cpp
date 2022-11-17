#include <bits/stdc++.h>
using namespace std;

long long n, INF = 1e18;
vector<long long> a, ps;
vector<vector<long long>> f;

long long cal(int l, int r) {
    if (l == r)
        return 0LL;
    if (f[l][r] != INF)
        return f[l][r];
    f[l][r] = INF;
    for (int i = l; i < r; i++)
        f[l][r] = min(f[l][r], cal(l, i) + cal(i + 1, r) + ps[r] - ps[l - 1]);
    return f[l][r];
}

int main() {

    cin >> n;
    a.resize(n + 1);
    ps.assign(n + 1, 0);
    f.assign(n + 1, vector<long long>(n + 1, INF));
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) ps[i] = ps[i - 1] + a[i];
    cout << cal(1, n) << endl;

    return 0;
}