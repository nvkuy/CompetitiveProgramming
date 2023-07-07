#include <bits/stdc++.h>
using namespace std;

vector<vector<set<string>>> dd;
vector<vector<string>> c;
int n;
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, 1, -1};
set<string> ans, move;
vector<vector<int>> space;

bool isWinning() {
    if (::move.count("M11") > 0 && ::move.count("O22") > 0 && ::move.count("O33") > 0)
        return true;
    if (::move.count("O11") > 0 && ::move.count("O22") > 0 && ::move.count("M33") > 0)
        return true;
    if (::move.count("M13") > 0 && ::move.count("O22") > 0 && ::move.count("O31") > 0)
        return true;
    if (::move.count("O13") > 0 && ::move.count("O22") > 0 && ::move.count("M31") > 0)
        return true;
    for (int i = 1; i <= 3; i++) {
        if (::move.count("M" + to_string(i) + "1") > 0 && ::move.count("O" + to_string(i) + "2") > 0 && ::move.count("O" + to_string(i) + "3") > 0)
            return true;
        if (::move.count("O" + to_string(i) + "1") > 0 && ::move.count("O" + to_string(i) + "2") > 0 && ::move.count("M" + to_string(i) + "3") > 0)
            return true;
        if (::move.count("M1" + to_string(i)) > 0 && ::move.count("O2" + to_string(i)) > 0 && ::move.count("O3" + to_string(i)) > 0)
            return true;
        if (::move.count("O1" + to_string(i)) > 0 && ::move.count("O2" + to_string(i)) > 0 && ::move.count("M3" + to_string(i)) > 0)
            return true;
    }
    return false;
}

void dfs(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) return;
    if (c[x][y] == "#") return;
    bool isInsert = false;
    if (c[x][y] != "." && space[c[x][y][1] - '0'][c[x][y][2] - '0']) {
        ::move.insert(c[x][y]);
        space[c[x][y][1] - '0'][c[x][y][2] - '0'] = 0;
        isInsert = true;
    }
    string s = "";
    for (string tmp : ::move) s += (tmp + "|");
    if (s.length() > 0)
        s.pop_back();
    if (dd[x][y].count(s) > 0) {
        if (isInsert) {
            ::move.erase(::move.find(c[x][y]));
            space[c[x][y][1] - '0'][c[x][y][2] - '0'] = 1;
        }
        return;
    }
    dd[x][y].insert(s);
    if (isInsert && isWinning()) {
        ans.insert(s);
        if (isInsert) {
            ::move.erase(::move.find(c[x][y]));
            space[c[x][y][1] - '0'][c[x][y][2] - '0'] = 1;
        }
        return;
    }
    for (int i = 0; i < 4; i++)
        dfs(x + dx[i], y + dy[i]);
    if (isInsert) {
        ::move.erase(::move.find(c[x][y]));
        space[c[x][y][1] - '0'][c[x][y][2] - '0'] = 1;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x, y;
    cin >> n;
    c.resize(n);
    dd.assign(n, vector<set<string>>(n));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j * 3] == '#')
                c[i].push_back("#");
            else if (s[j * 3] == '.')
                c[i].push_back(".");
            else if (s[j * 3] == 'B') {
                c[i].push_back(".");
                x = i, y = j;
            } else
                c[i].push_back(s.substr(j * 3, 3));
        }
    }
    space = vector<vector<int>>(4, vector<int>(4, 1));
    dfs(x, y);
    cout << ans.size() << endl;
    // for (string tmp : ans) cout << tmp << endl;

    return 0;
}