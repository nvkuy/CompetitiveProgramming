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

    string s;
    cin >> s;

    int p10[10];
    for (int i = 0; i < 10; i++)
        p10[i] = pow(10, i);
    int last = p10[s.length()] - 1, sz = s.length(), first = p10[s.length() - 1] - 1;
    while (first % 25 > 0) first++;
    vector<int> fixed, same, opt;
    for (int i = 0; i < sz; i++) {
        if (s[i] == '_')
            opt.push_back(i);
        else if (s[i] == 'X')
            same.push_back(i);
        else
            fixed.push_back(i);
    }

    int ans = 0;
    for (int num = first; num <= last; num += 25) {
        bool iok = true;
        for (int p : fixed) {
            if (!iok) break;
            if ((s[p] - '0') != ((num / p10[sz - p - 1]) % 10)) iok = false;
        }
        for (int p : same) {
            if (!iok) break;
            if (((num / p10[sz - p - 1]) % 10) != ((num / p10[sz - same[0] - 1]) % 10)) iok = false;
        }
        if (num / p10[sz] > 0) iok = false;
        if (((num / p10[sz - 1]) % 10) == 0 && sz > 1) iok = false;
        if (num > 0 && same.size() > 0 && same[0] == 0 && ((num / p10[sz - same[0] - 1]) % 10) == 0) iok = false;
        if (num > 0 && opt.size() > 0 && opt[0] == 0 && ((num / p10[sz - opt[0] - 1]) % 10) == 0) iok = false;
        ans += iok;
        // if (iok)
        //     cout << num << endl;
    }

    cout << ans << endl;

    return 0;
}
