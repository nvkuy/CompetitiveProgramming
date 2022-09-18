#include <bits/stdc++.h>

using namespace std;

vector<int> par;
vector<long long> sc;

int getRoot(int u) {
    if (par[u] < 0)
        return u;
    par[u] = getRoot(par[u]);
    return par[u];
}

void mergeSet(int u, int v) {
    int r1 = getRoot(u), r2 = getRoot(v);
    if (r1 == r2)
        return;
    if (par[r1] > par[r2])
        swap(r1, r2);
    par[r1] += par[r2];
    par[r2] = r1;
    sc[r1] += sc[r2];
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1), dd(n + 1, 0), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    par.assign(n + 1, -1);
    sc.resize(n + 1);
    vector<pair<int, int>> sa;
    for (int i = 1; i <= n; i++) {
        sc[i] = a[i];
        sa.push_back({b[i], i});
    }
    sort(sa.begin(), sa.end(), greater<pair<int, int>>());
    vector<long long> ans;
    ans.push_back(0LL);
    for (int i = 0; i < n; i++) {
        int pos = sa[i].second;
        dd[pos] = 1;
        if (pos > 1 && dd[pos - 1] == 1)
            mergeSet(pos, pos - 1);
        if (pos < n && dd[pos + 1] == 1)
            mergeSet(pos, pos + 1);
        long long maxSeg = ans.back();
        maxSeg = max(maxSeg, sc[getRoot(pos)]);
        ans.push_back(maxSeg);
    }
    reverse(ans.begin(), ans.end());
    for (int i = 1; i <= n; i++)
        cout << ans[i] << endl;

    return 0;
}
