#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<vector<long long>> f(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
        f[i][0] = f[i][i] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < i; j++)
            f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)
            cout << f[i][j] << ' ';
        cout << endl;
    }

    return 0;
}
