#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, k, x, y, prex, prey;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    x = prex = a[0], y = prey = b[0];
    for (int i = 1; i < n; i++) {
        x = y = -1;
        if (abs(a[i] - prex) <= k || abs(a[i] - prey) <= k)
            x = a[i];
        if (abs(b[i] - prex) <= k || abs(b[i] - prey) <= k)
            y = b[i];
        if (x < 0 && y < 0)
            break;
        if (x > 0)
            prex = x;
        if (y > 0)
            prey = y;
        if (x < 0 || y < 0)
            prex = prey = max(x, y);
    }
    if (x > 0 || y > 0)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
