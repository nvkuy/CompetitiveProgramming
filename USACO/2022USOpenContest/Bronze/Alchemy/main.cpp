#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n;
vector<vector<int>> c;
vector<long long> a, needAi;
set<int> s;
set<int>::iterator it;

bool canMake(int need) {
    s.clear();
    fill(needAi.begin(), needAi.end(), 0);
    needAi[n] += need;
    s.insert(n);
    bool iok = true;
    while (!s.empty()) {
        it = s.end(); it--;
        int u = (*it); s.erase(it);
        //cout << u << '|' << needAi[u] << '|' << a[u] << endl;
        if (needAi[u] <= a[u])
            continue;
        if (c[u].size() == 0) {
            iok = false;
            break;
        }
        int needMore = needAi[u] - a[u];
        for (int i = 0; i < c[u].size(); i++) {
            int v = c[u][i];
            s.insert(v);
            needAi[v] += needMore;
        }
    }
    return iok;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //freopen("5.in", "r", stdin);

    int u, v, mm, k;
    cin >> n;
    c.resize(n + 1);
    a.resize(n + 1);
    needAi.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> k;
    while (k--) {
        cin >> u >> mm;
        while (mm--) {
            cin >> v;
            c[u].push_back(v);
        }
    }
    int l = 0, r = 1e6, m;
    while (l < r) {
        if (r - l == 1) {
            if (canMake(r))
                l = r;
            break;
        }
        m = (l + r) / 2;
        if (canMake(m))
            l = m;
        else
            r = m - 1;
    }
    cout << l;

    return 0;
}
