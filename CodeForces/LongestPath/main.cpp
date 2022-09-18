#include <bits/stdc++.h>

using namespace std;

bool c[1000][1000], vis[1000];
int d[1000];

int longestPath(int n, vector<vector<int>> ed, int u, int v)
{
    memset(c, false, sizeof(c));
    for (int i = 0; i < ed.size(); i++)
        c[ed[i][0] - 1][ed[i][1] - 1] = true;
    for (int i = 0; i < n; i++) {
        d[i] = -1e6;
        vis[i] = false;
    }
    d[u - 1] = 0;
    while (true) {
        int j = -1, maxi = -1e6;
        for (int i = 0; i < n; i++) {
            if ((!vis[i]) && (d[i] > maxi)) {
                j = i;
                maxi = d[i];
            }
        }
        if (maxi == -1e6)
            break;
        vis[j] = true;
        for (int i = 0; i < n; i++) {
            if ((c[j][j]) && (d[i] < d[j] + 1))
                d[i] = d[j] + 1;
        }
    }
    if (d[v - 1] == -1e6)
        return -1;
    return d[v - 1];
}

int main()
{
    cout << longestPath(3,{{1, 2}, {2, 3}, {1, 3}},1,3) << endl;
    return 0;
}
