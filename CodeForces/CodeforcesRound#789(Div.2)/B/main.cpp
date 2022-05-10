#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, ans;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        getline(cin, s);
        ans = 0;
        vector<vector<int>> f(s.length(), vector<int>(2));
        for (int i = 0; i < s.length(); i += 2) {
            if (s[i] != s[i + 1]) {
                ans++;
                if (i > 0) {
                    f[i][0] = min(f[i - 2][0], f[i - 2][1] + 1);
                    f[i][1] = min(f[i - 2][1], f[i - 2][0] + 1);
                } else
                    f[i][0] = f[i][1] = 1;
            } else {
                int avai = s[i] - '0';
                if (i > 0) {
                    f[i][avai] = min(f[i - 2][avai], f[i - 2][1 - avai] + 1);
                    f[i][1 - avai] = 1e9;
                } else {
                    f[i][avai] = 1;
                    f[i][1 - avai] = 1e9;
                }
            }
            //cout << i << ':' << f[i][0] << ' ' << f[i][1] << endl;
        }
        cout << ans << ' ' << min(f[s.length() - 2][0], f[s.length() - 2][1]) << endl;
    }

    return 0;
}
