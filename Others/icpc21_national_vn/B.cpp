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

int cost(char a, char b) {
    int res = abs(a - b);
    res = min(res, abs(a - 'A') + abs(b - 'Z') + 1);
    res = min(res, abs(a - 'Z') + abs(b - 'A') + 1);
    return res;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int r, c, ans = 0;
    cin >> r >> c;
    vector<string> cc(r);
    for (int i = 0; i < r; i++)
        cin >> cc[i];
    for (int i = 0; i < (r + 1) / 2; i++) {
        for (int j = 0; j < (c + 1) / 2; j++) {
            int tans = 1e6, oi = r - i - 1, oj = c - j - 1;
            for (char nc = 'A'; nc <= 'Z'; nc++) {
                if (oi == i && oj == j) {
                    tans = 0;
                    break;
                }
                if (oi == i) {
                    tans = min(tans, cost(cc[i][j], nc) + cost(cc[i][oj], nc));
                    continue;
                }
                if (oj == j) {
                    tans = min(tans, cost(cc[i][j], nc) + cost(cc[oi][j], nc));
                    continue;
                }
                tans = min(tans, cost(cc[i][j], nc) + cost(cc[oi][j], nc) + cost(cc[i][oj], nc) + cost(cc[oi][oj], nc));
            }
            //cout << i << '|' << j << '-' << tans << endl;
            ans += tans;
        }
    }
    cout << ans << endl;

    return 0;
}
