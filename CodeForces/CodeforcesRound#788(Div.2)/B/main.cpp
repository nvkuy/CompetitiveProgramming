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
        cin >> n;
        cin.ignore();
        getline(cin, s);
        cin >> k;
        char c;
        vector<int> dd(33, 0), pos;
        for (int i = 0; i < k; i++) {
            cin >> c;
            dd[c - 'a'] = 1;
        }
        for (int i = 0; i < n; i++) {
            if (dd[s[i] - 'a'] == 1)
                pos.push_back(i);
        }
        if (pos.size() == 0) {
            cout << "0" << endl;
            continue;
        }
        int ans = pos[0];
        for (int i = 1; i < pos.size(); i++)
            ans = max(ans, pos[i] - pos[i - 1]);
        cout << ans << endl;

    }

    return 0;
}
