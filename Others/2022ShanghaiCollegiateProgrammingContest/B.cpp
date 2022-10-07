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

struct range {
    int l, r, no;
};

bool cmp(range r1, range r2) {
    return r1.r - r1.l < r2.r - r2.l;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, q;
    cin >> n >> q;
    vector<int> a(n, -1);
    vector<range> rgs(q);
    bool iok = true;
    for (int i = 0; i < q; i++) {
        cin >> rgs[i].l >> rgs[i].r >> rgs[i].no;
        rgs[i].l--, rgs[i].r--;
        int nn = rgs[i].r - rgs[i].l + 1;
        if (abs(rgs[i].no) > nn || (nn + rgs[i].no) % 2 != 0)
            iok = false;
        rgs[i].no = (nn + rgs[i].no) / 2;        
    }
    rgs.push_back({0, n - 1, n / 2});
    sort(rgs.begin(), rgs.end(), cmp);
    for (range r : rgs) {
        int no = 0;
        for (int i = r.l; i <= r.r; i++)
            no += (a[i] == 1);
        if (no > r.no) {
            iok = false;
            break;
        }
        int rm = r.no - no;
        for (int i = r.l; i <= r.r; i++) {
            if (a[i] != -1)
                continue;
            if (rm > 0) {
                rm--;
                a[i] = 1;
            } else
                a[i] = 0;
        }
        if (rm > 0) {
            iok = false;
            break;
        }
    }
    if (!iok) {
        cout << "?" << endl;
        return 0;
    }
    cout << "! ";
    for (int i = 0; i < n; i++)
        cout << (a[i] ? '(' : ')');
    cout << endl;

    return 0;
}
