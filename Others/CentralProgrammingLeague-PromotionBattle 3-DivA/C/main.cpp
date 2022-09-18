#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n, max_val = 0;
vector<vector<int>> a;
vector<vector<int>> f;
vector<vector<int>> dd;
vector<vector<vector<pair<int, int>>>> mmap;

void corCompress() {
    vector<int> num;
    map<int, int> mask;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            num.push_back(a[i][j]);
    sort(num.begin(), num.end());
    int mask_num = 0;
    for (int i = 0; i < num.size(); i++) {
        if (mask.find(num[i]) != mask.end())
            continue;
        mask_num++;
        mask.insert({num[i], mask_num});
    }
    max_val = mask_num;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = mask[a[i][j]];
}

bool canGo(int x, int y, int curx, int cury) {
    if (x < 0 || x >= n || y < 0 || y >= n)
        return false;
    if (a[x][y] <= a[curx][cury])
        return false;
    if (abs(x - curx) < 2 && abs(y - cury) < 2)
        return false;
    return true;
}

void dfs(int x, int y) {
    int maxMove = 0;
    dd[x][y] = 1;
    for (int i = 0; i < mmap[x][y].size(); i++) {
        pair<int, int> cor = mmap[x][y][i];
        if (dd[cor.first][cor.second] == 0 && maxMove < (max_val - a[cor.first][cor.second] + 1))
            dfs(cor.first, cor.second);
        maxMove = max(maxMove, f[cor.first][cor.second]);
    }
    f[x][y] = maxMove + 1;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int r, c;
    cin >> n >> r >> c;
    a.assign(n, vector<int>(n));
    f.assign(n, vector<int>(n, 0));
    dd.assign(n, vector<int>(n, 0));
    mmap.assign(n, vector<vector<pair<int, int>>>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    corCompress();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (canGo(i + 1, k, i, j))
                    mmap[i][j].push_back(make_pair(i + 1, k));
                if (canGo(i - 1, k, i, j))
                    mmap[i][j].push_back(make_pair(i - 1, k));
                if (canGo(k, j + 1, i, j))
                    mmap[i][j].push_back(make_pair(k, j + 1));
                if (canGo(k, j - 1, i, j))
                    mmap[i][j].push_back(make_pair(k, j - 1));
            }
        }
    }
    dfs(r - 1, c - 1);
    cout << f[r - 1][c - 1];

    return 0;
}
