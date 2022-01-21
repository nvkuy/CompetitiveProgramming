#include <bits/stdc++.h>

using namespace std;

long long f[1000001];

int main()
{

    int n, m = 1e9 + 7;
    memset(f, 0LL, sizeof(f));
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= min(i, 6); j++)
            f[i] = (f[i - j] + f[i]) % m;
    cout << f[n];

    return 0;
}
