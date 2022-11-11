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

int cal_mex(vector<int> &a) {
    int ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == ans)
            ans++;
        if (a[i] > ans)
            break;
    }
    return ans;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t, n, k;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cin.ignore();
        getline(cin, s);
        vector<int> cnt(33, 0);
        for (int i = 0; i < n; i++)
            cnt[s[i] - 'a']++;
        int num = n / k;
        vector<vector<int>> ans(k);
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < num; j++) {
                if (cnt[j] > 0) {
                    ans[i].push_back(j);
                    cnt[j]--;
                } else
                    break;
            }
        }
        int j = 0;
        for (int i = 0; i < k; i++) {
            while (true) {
                if (ans[i].size() == num)
                    break;
                while (cnt[j] == 0)
                    j++;
                ans[i].push_back(j);
                cnt[j]--;
            }
        }
        for (int i = 0; i < k; i++)
            cout << char(cal_mex(ans[i]) + 'a');
        cout << endl;
    }

    return 0;
}
