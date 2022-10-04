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

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    long long t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> a(k);
        bool iok = true;
        for (int i = 0; i < k; i++)
            cin >> a[i];
        if (k == 1) {
            cout << "YES" << endl;
            continue;
        }
        vector<long long> tmp;
        for (int i = 1; i < a.size(); i++)
            tmp.push_back(a[i] - a[i - 1]);
        for (int i = 1; i < tmp.size(); i++)
            if (tmp[i] < tmp[i - 1])
                iok = false;
        long long rm = (n - k + 1) * tmp[0];
        if (rm < a[0])
            iok = false;
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
