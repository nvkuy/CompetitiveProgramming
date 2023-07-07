#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> c;
vector<int> dd;

void dfs(int u) {
    dd[u] = 1;
    for (int v : c[u])
        if (!dd[v]) dfs(v);
}

int main() {

    int n;
    cin >> n;
    c.resize(n + 1);
    dd.resize(n + 1);
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
        for (int j = 0; j < n; j++) {
            if (a[i][j] == i + 1) break;
            c[a[i][j]].push_back(i + 1);
        }
    }

    for (int i = 0; i < n; i++) {
        fill(dd.begin(), dd.end(), 0);
        dfs(i + 1);
        for (int j = 0; j < n; j++) {
            if (dd[a[i][j]]) {
                cout << a[i][j] << endl;
                break;
            }
        }
    }

    return 0;
}