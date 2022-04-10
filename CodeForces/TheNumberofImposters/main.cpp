#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n, ct1, ct2;
bool isValid;
vector<vector<pair<int, bool>>> c; // i->j true => team, i->j false => not team
vector<int> dd; //0 - not vis, 1 team_1, 2 team_2

void dfs(int u) {
    if (!isValid)
        return;
    if (dd[u] == 1)
        ct1++;
    else
        ct2++;
    for (int i = 0; i < c[u].size(); i++) {
        pair<int, bool> tmp = c[u][i];
        if (dd[tmp.first] == 0) {
            if (tmp.second)
                dd[tmp.first] = dd[u];
            else
                dd[tmp.first] = 3 - dd[u];
            dfs(tmp.first);
        } else {
            if (tmp.second) {
                if (dd[tmp.first] != dd[u])
                    isValid = false;
            } else {
                if (dd[tmp.first] == dd[u])
                    isValid = false;
            }
            if (!isValid)
                return;
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, m, u, v;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        c.clear();
        c.resize(n + 1);
        dd.assign(n + 1, 0);
        isValid = true;
        while (m--) {
            cin >> u >> v;
            cin.ignore();
            getline(cin, s);
            if (s == "imposter") {
                c[u].push_back(make_pair(v, false));
                c[v].push_back(make_pair(u, false));
            } else {
                c[u].push_back(make_pair(v, true));
                c[v].push_back(make_pair(u, true));
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (!isValid)
                break;
            if (dd[i] != 0)
                continue;
            ct1 = ct2 = 0;
            dd[i] = 1;
            dfs(i);
            ans += max(ct1, ct2);
        }
        cout << (isValid ? ans : -1) << endl;
    }

    return 0;
}
