
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

template<typename T>
struct PersistentArray {
    static const int LOG = 4;
    static const int FULL_MASK = (1<<LOG) - 1;

    struct Node {
        T x;
        std::array<Node*, 1<<LOG> child;
        Node(const T& _x) : x(_x) {
            std::fill(child.begin(), child.end(), nullptr);
        }
        Node(const Node& n) : x(n.x) {
            std::copy(n.child.begin(), n.child.end(), child.begin());
        }
    };

    static T get(Node* t, int p) {
        if (t == NULL) return 0;
        return p ? get(t->child[p & FULL_MASK], p >> LOG) : t->x;
    }

    static Node* set(Node* t, int p, const T& x) {
        t = (t == NULL) ? new Node(0) : new Node(*t);
        if (p == 0) t->x = x;
        else {
            auto ptr = set(t->child[p & FULL_MASK], p >> LOG, x);
            t->child[p & FULL_MASK] = ptr;
        }
        return t;
    }

    Node* build(const vector<T>& v) {
        Node* root = NULL;
        for (int i = 0; i < (int) v.size(); i++) {
            root = set(root, i, v[i]);
        }
        return root;
    }
};

struct PersistentDSU {
    int n;
    using Arr = PersistentArray<int>;

    PersistentDSU(int _n) : n(_n) {
        roots.emplace_back(A.build(std::vector<int> (n, -1)));
    }

    int find(int version, int u) {
        int p = A.get(roots[version], u);
        return p < 0 ? u : find(version, p);
    }

    bool merge(int version, int u, int v) {
        u = find(version, u);
        v = find(version, v);
        auto ptr = roots[version];
        if (u != v) {
            int sz_u = -A.get(ptr, u), sz_v = -A.get(ptr, v);
            if (sz_u < sz_v) swap(u, v);
            ptr = A.set(ptr, u, -sz_u - sz_v);
            ptr = A.set(ptr, v, u);
        }

        roots.emplace_back(ptr);
        return u != v;
    }

    int component_size(int version, int u) {
        return -A.get(roots[version], find(version, u));
    }

    bool same_component(int version, int u, int v) {
        return find(version, u) == find(version, v);
    }

    Arr A;
    vector<Arr::Node*> roots;
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // debugLocal();
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        PersistentDSU dsu(n + 1);
        dsu.merge(0, 0, 0);
        for (int i = 1; i <= m; i++) {
            int type, u, v;
            cin >> type >> u >> v;
            if (type == 1) {
                dsu.merge(i, u, v);
                //cout << "TEST: " << dsu.same_component(i, u, v) << endl;
            } else {
                dsu.merge(i, 0, 0);
                if (!dsu.same_component(i, u, v)) {
                    cout << -1 << endl;
                    continue;
                }
                int ll = 1, rr = i, mm;
                while (ll < rr) {
                    mm = (ll + rr) / 2;
                    if (dsu.same_component(mm, u, v))
                        rr = mm;
                    else
                        ll = mm + 1;
                }
                cout << rr - 1 << endl;
            }
        }
    }


    return 0;
}
