#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

inline void debugLocal() {
    if (!fopen("clocktree.in", "r"))
        return;
    freopen("clocktree.in", "r", stdin);
    freopen("clocktree.out", "w", stdout);
}

vector<vector<int>> c;
vector<int> color;

void dfs(int u, int par) {
    
    for (int v : c[u]) {
        if (v != par) {
            color[v] = 1 - color[u];
            dfs(v, u);
        }
    }

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n;
    cin >> n;
    vector<int> initVal(n + 1);
    color.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> initVal[i];
    c.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }

    dfs(1, 0);
    int zeroCnt = 0, sumZero = 0, sumOne = 0;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0) {
            zeroCnt++;
            sumZero += initVal[i];
        } else
            sumOne += initVal[i];
    }

    int t0 = sumZero % 12, t1 = sumOne % 12;
    if (t1 == t0)
        cout << n << endl;
    else {
        if (((t1 + 1) % 12) == t0)
            cout << zeroCnt << endl;
        else if (((t0 + 1) % 12) == t1)
            cout << n - zeroCnt << endl;
        else
            cout << 0 << endl;
    }

    return 0;
} 
