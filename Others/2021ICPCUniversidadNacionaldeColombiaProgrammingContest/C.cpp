#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main()
{
    

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen("input", "r", stdin);

    string s;
    while (cin >> s) {
        long long ans = 0;
        for (int i = 0; i < s.length(); i++) {
            string t = s.substr(i);
            vector<int> pf = prefix_function(t);
            for (int j = 0; j < pf.size(); j++)
                ans += pf[j];
        }
        cout << ans << endl;
    }

    return 0;
}