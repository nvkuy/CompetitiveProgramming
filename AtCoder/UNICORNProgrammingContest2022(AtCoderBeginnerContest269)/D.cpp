#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

set<pair<int, int>> dd1, dd2;
int mx[6] = {-1, -1, 0, 0, 1, 1}, my[6] = {-1, 0, -1, 1, 0, 1};

void dfs(int x, int y) {
    dd1.insert({x, y});
    for (int i = 0; i < 6; i++) {
        int nx = x + mx[i], ny = y + my[i];
        if (dd2.find({nx, ny}) != dd2.end() && dd1.find({nx, ny}) == dd1.end())
            dfs(nx, ny);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> cell(n);
    for (int i = 0; i < n; i++) {
        cin >> cell[i].first >> cell[i].second;
        dd2.insert(cell[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dd1.find(cell[i]) != dd1.end())
            continue;
        ans++;
        dfs(cell[i].first, cell[i].second);
    }
    cout << ans;

    return 0;
}