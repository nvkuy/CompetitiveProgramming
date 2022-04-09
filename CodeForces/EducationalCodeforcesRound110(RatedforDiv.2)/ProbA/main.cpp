#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        vector<pair<int, int>> s(4);
        for (int i = 0; i < 4; i++)
            cin >> s[i].first, s[i].second = i + 1;
        sort(s.begin(), s.end());
        if ((s[2].second == 1 && s[3].second == 2) || (s[2].second == 2 && s[3].second == 1) || (s[2].second == 3 && s[3].second == 4) || (s[2].second == 4 && s[3].second == 3))
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}
