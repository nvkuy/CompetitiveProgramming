#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

inline void debugLocal() {
    if (!fopen("moocast.in", "r"))
        return;
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
}

struct cow {
    long long x, y, p;
    bool canReach(cow &c) {
        return (x - c.x) * (x - c.x) + (y - c.y) * (y - c.y) <= p * p;
    }
};



void dfs(vector<cow> &cows, vector<int> &dd, int cow_num) {
    dd[cow_num] = 1;
    for (int i = 0; i < cows.size(); i++) {
        if (dd[i] == 0 && cows[cow_num].canReach(cows[i]))
            dfs(cows, dd, i);
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n;
    cin >> n;
    vector<cow> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i].x >> c[i].y >> c[i].p;
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        vector<int> dd(n, 0);
        dfs(c, dd, i);
        int tans = 0;
        for (int i = 0; i < n; i++) tans += dd[i];
        ans = max(ans, tans);
    }
    cout << ans << endl;
    
    return 0;
}
