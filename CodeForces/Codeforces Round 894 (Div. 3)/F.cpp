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

const int MAXN = 1e6;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long a, b, sum = 0;
        cin >> a >> b;
        if (a > b) swap(a, b);
        int n;
        cin >> n;
        bitset<MAXN + 1> sum_subset(0);
        sum_subset[0] = 1;
        while (n--) {
            int ai;
            cin >> ai;
            sum += ai;
            sum_subset |= (sum_subset << ai);
        }
        long long ans = 1e9;
        for (int i = 0; i <= MAXN; i++) {
            if (sum_subset[i]) {
                long long s1 = i, s2 = sum - s1;
                if (s1 > s2) swap(s1, s2);
                ans = min(ans, max(s1 / a + (s1 % a > 0), s2 / b + (s2 % b > 0)));
            }
        }
        cout << ans << endl;
    }

    return 0;
}
