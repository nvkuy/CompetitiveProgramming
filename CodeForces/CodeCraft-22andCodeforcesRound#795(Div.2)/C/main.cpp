#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, k;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cin.ignore();
        getline(cin, s);
        int ans = 0, l = 0, r = 0;
        for (int i = 1; i < n; i++)
            ans += ((s[i - 1] - '0') * 10 + (s[i] - '0'));
        for (int i = 0; i < n; i++) {
            if (s[i] != '1')
                l++;
            else
                break;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != '1')
                r++;
            else
                break;
        }
        //cout << ans << '|' << l << '|' << r << endl;
        bool onlyOne = (l + r + 1 == n), useOne = (r == 0);
        if (k >= r && r < n && r > 0) {
            k -= r;
            ans -= 10;
            if (r == n - 1)
                ans++;
            useOne = true;
        }
        if (k >= l && l < n && (onlyOne == false || useOne == false) && l > 0) {
            k -= l;
            ans -= 1;
        }
        cout << ans << endl;
    }

    return 0;
}
