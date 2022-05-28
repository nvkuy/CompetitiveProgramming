#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q, x;
    cin >> n >> q;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = i;
        b[i] = i;
    }
    while (q--) {
        cin >> x;
        int p1 = b[x], p2 = p1 + 1;
        if (p1 == n)
            p2 = p1 - 1;
        b[x] = p2, b[a[p2]] = p1;
        swap(a[p1], a[p2]);
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';

    return 0;
}
