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

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        map<int, int> cnt;
        for (int i = 0; i < s.length(); i++)
            cnt[s[i] - '0']++;
        if (cnt.size() == 1)
            cout << -1 << endl;
        else {
            if (cnt.size() == 2) {
                if (cnt.begin()->second != 2)
                    cout << 6 << endl;
                else
                    cout << 4 << endl;
            } else
                cout << 4 << endl;
        }
    }

    return 0;
}
