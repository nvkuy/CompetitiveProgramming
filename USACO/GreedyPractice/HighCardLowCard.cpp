#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("cardgame.in", "r"))
        return;
    freopen("cardgame.in", "r", stdin);
    freopen("cardgame.out", "w", stdout);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    set<int> s1, s2, s;
    for (int i = 0; i < n; i++) s.insert(a[i]);
    for (int i = 1; i <= 2 * n; i++) {
        if (s.find(i) == s.end())
            s1.insert(i);
    }
    for (int i = 0; i < n / 2; i++) {
        int ai = *s1.begin();
        s1.erase(ai);
        s2.insert(ai);
    }
    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
        auto it = s1.lower_bound(a[i]);
        if (it != s1.end()) {
            ans++;
            s1.erase(it);
        }
    }
    for (int i = n / 2; i < n; i++) {
        auto it = s2.lower_bound(a[i]);
        if (it != s2.begin()) {
            it--;
            ans++;
            s2.erase(it);
        }
    }
    cout << ans << endl;

    return 0;
}
