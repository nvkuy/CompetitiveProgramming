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

long long cal(const string &tmp, int pos) {
    if (pos == tmp.length()) return 0LL;
    long long tt = tmp[pos] - '0';
    if (tt >= 4) tt--;
    if (tmp[pos] == '4') return tt * pow(9, tmp.length() - pos - 1);
    return cal(tmp, pos + 1) + tt * pow(9, tmp.length() - pos - 1);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t;
    cin >> t;
    while (t--) {
        long long k;
        cin >> k;
        long long ll = 1, rr = 2e18, mm;
        while (ll < rr) {
            mm = (ll + rr) / 2LL;
            if (cal(to_string(mm), 0) - 1LL >= k)
                rr = mm;
            else
                ll = mm + 1;
        }
        cout << rr << endl;
    }

    return 0;
}
