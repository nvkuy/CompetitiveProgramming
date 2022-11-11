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

    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        int flip_cnt = 0, n0 = 0, n1 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') n0++;
            else n1++;
        }
        for (int i = 0; i < n; i++) {
            if (flip_cnt % 2)
                s[i] = (1 - (s[i] - '0')) + '0';
            if (s[i] == '1' && n0 > 0) {
                flip_cnt++;
                swap(n0, n1);
                s[i] = '0';
            }
            if (s[i] == '0')
                n0--;
            else
                n1--;
        }
        cout << flip_cnt << endl;
        
    }

    return 0;
}
