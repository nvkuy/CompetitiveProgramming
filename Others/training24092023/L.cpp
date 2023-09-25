#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)
#define low_bit(x) __builtin_ctzll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

    // get p-th element in `t` version
    static T get(Node* t, int p) {
        if (t == NULL) return 0;
        return p ? get(t->child[p & FULL_MASK], p >> LOG) : t->x;
    }

    // set p-th element in `t` version to x, and return new version
    static Node* set(Node* t, int p, const T& x) {
        t = (t == NULL) ? new Node(0) : new Node(*t);
        if (p == 0) t->x = x;
        else {
            auto ptr = set(t->child[p & FULL_MASK], p >> LOG, x);
            t->child[p & FULL_MASK] = ptr;
        }
        return t;
    }

    // init a persistent array and return root node
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
        // Note that we can't do path compression here
        int p = A.get(roots[version], u);
        return p < 0 ? u : find(version, p);
    }

    // Note that this will always create a new version,
    // regardless of whether u and v was previously in same component.
    bool merge(int version, int u, int v) {
        u = find(version, u);
        v = find(version, v);
        auto ptr = roots[version];
        if (u != v) {
            int sz_u = -A.get(ptr, u), sz_v = -A.get(ptr, v);
            if (sz_u < sz_v) swap(u, v);
            // sz[u] >= sz[v]
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

vector<int> par;

int findRoot(int u) {
    if (par[u] < 0) return u;
    return par[u] = findRoot(par[u]);
}

void merge(int u, int v) {
    int r1 = findRoot(u), r2 = findRoot(v);
    if (r1 == r2) return;
    if (par[r1] > par[r2]) swap(r1, r2);
    par[r1] += par[r2];
    par[r2] = r1;
}

struct edge {
    int u, v, w;
};

bool cmp(const edge &e1, const edge &e2) {
    return e1.w < e2.w;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, ver = 0;
    cin >> n >> m;
    PersistentDSU pdsu(n + 1);
    par.assign(n + 1, -1);
    vector<edge> e(m);
    vector<int> need_del, not_del;
    for (int i = 0; i < m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    
    sort(e.begin(), e.end(), cmp);
    for (int i = 0; i < m; i++) {
        int r1 = findRoot(e[i].u), r2 = findRoot(e[i].v);
        if (r1 == r2) {
            pdsu.merge(ver++, e[i].u, e[i].v);
            not_del.push_back(i);
            continue;
        }
        need_del.push_back(i);
        merge(e[i].u, e[i].v);
    }

    // for (int i = 0; i < m; i++)
    //     cout << e[i].u << ' ' << e[i].v << ' ' << e[i].w << endl; 
 
    // for (int id : need_del)
    //     cout << id << ' ';
    // cout << endl;

    // cout << pdsu.same_component(ver, 1, 2) << ' ' << pdsu.same_component(ver, 1, 3) << endl;

    long long ans = 0;
    bool hasAns = true;
    for (int id_del : need_del) {
        if (ver < 0 || !pdsu.same_component(ver, e[id_del].u, e[id_del].v)) {
            hasAns = false;
            break;
        }
        int l = 1, r = ver, m;
        while (l < r) {
            m = (l + r) / 2;
            if (pdsu.same_component(m, e[id_del].u, e[id_del].v))
                r = m;
            else
                l = m + 1;
        }
        // assert(r < not_del.size());
        ans += e[not_del[r - 1]].w + 1 - e[id_del].w;
    }

    if (!hasAns) {
        cout << -1 << endl;
        return 0;
    }

    cout << ans << endl;

    return 0;
}
