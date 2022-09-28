#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

double dis(long long x1, long long y1, long long x2, long long y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

bool cmpLess(double a, double b) {
    return a + 1e-9 < b;
}

int cnt(vector<int> &dd, vector<pair<int, int>> pos, int d) {
    int ans = 0;
    set<int> f;
    for (int i = 0; i < dd.size(); i++) {
        if (dd[i])
            f.insert(i);
    }
    for (int i = 0; i < pos.size(); i++) {
        if (f.find(i) == f.end())
            continue;
        for (int j = 0; j < pos.size(); j++) {
            if (cmpLess(dis(pos[i].first, pos[i].second, pos[j].first, pos[j].second), d) && !dd[j]) {
                dd[j] = 1;
                ans++;
            }
        }
    }
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, f0, d, f1, f2;
    cin >> n >> f0 >> d;
    vector<pair<int, int>> pos(n);
    vector<int> dd(n, 0);
    for (int i = 0; i < n; i++)
        cin >> pos[i].first >> pos[i].second;
    dd[f0 - 1] = 1;
    f1 = cnt(dd, pos, d);
    f2 = cnt(dd, pos, d);
    cout << f1 << ' ' << f2;

    return 0;
}
