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

const long long mod = 998244353;

long long power(long long num, long long pow) {
    if (pow == 0) return 1;
    if (num >= mod) return power(num % mod, pow);
    if (pow % 2) return (num * power(num, pow - 1)) % mod;
    return power(num * num, pow / 2);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long n;
    cin >> n;
    long long all_way = 0;
    map<int, long long> cnt;
    for (int i = 0; i < n; i++) {
        long long k;
        cin >> k;
        all_way += (n - i) * k;
        all_way %= mod;
        while (k--) {
            int ai;
            cin >> ai;
            cnt[ai]++;
        }
    }
    long long valid_way = 0;
    for (auto p : cnt) {
        valid_way += (p.second * (p.second + 1)) / 2;
        valid_way %= mod;
    }
    // cout << all_way << endl;
    // cout << valid_way << endl;
    cout << (valid_way * power(all_way, mod - 2)) % mod << endl;

    return 0;
}
