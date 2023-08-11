#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int const MaxN = 4e5 + 3;
int cnt_xor[MaxN + 1];
vector<int> bad_num;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i <= MaxN; i++) {
        map<int, int> cnt;
        int rm = i;
        for (int j = 2; j * j <= i; j++) {
            if (j > rm) break;
            int tcnt = 0;
            while (rm % j == 0) {
                tcnt++;
                rm /= j;
            }
            if (tcnt > 0)
                cnt[j] += tcnt;
        }
        if (rm > 1)
            cnt[rm]++;
        bool isBad = true;
        for (auto p : cnt)
            isBad &= (p.second % 2 == 0);
        if (isBad)
            bad_num.push_back(i);
    }
    // cout << bad_num.size() << endl;
    // return 0;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        long long bad_cnt = 0;
        for (int num : bad_num) {
            if (num > 2 * n) break;
            // map<int, int> cnt;
            int pre_xor = 0;
            for (int i = 0; i < n; i++) {
                pre_xor ^= a[i];
                cnt_xor[pre_xor]++;
            }
            pre_xor = 0;
            for (int i = 0; i < n; i++) {
                if ((num ^ pre_xor) <= MaxN)
                    bad_cnt += cnt_xor[num ^ pre_xor];
                pre_xor ^= a[i];
                cnt_xor[pre_xor]--;
            }
        }
        // cout << "@bad_seg: " << bad_cnt << endl;
        cout << (1LL * n * (n + 1)) / 2 - bad_cnt << endl;
    }

    return 0;
}
