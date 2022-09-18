#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q, x, y;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), greater<int>());
    vector<long long> ps(n + 1, 0);
    for (int i = 1; i <= n; i++)
        ps[i] = ps[i - 1] + a[i - 1];
    while (q--) {
        cin >> x >> y;
        cout << ps[x] - ps[x - y] << endl;
    }

    return 0;
}
