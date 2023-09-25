#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// put two-room first because it make sure everything valid
// min strategy: get 11 first, remain 1 always can get. Min because 11 only +1 to answer
// max strategy: get 00 or 01 or 10. Max because remain one can be always get by one-room => need maximize 1 remain

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    int min_ans = 0, max_ans = 0;
    for (int j = 0; j < n; j++) {
        string s;
        cin >> s;
        int one_cnt = 0;
        for (char c : s) one_cnt += (c - '0');
        vector<int> used(m, 0);
        int rm = m / 4, rm_one = one_cnt;
        for (int i = 0; i + 1 < m; i++) {
            if (rm == 0) break;
            if (used[i]) continue;
            if (s[i] == '1' && s[i + 1] == '1') {
                rm--;
                min_ans++;
                rm_one -= 2;
                used[i] = used[i + 1] = 1;
            }
        }
        min_ans += rm_one;
        rm = m / 4, rm_one = one_cnt;
        fill(used.begin(), used.end(), 0);
        for (int i = 0; i + 1 < m; i++) {
            if (rm == 0) break;
            if (used[i]) continue;
            if (s[i] == '0' && s[i + 1] == '0') {
                rm--;
                used[i] = used[i + 1] = 1;
                continue;
            }
            if (s[i] == '0' || s[i + 1] == '0') {
                rm--;
                max_ans++;
                rm_one--;
                used[i] = used[i + 1] = 1;
            }
        }
        rm_one -= rm;
        max_ans += rm_one;
    }
    cout << min_ans << ' ' << max_ans << endl;

    return 0;
}
