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

//DM THANG RA DE =((((((((

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        long long sum = accumulate(a.begin(), a.end(), 0LL);
        if (sum % n != 0) {
            cout << "NO" << endl;
            continue;
        }
        long long equal = sum / n;
        bool iok = true;
        vector<int> f(60, 0);
        for (int i = 0; i < n; i++) {
            if (a[i] == equal) continue;
            int cnt = 0;
            for (int give = 0; give <= 55; give++) {
                for (int take = 0; take <= 55; take++) {
                    if ((1LL << take) - (1LL << give) + a[i] == equal) {
                        f[take]++;
                        f[give]--;
                        cnt++;
                    }
                }
            }
            if (cnt != 1)
                iok = false;
        }
        for (int i = 0; i < 60; i++) iok &= (f[i] == 0);
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
