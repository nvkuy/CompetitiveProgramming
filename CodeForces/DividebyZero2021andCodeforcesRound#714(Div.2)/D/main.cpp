#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<int> par, a;
long long n, p;

int root(int v) {
    return par[v] < 0 ? v : (par[v] = root(par[v]));
}

void mergeSet(int x, int y) {
    if ((x = root(x)) == (y = root(y)))
        return ;
    if (par[y] < par[x])
        swap(x, y);
    par[x] += par[y];
    par[y] = x;
}

long long costComponent(int pos) {
    if (root(pos) != pos)
        return 0LL;
    long long ans = 0;
    int l = pos - 1, r = pos + 1;
    while ((l >= 0) && (a[l] % a[pos] == 0) && (root(l) == l)) {
        mergeSet(root(pos), root(l));
        l--;
        ans += a[pos];
    }
    if ((l >= 0) && (a[l] % a[pos] == 0)) {
        mergeSet(root(pos), root(l));
        ans += a[pos];
    }
    while ((r < n) && (a[r] % a[pos] == 0) && (root(r) == r)) {
        mergeSet(root(pos), root(r));
        r++;
        ans += a[pos];
    }
    if ((r < n) && (a[r] % a[pos] == 0)) {
        mergeSet(root(pos), root(r));
        ans += a[pos];
    }
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> p;
        a.resize(n);
        par.assign(n, -1);
        vector<pair<int, int>> sa;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sa.push_back({a[i], i});
        }
        sort(sa.begin(), sa.end());
        long long ans = 0;
        for (int i = 0; i < sa.size(); i++) {
            if (sa[i].first >= p)
                break;
            ans += costComponent(sa[i].second);
        }
        set<int> cc;
        for (int i = 0; i < n; i++)
            cc.insert(root(i));
        ans += ((cc.size() - 1LL) * p);
        cout << ans << endl;
    }

    return 0;
}
