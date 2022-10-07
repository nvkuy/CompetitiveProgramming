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

    int t, b, r, d, s;
    cin >> t;
    while (t--) {
        cin >> b >> r >> d >> s;
        int shot = r > 0;
        shot += ((s * r) / 60);
        if (d - shot * b > 0)
            cout << "gua!";
        else
            cout << "ok";
        cout << endl;
    }

    return 0;
}
