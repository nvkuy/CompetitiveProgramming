#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int k, f[524288];
string s;

void merge(int id, int id_c1, int id_c2) {
    int id_s = (1 << k) - id - 2;
    int res;
    if (s[id_s] == '0')
        res = f[id_c1];
    else if (s[id_s] == '1')
        res = f[id_c2];
    else
        res = f[id_c1] + f[id_c2];
    f[id] = res;
}

void build(int id) {
    if (id >= (1 << k) - 1) {
        f[id] = 1;
        return;
    }
    build(id * 2 + 2);
    build(id * 2 + 1);
    merge(id, id * 2 + 2, id * 2 + 1);
}

void update(int id) {
    int id_f = (1 << k) - id - 2;
    while (true) {
        merge(id_f, id_f * 2 + 2, id_f * 2 + 1);
        if (id_f == 0) break;
        id_f = (id_f - 1) / 2;
    }
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> k;
    cin >> s;

    build(0);

    int q;
    cin >> q;
    while (q--) {
        int p;
        char c;
        cin >> p >> c;
        p--;
        s[p] = c;
        update(p);
        cout << f[0] << endl;
    }

    return 0;
}
