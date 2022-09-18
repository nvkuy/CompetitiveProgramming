#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q, n;
    string s, t;
    cin >> q;
    while (q--) {
        cin >> n;
        cin.ignore();
        getline(cin, s);
        getline(cin, t);
        vector<int> p1, p2;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1])
                p1.push_back(i);
            if (t[i] != t[i - 1])
                p2.push_back(i);
        }
        if (s[0] != t[0] || s[n - 1] != t[n - 1] || p1.size() != p2.size()) {
            cout << -1 << endl;
            continue;
        }
        long long ans = 0;
        for (int i = 0; i < p1.size(); i++)
            ans += abs(p1[i] - p2[i]);
        cout << ans << endl;
    }

    return 0;
}
