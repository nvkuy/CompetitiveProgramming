#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        vector<string> arr(n);
        for (int i = 0; i < n; i++)
            getline(cin, arr[i]);
        int ans = 0;
        for (char c = 'a'; c <= 'e'; c++) {
            vector<int> dt(n);
            for (int i = 0; i < n; i++) {
                int ec = 0, nec = 0;
                for (int j = 0; j < arr[i].length(); j++) {
                    if (arr[i][j] == c)
                        ec++;
                    else
                        nec++;
                }
                dt[i] = ec - nec;
            }
            sort(dt.begin(), dt.end(), greater<int>());
            int cs = 0, tans = 0;
            for (int i = 0; i < n; i++) {
                if (cs + dt[i] > 0) {
                    tans++;
                    cs += dt[i];
                } else
                    break;
            }
            ans = max(ans, tans);
        }
        cout << ans << endl;
    }

    return 0;
}
