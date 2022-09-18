#include <bits/stdc++.h>

using namespace std;

int n, f[100001];
int mod = 1e9 + 7;

int main()
{

    cin >> n;
    f[1] = 1; f[2] = 2; f[3] = 4;
    for (int i = 4; i <= n; i++)
        f[i] = (f[i - 1] + f[i - 2] + f[i - 3]) % mod;
    cout << f[n];

    return 0;
}
