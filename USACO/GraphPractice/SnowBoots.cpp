#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

inline void debugLocal() {
    if (!fopen("snowboots.in", "r"))
        return;
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n, b;
    cin >> n >> b;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<pair<int, int>> boot(b);
    for (int i = 0; i < b; i++) cin >> boot[i].first >> boot[i].second;

    vector<int> dd(n, -1);
    dd[0] = 0;
    for (int i = 0; i < b; i++) {
        for (int j = 0; j < n; j++) {
            if (dd[j] == -1 || a[j] > boot[i].first) continue;
            for (int k = 0; k < n; k++) {
                if (dd[k] == -1 && abs(k - j) <= boot[i].second && a[k] <= boot[i].first)
                    dd[k] = i;
            }
        }
        if (dd[n - 1] != -1) break;
    }
    cout << dd[n - 1] << endl;

    return 0;
}
