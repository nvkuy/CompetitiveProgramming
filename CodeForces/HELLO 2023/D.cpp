#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<int> parent, mx, sz;

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
    mx[v] = v;
}

int find_set(int v) {
    return v == parent[v] ? v : parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        mx[a] = max(mx[a], mx[b]);
    } 
}

void leave(int v) {
    if (v + 1 >= parent.size())
        return;
    union_sets(v, v + 1);
}

int find_next(int p) { 
    p = find_set(p);
    return mx[p];
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        cin >> m;
        vector<int> rz(m);
        for (int i = 0; i < m; i++)
            cin >> rz[i];
        parent.resize(n);
        mx.resize(n);
        sz.resize(n);
        for (int i = 0; i < n; i++)
            make_set(i);
        bool iok = true;
        map<int, vector<int>> hair;
        map<int, int> razor;
        for (int i = 0; i < n; i++)
            hair[b[i]].push_back(i);
        for (int i = 0; i < m; i++)
            razor[rz[i]]++;
        
        int rm = hair.size();
        for (auto p2 : hair) {
            if (!iok) break;
            pair<int, int> p1;
            auto it = razor.find(p2.first);
            if (it == razor.end())
                p1 = {p2.first, 0};
            else
                p1 = *it;
            int need = 0, need_new = 0;
            vector<int> tmp = p2.second;
            for (int i = 0; i < tmp.size(); i++) {
                if (a[tmp[i]] < b[tmp[i]]) {
                    iok = false;
                    // cout << "Cant grow hair at pos = " << tmp[i] << endl;
                }
                if (i > 0 && find_next(tmp[i - 1] + 1) != tmp[i]) {
                    need += need_new;
                    need_new = 0;
                }
                if (a[tmp[i]] != b[tmp[i]])
                    need_new = 1;
                leave(tmp[i]);
            }
            need += need_new;
            if (need > p1.second) {
                iok = false;
                // cout << "Not enough razor for hair len = " << p2.first << endl;
            }
            rm--;
        }
        iok &= (rm == 0);
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
