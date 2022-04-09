#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int mx[4] = {-1, 0, 0, 1}, my[4] = {0, -1, 1, 0};
int n, rm;
vector<vector<bool>> c, dd;
vector<int> seg_r;

bool isOut(int x, int y) {
    if (x < 1 || x > 3 || y < 1 || y > n)
        return true;
    return false;
}

void dfs(int x, int y) {
    dd[x][y] = true;
    rm = max(rm, y);
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

    int n, l, r, q;
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
            rm = j;
            dfs(i, j);
            seg_r.push_back(rm);
        }
    }
    sort(seg_r.begin(), seg_r.end());
    //cout << "CONS: " << seg_r.size() << endl;
    cin >> q;
    while (q--) {
        cin >> l >> r;
        int i1 = lower_bound(seg_r.begin(), seg_r.end(), r) - seg_r.begin();
        int i2 = lower_bound(seg_r.begin(), seg_r.end(), l) - seg_r.begin();
        if (i1 > seg_r.size() || seg_r[i1] > r)
            i1--;
        if (i2 == seg_r.size()) {
            cout << 0 << endl;
            continue;
        }
        cout << max(i1 - i2 + 1, 0) << endl;
    }

    return 0;
}
