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
        set<pair<int, int>> s1;
        set<int> s2;
        for (int i = 0; i < s.length(); i++)
            s1.insert({s[i] - '0', i});
        string ans;
        vector<int> fixed(s.length(), 0);
        vector<int> a1, a2;
        int curP = 0;
        for (auto p : s1) {
            if (p.second >= curP) {
                fixed[p.second] = 1;
                curP = p.second;
            }
        }
        for (int i = 0; i < s.length(); i++) {
            if (fixed[i])
                a1.push_back(s[i] - '0');
            else
                a2.push_back(min((s[i] - '0' + 1), 9));
        }
        sort(a2.begin(), a2.end());
        reverse(a1.begin(), a1.end());
        reverse(a2.begin(), a2.end());
        while (a1.size() > 0 || a2.size() > 0) {
            int t1 = 1e9, t2 = 1e9;
            if (a1.size() > 0)
                t1 = a1.back();
            if (a2.size() > 0)
                t2 = a2.back();
            if (t1 < t2) {
                cout << t1;
                a1.pop_back();
            } else {
                cout << t2;
                a2.pop_back();
            }
        }
        cout << endl;
    }

    return 0;
}