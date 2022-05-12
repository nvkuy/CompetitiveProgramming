#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, ai;
    cin >> n;
    vector<int> on, zr;
    for (int i = 1; i <= n; i++) {
        cin >> ai;
        if (ai == 1)
            on.push_back(i);
        else
            zr.push_back(i);
    }
    vector<vector<long long>> f(zr.size() + 1, vector<long long>(on.size() + 1, 1e9));
    for (int i = 0; i <= zr.size(); i++)
        f[i][0] = 0;
    for (int i = 1; i <= on.size(); i++) {
        for (int j = 1; j <= zr.size(); j++) {
            f[j][i] = f[j - 1][i];
            f[j][i] = min(f[j][i], llabs(zr[j - 1] - on[i - 1]) + f[j - 1][i - 1]);
        }
    }
    cout << f[zr.size()][on.size()];

    return 0;
}
