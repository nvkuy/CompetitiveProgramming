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

bool check(int numZR, int l, vector<int> a) {
    vector<int> ps(a.size(), 0);
    for (int i = 1; i < a.size(); i++)
        ps[i] = ps[i - 1] + (1 - a[i]);
    for (int i = 1; i + l - 1 < a.size(); i++) {
        int j = i + l - 1;
        if (ps[j] - ps[i - 1] <= numZR) {
            // cout << "SUM RANGE: " << ps[j] - ps[i - 1] << endl;
            // cout << l << ':' << i << '|' << j << endl;
            return true;
        }
    }
    return false;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, k, ai, cnt = 0;
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    for (int i = 0; i < k; i++) {
        cin >> ai;
        a[ai] = 1;
        if (ai == 0)
            cnt++;
    }
    int l = 0, r = n, m;
    while (l < r) {
        if (l + 1 == r) {
            if (check(cnt, r, a))
                l = r;
            break;
        }
        m = (l + r) / 2;
        if (check(cnt, m, a))
            l = m;
        else
            r = m - 1;
    }
    cout << l << endl;

    return 0;
}
