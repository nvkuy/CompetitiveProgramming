#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        deque<int> dq(n);
        for (int i = 0; i < n; i++) cin >> dq[i];
        sort(dq.begin(), dq.end());
        if (dq.front() == 0 && dq.back() == 0) {
            cout << "NO" << endl;
            continue;
        }
        // cout << "TEST: ";
        // for (int ai : dq) cout << ai << ' ' << ' ';
        // cout << endl;
        vector<int> ans;
        long long cs = 0;
        for (int i = 0; i < n; i++) {
            if (cs > 0) {
                ans.push_back(dq.front());
                dq.pop_front();
            } else {
                ans.push_back(dq.back());
                dq.pop_back();
            }
            cs += ans.back();
            // cout << "CS = " << cs << ' ';
            // cout << "STEP " << i << ": ";
            // for (int ai : ans)
            //     cout << ai << ' ';
            // cout << endl;
        }
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}
