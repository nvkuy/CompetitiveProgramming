#include <bits/stdc++.h>

using namespace std;

long long maxn = 1e6 + 1, f[1000001];
bool nt[1000001];

int main()
{

    nt[1] = false;
    for (int i = 2; i <= maxn; i++)
        nt[i] = true;
    for (int i = 2; i * i <= maxn; i++) {
        if (nt[i]) {
            for (int j = i * i; j <= maxn; j += i)
                nt[j] = false;
        }
    }
    f[0] = 0;
    for (int i = 1; i < maxn; i++) {
        f[i] = f[i - 1];
        if (nt[i])
            f[i] += i;
    }

    int t, l, r;
    cin >> t;
    while (t > 0) {
        t--;
        cin >> l >> r;
        cout << f[r] - f[l - 1] << "\n";
    }

    return 0;
}
