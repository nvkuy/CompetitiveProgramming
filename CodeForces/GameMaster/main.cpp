#include <bits/stdc++.h>

using namespace std;

int n;
bool dd[100001];
vector<vector<int>> c;
vector<pair<int, int>> a, b;
string ans;

void dfs(int u) {
    dd[u] = true;
    ans[u] = '1';
    for (int i = 0; i < c[u].size(); i++)
        if (!dd[c[u][i]])
            dfs(c[u][i]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t, ai, ma, mb, am, bm;
    cin >> t;
    while (t--) {
        cin >> n;
        ma = mb = am = bm = -1;
        a.clear();
        b.clear();
        c.clear();
        c.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> ai;
            a.push_back(make_pair(ai, i));
            if (ma < ai) {
                ma = ai;
                am = i;
            }
        }
        for (int i = 0; i < n; i++) {
            cin >> ai;
            b.push_back(make_pair(ai, i));
            if (mb < ai) {
                mb = ai;
                bm = i;
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        for (int i = 1; i < n; i++) {
            c[a[i - 1].second].push_back(a[i].second);
            c[b[i - 1].second].push_back(b[i].second);
        }
        ans.assign(n, '0');
        memset(dd, false, (n + 1) * sizeof *dd);
        dfs(bm);
        memset(dd, false, (n + 1) * sizeof *dd);
        dfs(am);

        cout << ans << '\n';
    }

    return 0;
}
