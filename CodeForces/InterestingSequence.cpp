#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        long long n, x;
        cin >> n >> x;
        if (n == x) {
            cout << n << endl;
            continue;
        }
        bool iok = true;
        for (int i = 0; i < 61; i++)
            iok &= (((n >> i) & 1) >= ((x >> i) & 1));
        if (!iok) {
            cout << -1 << endl;
            continue;
        }
        int last_diff = 0;
        for (int i = 0; i < 61; i++)
            if (((n >> i) & 1) != ((x >> i) & 1)) last_diff = i;
        long long pre_val_n = 0;
        for (int i = 0; i < last_diff; i++)
            pre_val_n |= (((n >> i) & 1) << i);
        long long m = n + (1LL << last_diff) - pre_val_n;
        if ((n & m) != x) {
            cout << -1 << endl;
            continue;
        }
        cout << m << endl;
    }

    return 0;
}