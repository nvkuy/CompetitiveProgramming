#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const long long mod = 1e9 + 7;

long long power(long long num, long long pow) {
    if (pow == 0) return 1;
    if (pow % 2) return (num * power(num, pow - 1)) % mod;
    return power((num * num) % mod, pow / 2);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            int ai;
            cin >> ai;
            cnt[ai]++;
        }
        long long ans = 0, tmp = cnt.begin()->second, cur_num = 1;
        auto it = cnt.begin();
        for (auto p : cnt) {
            while (true) {
                it++;
                if (it == cnt.end() || it->first - p.first >= m) {
                    it--;
                    break;
                }
                cur_num++;
                tmp = (tmp * it->second) % mod;
            }
            if (cur_num == m) ans = (ans + tmp) % mod;
            cur_num--;
            tmp = (tmp * power(p.second, mod - 2)) % mod;
        }
        cout << ans << endl;
    }

    return 0;
}
