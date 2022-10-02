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

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

struct node {
    int p, q, x1, x2;
    node();
    node(int a, int b, int c, int d): p(a), q(b), x1(c), x2(d) {}
};

vector<vector<int>> c;

bool check(int u, long long w) {

}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, p, q, x1, x2;
    cin >> n;
    vector<node> ns(n + 1);
    set<int> notRoot;
    for (int i = 1; i <= n; i++) {
        cin >> p >> q >> x1 >> x2;
        long long g = gcd(p, q);
        if (g != 0)
            p /= g, q /= g;
        ns[i] = {p, q, x1, x2};
        notRoot.insert(x1);
        notRoot.insert(x2);
        c[i].push_back(x1);
        c[i].push_back(x2);
    }
    int root = -1;
    for (int i = 1; i <= n; i++) {
        if (notRoot.find(i) == notRoot.end()) {
            root = i;
            break;
        }
    }

    return 0;
}
