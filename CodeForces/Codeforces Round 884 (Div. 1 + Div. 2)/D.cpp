#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<vector<int>> c;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    c.resize(1e6 + 1);
    for (int i = 1; i <= 1e6; i++)
        for (int j = 1; j * i <= 1e6; j++)
            c[i * j].push_back(i);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ans(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            vector<int> avai(26, 1);
            for (int divs : c[n]) {
                int pre = i - divs;
                if (pre > 0) 
                    avai[ans[pre]] = 0;
            }
            for (int j = 0; j < 26; j++) {
                if (avai[j]) {
                    ans[i] = j;
                    break;
                }
            }
            cout << char(ans[i] + 'a');
        }
        cout << endl;
    }

    return 0;
}
