#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)
#define low_bit(x) __builtin_ctzll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> seat(m + 1, 0);
        int goLeft = 0, goRight = 0;
        for (int i = 0; i < n; i++) {
            int ai;
            cin >> ai;
            if (ai == -1)
                goLeft++;
            else if (ai == -2)
                goRight++;
            else
                seat[ai] = 1;
        }
        for (int i = 1; i <= m; i++)
            seat[i] += seat[i - 1];
        int ans = min(m, max(goLeft, goRight) + seat[m]);
        for (int i = 1; i <= m; i++) {
            if (seat[i] == seat[i - 1]) continue;
            int tans = seat[m], space_left = i - seat[i], space_right = m - i - (seat[m] - seat[i]);
            tans += min(goLeft, space_left);
            tans += min(goRight, space_right);
            ans = max(ans, tans);
        }
        cout << ans << endl;
    }

    return 0;
}
