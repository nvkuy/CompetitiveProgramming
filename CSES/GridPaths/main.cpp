#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int ans = 0;
char mw[8] = {'D', 'L', 'U', 'R', 'X', 'Y', 'Z', 'T'};
vector<vector<bool>> vis;
string s;

void go(int &row, int &col, char c) {
    if (c == 'D')
        row++;
    else if (c == 'U')
        row--;
    else if (c == 'L')
        col--;
    else if (c == 'R')
        col++;
    else if (c == 'X')
        row++, col++;
    else if (c == 'Y')
        row++, col--;
    else if (c == 'Z')
        row--, col++;
    else
        row--, col--;
}

bool canGo(int row, int col) {
    if (row > 7 || row < 1 || col > 7 || col < 1 || vis[row][col])
        return false;
    return true;
}

bool isStuck(int row, int col) {
    vector<bool> checkStuck(8, false);
    for (int i = 0; i < 8; i++) {
        int trow = row, tcol = col;
        go(trow, tcol, mw[i]);
        if (!canGo(trow, tcol))
            checkStuck[i] = true;
    }
    if (checkStuck[0] && checkStuck[2] && !checkStuck[1] && !checkStuck[3])
        return true;
    if (!checkStuck[0] && !checkStuck[2] && checkStuck[1] && checkStuck[3])
        return true;
    if (checkStuck[4] && !checkStuck[0] && !checkStuck[3])
        return true;
    if (checkStuck[5] && !checkStuck[0] && !checkStuck[1])
        return true;
    if (checkStuck[6] && !checkStuck[2] && !checkStuck[3])
        return true;
    if (checkStuck[7] && !checkStuck[1] && !checkStuck[2])
        return true;
    return false;
}

bool canFinish(int row, int col, int rm) {
    int d = 6 - row + col;
    if (d > rm)
        return false;
    return true;
}

void dfs(int row, int col, int i) {
    if (row == 7 && col == 1) {
        if (i >= s.length())
            ans++;
        return;
    }
    if ((!canFinish(row, col, s.length() - i)) || isStuck(row, col))
        return;
    vis[row][col] = true;
    if (s[i] != '?') {
        int trow = row, tcol = col;
        go(trow, tcol, s[i]);
        if (!canGo(trow, tcol)) {
            vis[row][col] = false;
            return;
        }
        dfs(trow, tcol, i + 1);
    } else {
        for (int j = 0; j < 4; j++) {
            int trow = row, tcol = col;
            go(trow, tcol, mw[j]);
            if (!canGo(trow, tcol))
                continue;
            dfs(trow, tcol, i + 1);
        }
    }
    vis[row][col] = false;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vis = vector<vector<bool>>(8, vector<bool>(8, false));
    getline(cin, s);
    dfs(1, 1, 0);
    cout << ans;

    return 0;
}
