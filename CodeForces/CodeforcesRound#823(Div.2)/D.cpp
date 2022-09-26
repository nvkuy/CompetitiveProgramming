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

    // freopen("in", "r", stdin);

    int t, n;
    string s1, s2;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        getline(cin, s1);
        getline(cin, s2);
        map<pair<char, char>, int> cnt;
        vector<pair<char, char>> odd_cnt;
        for (int i = 0; i < n; i++) {
            int j = n - i - 1;
            if (s1[i] > s2[j])
                swap(s1[i], s2[j]);
            cnt[{s1[i], s2[j]}]++;
        }
        for (auto p : cnt) {
            if (p.second % 2 == 0)
                continue;
            odd_cnt.push_back(p.first);
        }
        if (odd_cnt.size() > 1 || (odd_cnt.size() > 0 && odd_cnt[0].first != odd_cnt[0].second)) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }

    return 0;
}