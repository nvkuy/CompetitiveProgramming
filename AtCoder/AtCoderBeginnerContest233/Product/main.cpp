#include <bits/stdc++.h>

using namespace std;

vector<vector<long long>> c;
int n, ans;
long long x;

void dfs(int i, long long pro) {
    if (i == n) {
        if (pro == x)
            ans++;
        return;
    }
    for (int j = 0; j < c[i].size(); j++) {
        if (pro <= x / c[i][j])
            dfs(i + 1, pro * c[i][j]);
    }
}

int main()
{
    int li;
    cin >> n >> x;
    c.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> li;
        c[i].resize(li);
        for (int j = 0; j < li; j++)
            cin >> c[i][j];
    }
    ans = 0;
    dfs(0, 1);
    cout << ans;

    return 0;
}
