#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<int>> cycle(10), to_cycle(10);
const int base = 10;

long long cal(long long s, long long k) {
    vector<long long> cnt(base, 0);
    for (auto num : to_cycle[s]) {
        if (k == 0) break;
        cnt[num]++;
        k--;
    }
    long long tmp = k / cycle[s].size();
    k %= cycle[s].size();
    for (auto num : cycle[s])
        cnt[num] += tmp;
    for (auto num : cycle[s]) {
        if (k == 0) break;
        cnt[num]++;
        k--;
    }
    long long res = 0;
    for (long long num = 0; num < base; num++)
        res += (num * cnt[num]);
    return res;
}

long long calCost(long long s, long long k, long long use_bonus) {
    long long val = cal(s % base, max(k - use_bonus, 0LL)) + s;
    return val * min(use_bonus, k);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    for (int i = 0; i < base; i++) {
        vector<int> dd(base, 0), tmp;
        int num = i;
        while (true) {
            if (dd[num]) break;
            dd[num] = 1;
            tmp.push_back(num);
            num *= 2;
            num %= base;
        }

        // cout << "@i = " << i << ": ";
        // for (auto num : tmp)
        //     cout << num << ' ';
        // cout << endl;

        for (int j = 0; j < tmp.size(); j++) {
            if (tmp[j] == num) {
                for (int k = j; k < tmp.size(); k++)
                    cycle[i].push_back(tmp[k]);
                break;
            }
            to_cycle[i].push_back(tmp[j]);
        }
    }

    int t;
    cin >> t;
    while (t--) {
        long long s, k;
        cin >> s >> k;
        
        if ((s % base) == 0) {
            cout << s * k << endl;
            continue;
        }
        if ((s % base) == 5) {
            if (k == 1)
                cout << s << endl;
            else
                cout << calCost(s, k, k - 1) << endl;
            continue;
        }
        int l = 1, r = k, m1, m2, optimal = 1;
        while (l < r) {
            // cout << l << ' ' << r << endl;
            if (r - l <= 33) {
                for (int i = l; i <= r; i++)
                    if (calCost(s, k, optimal) < calCost(s, k, i))
                        optimal = i;
                break;
            }
            int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
            long long c1 = calCost(s, k, m1), c2 = calCost(s, k, m2);
            // if (c1 == c2) {
            //     r++;
            //     continue;
            // }
            if (c1 < c2)
                l = m1 + 1;
            else
                r = m2 - 1;
        }
        cout << calCost(s, k, optimal) << endl;
        
    }

    return 0;
}
