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

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        // if (n == 1) {
        //     cout << s << endl;
        //     continue;
        // }
        // if (n == 2) {
        //     if (s[0] > s[1] && k == 2) swap(s[0], s[1]);
        //     cout << s << endl;
        //     continue;
        // }
        // sort(s.begin(), s.end());
        // cout << s << endl;
        if (k % 2 == 0) sort(s.begin(), s.end());
        else {
            string s1, s2;
            for (int i = 0; i < n; i++) {
                if (i % 2) s2.push_back(s[i]);
                else s1.push_back(s[i]);
            }
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
            int j = 0, k = 0;
            for (int i = 0; i < n; i++) {
                if (i % 2) {
                    s[i] = s2[j];
                    j++;
                } else {
                    s[i] = s1[k];
                    k++;
                }
            }
        }
        cout << s << endl;
    }

    return 0;
}
