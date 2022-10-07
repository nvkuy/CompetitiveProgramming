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

const int inf = 1e9;

int n, m, cur_time = 0;
vector<vector<int>> c, cc;
vector<int> num, low;
stack<int> st;

void visit(int u) {
    low[u] = num[u] = ++cur_time;
    st.push(u);

    for (int v : c[u])
        if (num[v])
            low[u] = min(low[u], num[v]);
        else {
            visit(v);
            low[u] = min(low[u], low[v]);
        }

    if (num[u] == low[u]) { //found
        vector<int> tmp;
        int v;
        do {
            v = st.top();
            st.pop();
            num[v] = low[v] = inf;
            tmp.push_back(v);
        } while (v != u);
        cc.push_back(tmp);
    }
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    cin >> n >> m;
    c.resize(n + 1);
    low.assign(n + 1, 0);
    num.assign(n + 1, 0);
    vector<int> chain(n + 1);
    while (m--) {
        for (int i = 1; i <= n; i++)
            cin >> chain[i];
        for (int i = 2; i <= n; i++)
            c[chain[i - 1]].push_back(chain[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (!num[chain[i]])
            visit(chain[i]);
    }
    vector<int> ans(n + 1);
    int tmp = 0;
    // cout << cc.size() << endl;
    reverse(cc.begin(), cc.end());
    while (cc.size() > 0) {
        tmp += (cc.back().size() - 1);
        for (int u : cc.back()) {
            ans[u] = tmp;
            // cout << u << ' ';
        }
        // cout << endl;
        tmp++;
        cc.pop_back();
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << endl;

    return 0;
}
