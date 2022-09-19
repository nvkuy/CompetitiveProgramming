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

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        set<pair<int, int>> ms;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            ms.insert({a[i], i});
        }
        vector<pair<int, int>> ans;
        int r = n - 1;
        while (r > 0) {
            auto it = ms.rbegin();
            pair<int, int> tmp = *it;
            ms.erase(ms.find(tmp));
            for (int i = r; i > tmp.second; i--) {
                if ((a[r] + a[tmp.second]) % 2 == 1) {
                    ms.erase(ms.find({a[r], r}));
                    r--;
                    ans.push_back({tmp.second, r});
                } else {
                    int minPos = r;
                    for (int j = r; j > tmp.second; j--) {
                        if ((a[tmp.second] + a[j]) % 2 == 0 && a[j] < a[minPos])
                            minPos = j;
                    }
                    ans.push_back({tmp.second, minPos});
                    a[tmp.second] = a[minPos];
                    ms.insert({a[tmp.second], tmp.second});
                    break;
                }
            }
            if (r == tmp.second)
                r--;
        }
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl;
    }

    return 0;
}