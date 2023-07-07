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
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(k), b(k);
        string ans = "abc";
        int char_num1 = 0, char_num2 = 3, cur = 3;
        for (int i = 0; i < k; i++) cin >> a[i];
        for (int i = 0; i < k; i++) cin >> b[i];
        bool iok = true;
        for (int i = 0; i < k; i++) {
            int len_dif = a[i] - ans.length(), pld_dif = b[i] - cur;
            if (pld_dif < 0 || pld_dif > len_dif) {
                iok = false;
                break;
            }
            while (pld_dif--) {
                ans.push_back((char)(char_num2 + 'a'));
                len_dif--;
            }
            char_num2++;
            while (len_dif--) {
                ans.push_back((char_num1 % char_num2) + 'a');
                char_num1++;
            }
            cur = b[i];
        }
        if (!iok) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        cout << ans << endl;
    }

    return 0;
}
