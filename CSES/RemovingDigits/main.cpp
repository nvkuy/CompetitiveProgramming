#include <bits/stdc++.h>

using namespace std;

long long f[1000001];

int main()
{
    int n, t, ni;
    cin >> n;
    f[0] = 0;
    for (int i = 1; i < 10; i++)
        f[i] = 1;
    for (int i = 10; i <= n; i++) {
        ni = i, f[i] = 1e9 + 7;
        while (ni > 0) {
            t = ni % 10;
            ni /= 10;
            f[i] = min(f[i], f[i - t] + 1);
        }
    }
    cout << f[n];

    return 0;
}
