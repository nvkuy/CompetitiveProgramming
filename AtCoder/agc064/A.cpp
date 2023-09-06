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

    int n;
    cin >> n;
    deque<int> ans;
    for (int i = n; i > 1; i -= 2) {
        ans.push_back(i);
        for (int j = 1; j < i; j++) {
            if (j % 2) {
                ans.push_back(i - 1);
                ans.push_back(i);
            } else {
                ans.push_front(i - 1);
                ans.push_front(i);
            }
        }
    }
    if (n % 2) ans.push_back(1);
    for (int num : ans) cout << num << ' ';
    cout << endl;

    return 0;
}
