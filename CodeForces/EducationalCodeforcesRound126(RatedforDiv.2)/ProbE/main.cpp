#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int mx[4] = {-1, 0, 0, 1}, my[4] = {0, -1, 1, 0};
int n, rm, lm;
vector<vector<bool>> c, dd;
vector<pair<int, int>> con_seg;

bool isOut(int x, int y) {
    if (x < 1 || x > 3 || y < 1 || y > n)
        return true;
    return false;
}

void dfs(int x, int y) {
    dd[x][y] = true;
    rm = max(rm, y);
    lm = min(lm, y);
    for (int i = 0; i < 4; i++) {
        int tx = x + mx[i], ty = y + my[i];
        if (!isOut(tx, ty) && !dd[tx][ty] && c[tx][ty])
            dfs(tx, ty);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int l, r, q;
    string s;
    cin >> n;
    cin.ignore();
    c.assign(4, vector<bool>(n + 1, false));
    dd.assign(4, vector<bool>(n + 1, false));
    for (int i = 1; i <= 3; i++) {
        getline(cin, s);
        for (int j = 1; j <= n; j++) {
            if (s[j - 1] == '1')
                c[i][j] = true;
        }
    }
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= n; j++) {
            if (dd[i][j] || !c[i][j])
                continue;
            //cout << i << '|' << j << endl;
            rm = j, lm = j;
            dfs(i, j);
            con_seg.push_back(make_pair(lm, rm));
        }
    }
    //cout << con_seg.size() << endl;
    cin >> q;
    while (q--) {
        cin >> l >> r;
        int ans = 0;
        for (int i = 0; i < con_seg.size(); i++)
            if (max(l, con_seg[i].first) <= min(r, con_seg[i].second))
                ans++;
        cout << ans << endl;
    }

    return 0;
}
