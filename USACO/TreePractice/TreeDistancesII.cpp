#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> c;
vector<long long> ans, sum_sub_tree, node_cnt_sub_tree;
int n; 

void buildTree(int u, int par) {

    for (int v : c[u]) {
        if (v != par) {
            buildTree(v, u);
            sum_sub_tree[u] += sum_sub_tree[v] + node_cnt_sub_tree[v];
            node_cnt_sub_tree[u] += node_cnt_sub_tree[v];
        }
    }

}

void findDist(int u, int par, long long sum_not_u) {

    ans[u] = sum_not_u + (n - node_cnt_sub_tree[u]) + sum_sub_tree[u];
    for (int v : c[u])
        if (v != par) findDist(v, u, ans[u] - sum_sub_tree[v] - node_cnt_sub_tree[v]);

}

int main() {

    cin >> n;
    ans.assign(n + 1, 0);
    sum_sub_tree.assign(n + 1, 0);
    node_cnt_sub_tree.assign(n + 1, 1);
    c.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        c[u].push_back(v);
        c[v].push_back(u);
    }

    buildTree(1, 0);
    findDist(1, 0, 0);

    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << endl;

    return 0;
}