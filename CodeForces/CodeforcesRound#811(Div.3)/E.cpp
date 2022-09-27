#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugMode() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

bool try_make(int val, vector<int> a) {
    vector<int> b, c;
    set<int> zr;
    for (int i = 0; i < a.size(); i++) {
        b.push_back(a[i] / 10);
        c.push_back(a[i] % 10);
    }
    int odd_cnt = 0;
    for (int i = 0; i < c.size(); i++) {
        for (int j = 0; j < 10; j++) {
            if ((c[i] % 10) == val)
                break;
            if ((c[i] % 10) * 2 >= 10)
                b[i]++;
            c[i] += (c[i] % 10);
        }
        if ((c[i] % 10) != val)
            return false;
        odd_cnt += (b[i] % 2);
        for (int j = 0; j < 10; j++) {
            if ((c[i] % 10) == 0) {
                zr.insert(b[i]);
                break;
            }
            if ((c[i] % 10) * 2 >= 10)
                b[i]++;
            c[i] += (c[i] % 10);
        }
    }
    if (zr.size() > 1)
        return false;
    if (odd_cnt == a.size() || odd_cnt == 0)
        return true;
    return false;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugMode();

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        bool iok = false;
        for (int i = 0; i < 10; i++)
            iok |= try_make(i, a);
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}