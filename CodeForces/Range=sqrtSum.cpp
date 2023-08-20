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
        int n;
        cin >> n;
        if (n == 1) {
            cout << 4 << endl;
            continue;
        }
        vector<int> ans(n);
        if (n % 2) {
            int tmp = n;
            for (int i = n / 2 - 1; i >= 0; i--) {
                ans[i] = tmp;
                tmp--;
            }
            tmp = n + 3;
            for (int i = n / 2; i < n; i++) {
                ans[i] = tmp;
                tmp++;
            }
        } else {
            int tmp = n - 1;
            for (int i = n / 2 - 1; i >= 0; i--) {
                ans[i] = tmp;
                tmp--;
            }
            tmp = n + 1;
            for (int i = n / 2; i < n; i++) {
                ans[i] = tmp;
                tmp++;
            }
        }
        for (int num : ans)
            cout << num << ' ';
        cout << endl;
    }

    return 0;
}
