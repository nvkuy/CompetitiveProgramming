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

    vector<int> cnt(1 << 10, 0);
    string s;
    cin >> s;

    long long ans = 0;
    int cur_xor = 0;
    for (int i = 0; i < s.length(); i++) {
        cur_xor ^= (1 << (s[i] - '0'));
        cnt[cur_xor]++;
    }
    cur_xor = 0;
    for (int i = 0; i < s.length(); i++) {
        ans += cnt[cur_xor];
        cur_xor ^= (1 << (s[i] - '0'));
        cnt[cur_xor]--;
    }

    cout << ans << endl;

    return 0;
}