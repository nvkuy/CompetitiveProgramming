#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n;
vector<int> par;

int root(int v) {
    return par[v] < 0 ? v : (par[v] = root(par[v]));
}

void mergeSet(int x, int y) {
    if ((x = root(x)) == (y = root(y)))
        return ;
    par[y] += par[x];
    par[x] = y;
}

int findNext(int u) {
    int v = u + 1;
    if (v > n) v -= n;
    return root(v);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b;
    cin >> n;
    while (n != 0) {
        par.assign(n + 1, -1);
        vector<map<int, int>> cnt;
        cnt.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a >> b;
            if (a != b)
                cnt[i][a]++, cnt[i][b]++;
            else
                mergeSet(i, findNext(i));
        }
        int u = 1, ans = 0;
        while (true) {
            while (cnt[u].size() > 0 && (*cnt[u].begin()).second >= 2)
                cnt[u].erase(cnt[u].begin());
            int v = findNext(u);
            if (cnt[u].size() == 0) {
                if (u == v)
                    break;
                mergeSet(u, v);
                u = v;
                continue;
            }
            int num = (*cnt[u].begin()).first;
            cnt[u].erase(cnt[u].begin());
            cnt[v][num]++;
            auto it = cnt[v].find(num);
            if ((*it).second >= 2)
                cnt[v].erase(it);
            ans++;
            if (u == v)
                break;
            if (cnt[u].size() == 0)
                mergeSet(u, v);
            u = v;
        }
        cout << ans << endl;
        cin >> n;
    }

    return 0;
}
