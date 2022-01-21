#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q, ai, a, b;
    long long f[200002];
    cin >> n >> q;
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> ai;
        f[i] = f[i - 1] + ai;
    }
    while (q--) {
        cin >> a >> b;
        cout << f[b] - f[a - 1] << endl;
    }

    return 0;
}
