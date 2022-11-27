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

    int t;
    string s;
    cin >> t;
    while (t--) {
        cin >> s;
        map<char, int> cnt;
        for (char c : s)
            cnt[c]++;
        deque<char> ans;
        for (auto p : cnt) {
            for (int i = 0; i < p.second; i++) {
                ans.push_back(p.first);
                ans.push_front(p.first);
            }
        }
        for (char c : ans)
            cout << c;
        cout << endl;
    }

    return 0;
}
