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

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long sum = n * (n + 1) / 2;
        vector<long long> a(n - 1);
        map<long long, int> cnt;
        bool iok = true;
        for (int i = 0; i + 1 < n; i++) {
            cin >> a[i];
            if (i == 0) {
                if (a[i] <= 0)
                    iok = false;
                else
                    cnt[a[i]]++;
            } else {
                if (a[i] <= a[i - 1])
                    iok = false;
                else
                    cnt[a[i] - a[i - 1]]++;
            }
        }
        if (a[n - 2] != sum) {
            if (a[n - 2] > sum) iok = false;
            else
                cnt[sum - a[n - 2]]++;
        }
        vector<long long> have, not_have;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == 0)
                not_have.push_back(i);
            else {
                while (cnt[i] > 1) {
                    have.push_back(i);
                    cnt[i]--;
                }
            }
        }
        auto it = cnt.upper_bound(n);
        while (it != cnt.end()) {
            while (it->second--)
                have.push_back(it->first);
            it++;
        }
        if (not_have.size() > 0) {
            if (have.size() == 1 && not_have.size() == 2) {
                if (have[0] != not_have[0] + not_have[1])
                    iok = false;
            } else
                iok = false;
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
