#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<long long> par, sum_cc;
vector<pair<int, int>> range_cc;
int n;

int root(int v) {
    return par[v] < 0
            ? v
            : (par[v] = root(par[v]));
}

void merge(int x, int y) {
    if ((x = root(x)) == (y = root(y))) {
        return ;
    }
    if (par[y] < par[x]) {
        swap(x, y);
    }
    sum_cc[x] += sum_cc[y];
    par[x] += par[y];
    if ((range_cc[y].second + 1) % n == range_cc[x].first)
        range_cc[x].first = range_cc[y].first;
    else
        range_cc[x].second = range_cc[y].second;
    par[y] = x;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    long long l = 0, r = 1e13, m;
    while (l < r) {
        m = (l + r) / 2;
        par.assign(n, -1);
        sum_cc.assign(n, 0);
        range_cc.resize(n);
        for (int i = 0; i < n; i++) {
            range_cc[i] = {i, i};
            sum_cc[i] = a[i];
        }
        for (int i = 0; i < n; i++) {
            if (m < a[i]) continue;
            while (true) {
                bool ic = false;
                int root_i = root(i), c1 = (range_cc[root_i].second + 1) % n, c2 = (range_cc[root_i].first - 1 + n) % n;
                // cout << m << ' ' << i << ' ' << c1 << ' ' << c2 << ' ' << abs(par[root_i]) << ' ' << sum_cc[root_i] << endl;
                // if (a[c1] > a[c2]) swap(c1, c2);
                if (sum_cc[root_i] + m >= a[c1] && root_i != root(c1)) {
                    ic = true;
                    merge(root_i, c1);
                }
                if (sum_cc[root_i] + m >= a[c2] && root_i != root(c2)) {
                    ic = true;
                    merge(root_i, c2);
                }
                if (!ic) break;
            }
        }
        if (abs(par[root(0)]) == n)
            r = m;
        else
            l = m + 1;
    }
    cout << r << endl;

    return 0;
}
