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

    string s;
    cin >> s;
    int oc = 0, zc = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1')
            oc++;
        else
            zc++;
    }
    vector<int> ans(s.length(), (oc > zc ? 0 : 1));
    if (oc == zc) {
        vector<int> free;
        for (int i = 0; i < ans.size(); i++) {
            if (s[i] - '0' != ans[i])
                continue;
            free.push_back(i);
        }
        int pos = rand() % free.size();
        ans[pos] = 1 - ans[pos];
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i];

    return 0;
}
