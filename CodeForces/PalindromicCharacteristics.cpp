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

bool cmpSubStr(int l, int r, vector<vector<int>> &pfl) {
    return pfl[l][r - l] >= (r - l + 1) / 2;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> f(n, vector<int>(n, 0)), pfl(n);
    vector<int> ans(n + 1, 0);
    for (int i = 0; i < n; i++) {
        f[i][i] = 1;
        ans[1]++;
    }
    for (int i = 0; i < n; i++)
        pfl[i] = prefix_function(s.substr(i, n - i));
    for (int len = 2; len <= n; len++) {
        for (int l = 0; l < n; l++) {
            int r = l + len - 1;
            if (r >= n)
                break;
            int k = 0, tmp = 1;
            while (tmp <= len) {
                k++;
                tmp *= 2;
            }
            int m1 = (l + r) / 2, m2 = m1 + 1;
            if (len % 2)
                m1--;
            if (cmpSubStr(l, r, pfl)) {
                cout << l << ' ' << r << endl;
                if (f[l][m1] && f[m2][r]) {
                    f[l][r] = 1;
                    ans[k]++;
                } else
                    ans[1]++;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << endl;

    return 0;
}
