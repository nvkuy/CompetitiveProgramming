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

    long long n, p, h;
    cin >> n >> p >> h;
    long long r = 1LL << n;
    string ans, same_side;
    while (r > 1) {
        long long l = r / 2LL;
        if (h > l) {
            h = r - h + 1;
            same_side.push_back('1');
            
        } else 
            same_side.push_back('0');
        r /= 2LL;
    }
    reverse(same_side.begin(), same_side.end());
    long long cur_l = 1, cur_r = 1LL << n;
    for (char c : same_side) {
        if (c == '1') {
            //same side
            if (p - cur_l < cur_r - p) {
                ans.push_back('L');
                cur_r /= 2LL;
            } else {
                ans.push_back('R');
                cur_l = (cur_r / 2LL) + 1LL;
            }
            p = cur_r - p + cur_l;
        } else {
            //not same side
            if (p - cur_l < cur_r - p) {
                ans.push_back('R');
                cur_r /= 2LL;
            } else {
                ans.push_back('L');
                cur_l = (cur_r / 2LL) + 1LL;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
