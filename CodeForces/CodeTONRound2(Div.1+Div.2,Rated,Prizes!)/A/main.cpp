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

    int t, n, m;
    string s1, s2;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cin.ignore();
        getline(cin, s1);
        getline(cin, s2);
        int iok = 0;
        int j = n - 1;
        for (int i = m - 1; i > 0; i--) {
            iok += (s1[j] == s2[i]);
            j--;
        }
        while (j >= 0) {
            if (s1[j] == s2[0]) {
                iok++;
                break;
            }
            j--;
        }
        cout << (iok >= m ? "YES" : "NO") << endl;
    }

    return 0;
}
