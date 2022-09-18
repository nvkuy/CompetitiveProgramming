#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n;
vector<vector<int>> c;

void trans(int &x, int &y) {
    int xt = y, yt = n - x - 1;
    x = xt, y = yt;
}

int minOp(int i, int j) {
    int x = i, y = j, zr = 0;
    for (int k = 0; k < 4; k++) {
        if (c[x][y] == 0)
            zr++;
        trans(x, y);
    }
    //cout << x << '|' << y << '|' << zr << endl;
    return min(zr, 4 - zr);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        string tmp;
        c.assign(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            getline(cin, tmp);
            for (int j = 0; j < n; j++)
                c[i][j] = tmp[j] - '0';
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = i; j < n - i - 1; j++)
                ans += minOp(i, j);
        cout << ans << endl;
    }

    return 0;
}
