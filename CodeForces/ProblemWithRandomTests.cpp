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

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> one_pos;
    int start = n;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0' && one_pos.size() > 0) {
            start = i;
            break;
        }
        if (s[i] == '1')
            one_pos.push_back(i);
    }

    string tmp(n, '0');
    for (int i = start; i < n; i++) {
        if (s[i] == '1') continue;
        vector<int> next_one_pos;
        int dt = i - start;
        for (int pos : one_pos) {
            int next_pos = pos + dt;
            // cout << "@i: " << i << ' ' << pos << ' ' << next_pos << endl;
            if (next_pos < n && s[next_pos] == '1')
                next_one_pos.push_back(pos);
        }
        if (next_one_pos.size() > 0) {
            tmp[i] = '1';
            one_pos = next_one_pos;
        }
        // cout << "@i: " << i << ' ';
        // for (auto pos : one_pos) cout << pos << ' ';
        // cout << endl;
    }

    for (int i = 0; i < n; i++)
        if (tmp[i] == '1') s[i] = '1';
    reverse(s.begin(), s.end());
    while (s.size() > 1 && s.back() == '0') s.pop_back();
    reverse(s.begin(), s.end());
    cout << s << endl;

    return 0;
}
