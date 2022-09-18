#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long k;
    string s;
    cin >> k;
    cin >> s;

    int ans = 0;
    while (stoll(s, 0, 2) > k) {
        int fo = s.length() - 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '1') {
                fo = i;
                break;
            }
        }
        s.erase(s.begin() + fo);
        ans++;
    }
    cout << ans;

    return 0;
}
