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

/*
    idea:
    sum c[] is sum of prefix fib => find n: the len of fib prefix
    because f[n] = f[n - 1] + f[n - 2] = 2f[n - 2] + f[n - 3] = f[n - 2] + 2f[n - 3] + f[n - 4] = ..
    => consider c[i] >= f[j], if we don't put c[i] in f[j], high change we can't put anywhere else
    => can greedy put c[i] from largest to smallest, but carefull that c[i] has to be the current max in c[]
    
*/

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long k;
        cin >> k;
        vector<long long> c(k);
        for (int i = 0; i < k; i++) cin >> c[i];
        long long sum = accumulate(c.begin(), c.end(), 0LL);
        if (sum == 1 || (sum == 2 && k == 2)) {
            cout << "YES" << endl;
            continue;
        }
        vector<long long> fi(2, 1);
        sum -= 2;
        while (true) {
            if (sum <= 0) break;
            int sz = fi.size();
            fi.push_back(fi[sz - 1] + fi[sz - 2]);
            sum -= fi.back();
        }
        if (sum < 0) {
            cout << "NO" << endl;
            continue;
        }
        vector<int> used(fi.size(), -1);
        set<pair<long long, int>> num;
        for (int i = 0; i < k; i++) num.insert({c[i], i});
        while (true) {
            if (num.size() == 0) break;
            auto best = *num.rbegin();
            num.erase(num.lower_bound(best));
            bool canPut = false;
            for (int i = fi.size() - 1; i >= 0; i--) {
                if (fi[i] > best.first || used[i] >= 0 || (i + 1 < fi.size() && used[i + 1] == best.second)) continue;
                canPut = true;
                best.first -= fi[i];
                used[i] = best.second;
                break;
            }
            if (best.first > 0) num.insert(best);
            if (!canPut) break;
        }
        cout << (num.size() == 0 ? "YES" : "NO") << endl;
    }

    return 0;
}