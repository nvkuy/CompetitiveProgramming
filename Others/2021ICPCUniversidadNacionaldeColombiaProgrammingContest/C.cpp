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

    freopen("input", "r", stdin);

    string s;
    
    while (cin >> s) {
        long long ans = 0;
        for (int i = 0; i < s.length(); i++) {
            int j = i + 1;
            while (true) {
                if (j == s.length())
                    break;
                while (j < s.length() && s[i] != s[j])
                    j++;
                int tans = 0, k = i;
                while (j < s.length() && s[k] == s[j]) {
                    tans++;
                    ans += tans;
                    j++, k++;
                }
            }
            
        }
        cout << ans << endl;
    }

    return 0;
}