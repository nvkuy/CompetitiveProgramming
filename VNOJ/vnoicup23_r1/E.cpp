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

vector<int> par;
int top_point, bot_point, left_point, right_point;
int n, m, l;

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

bool in_range(const pair<int, int> &p1, const pair<int, int> &p2) {
    if (p1.first - l <= p2.first && p1.first + l >= p2.first && p1.second - l <= p2.second && p1.second + l >= p2.second)
        return true;
    return false;
}

bool bad_bomb(int b) {
    if (root(b) == root(top_point) && root(b) == root(bot_point))
        return true;
    if (root(b) == root(left_point) && root(b) == root(right_point))
        return true;
    if (root(b) == root(top_point) && root(b) == root(right_point))
        return true;
    if (root(b) == root(bot_point) && root(b) == root(left_point))
        return true;
    return false;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    //debugLocal();

    cin >> n >> m >> l;
    par.assign(m + 4, -1);
    top_point = m, bot_point = m + 1, left_point = m + 2, right_point = m + 3;
    vector<pair<int, int>> point(m);
    for (int i = 0; i < m; i++) cin >> point[i].first >> point[i].second;

    for (int i = 0; i < m; i++) {
        if (in_range(point[i], {point[i].first, 0}))
            mergeSet(i, bot_point);
        if (in_range(point[i], {point[i].first, n}))
            mergeSet(i, top_point);
        if (in_range(point[i], {0, point[i].second}))
            mergeSet(i, left_point);
        if (in_range(point[i], {n, point[i].second}))
            mergeSet(i, right_point);
        for (int j = 0; j < m; j++) {
            if (in_range(point[i], point[j]))
                mergeSet(i, j);
        }
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < m; i++) {
        if (bad_bomb(i))
            ans.push_back(point[i]);
    }
    
    cout << ans.size() << endl;
    for (auto p : ans) cout << p.first << ' ' << p.second << endl;

    return 0;
}
