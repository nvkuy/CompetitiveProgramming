#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<long long>> f(n + 1, vector<long long>(n + 1, 0));
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        f[i][i] = a[i];
    for (int i = 1; i < n; i++)
        f[i][i + 1] = max(a[i], a[i + 1]);
    for (int len = 3; len <= n; len++) {
        for (int i = 1; i <= n - len + 1; i++) {
            int j = i + len - 1;
            f[i][j] = max(a[i] + min(f[i + 2][j], f[i + 1][j - 1]), a[j] + min(f[i + 1][j - 1], f[i][j - 2]));
        }
    }
    cout << f[1][n] << endl;

    return 0;
}
