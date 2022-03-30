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
        vector<int> pzr;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0')
                pzr.push_back(i);
        }
        for (int i = 1; i < pzr.size(); i++)
            ans += max(0, 3 - pzr[i] + pzr[i - 1]);
        cout << ans << endl;
    }

    return 0;
}
