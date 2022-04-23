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
        if (k % 2) {
            for (int i = 0; i < n; i++)
                s[i] = (1 - (s[i] - '0')) + '0';
        }
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            if (i + 1 == n) {
                if (k % 2)
                    s[i] = (1 - (s[i] - '0')) + '0';
                ans[i] = k;
                continue;
            }
            if (s[i] == '1' || k <= 0)
                continue;
            ans[i]++;
            k--;
            s[i] = (1 - (s[i] - '0')) + '0';
        }
        cout << s << endl;
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}
