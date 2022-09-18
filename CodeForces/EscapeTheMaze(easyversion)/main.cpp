#include <bits/stdc++.h>

using namespace std;

void vla(int st, vector<vector<int>> &c, vector<int> &dd, int n, set<int> sk) {
    dd = vector<int>(n + 1, 1e9 + 7);
    queue<int> q;
    q.push(st);
    dd[st] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (sk.find(u) != sk.end())
            continue;
        for (int i = 0; i < c[u].size(); i++) {
            if (dd[c[u][i]] == 1e9 + 7) {
                q.push(c[u][i]);
                dd[c[u][i]] = dd[u] + 1;
            }
        }
    }
}

bool check(int st, set<int> fi, vector<vector<int>> c, vector<int> &dd2, vector<int> &dd1, int n) {
    dd2 = vector<int>(n + 1, 1e9 + 7);
    queue<int> q;
    q.push(st);
    dd2[st] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (fi.find(u) != fi.end()) {
            if (dd2[u] <= dd1[st])
                return false;
        }
        for (int i = 0; i < c[u].size(); i++) {
            if (dd2[c[u][i]] == 1e9 + 7) {
                q.push(c[u][i]);
                dd2[c[u][i]] = dd2[u] + 1;
            }
        }
    }
    return true;
}

int main()
{
    int t, n, k, ai, u, v;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);
        vector<vector<int>> c(n + 1);
        vector<int> cnt(n + 1, 0);
        set<int> fris;
        vector<int> fins;
        while (k--) {
            scanf("%d", &ai);
            fris.insert(ai);
        }
        for (int i = 1; i < n; i++) {
            scanf("%d %d", &u, &v);
            c[v].push_back(u);
            c[u].push_back(v);
            cnt[u]++; cnt[v]++;
        }
        for (int i = 2; i <= n; i++) {
            if (cnt[i] == 1)
                fins.push_back(i);
        }
        vector<int> dd1, dd2;
        vla(1, c, dd1, n, fris);
        bool iok = false;
        for (int i = 0; i < fins.size(); i++) {
            if (dd1[fins[i]] == 1e9 + 7)
                continue;
            iok |= check(fins[i], fris, c, dd2, dd1, n);
            if (iok)
                break;
        }
        printf("%s\n", (iok ? "YES" : "NO"));
    }

    return 0;
}
