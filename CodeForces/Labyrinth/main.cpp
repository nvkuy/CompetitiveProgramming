#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int endPoint = -1, pe1, pe2, s;
vector<vector<int>> c;
vector<int> dd;
vector<int> trace;

void dfs(int u) {
    if (endPoint != -1)
        return;
    for (int i = 0; i < c[u].size(); i++) {
        int v = c[u][i];
        if (dd[v] == -1) {
            trace[v] = u;
            dd[v] = dd[u];
            dfs(v);
        } else {
            if (dd[v] == dd[u] || v == s)
                continue;
            endPoint = v;
            pe1 = trace[v];
            pe2 = u;
            return;
        }
    }
}

void printAns(int u) {
    vector<int> ans;
    ans.push_back(endPoint);
    int v = u;
    while (v != 0) {
        ans.push_back(v);
        v = trace[v];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    cout << endl;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m, n, u, v;

    cin >> n >> m >> s;
    c.resize(n + 1);
    trace.assign(n + 1, -1);
    dd.assign(n + 1, -1);
    while (m--) {
        cin >> u >> v;
        c[u].push_back(v);
        //c[v].push_back(u);
    }

    dd[s] = 0, trace[s] = 0;
    for (int i = 0; i < c[s].size(); i++) {
        if (dd[c[s][i]] == -1) {
            trace[c[s][i]] = s;
            dd[c[s][i]] = c[s][i];
            dfs(c[s][i]);
        } else {
            endPoint = c[s][i];
            pe1 = s;
            pe2 = trace[c[s][i]];
        }
        if (endPoint != -1) {
            cout << "Possible" << endl;
            printAns(pe1);
            printAns(pe2);
            return 0;
        }
    }
    cout << "Impossible";

    return 0;
}
