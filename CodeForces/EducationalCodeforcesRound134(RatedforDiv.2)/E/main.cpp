#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int bf(int l, int r, string &s) {
    int k = 0;
    for (k = 0; k < r - l + 1; k++) {

    }
    return k;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    string s, t, tmp;
    getline(cin, s);
    vector<int> f(11);
    for (int i = 0; i < 11; i++)
        f[i] = bf(i, s.length() - 1, s);
    cin >> q;
    cin.ignore();
    while (q--) {
        getline(cin, t);
        if (s.length() <= 30) {
            tmp = s + t;
            for (int i = s.length(); i < tmp.length(); i++)
                cout << bf(0, i, tmp) << ' ';
            cout << endl;
        } else {
            tmp.clear();
            for (int i = 0; i < t.length(); i++) {
                tmp.push_back(t[i]);
                int ans = 0, j;
                for (j = 0; j < tmp.length(); j++) {
                    if (s[j] == tmp[j])
                        ans++;
                    else
                        break;
                }
                if (ans == tmp.length())
                    ans += f[j];
                cout << ans << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}
