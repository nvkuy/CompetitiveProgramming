#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    string s;
    cin >> t;
    cin.ignore();
    while (t--) {
        getline(cin, s);
        if (s.size() == 2) {
            cout << s[1] << endl;
            continue;
        }
        int ans = 1e9;
        for (int i = 0; i < s.size(); i++)
            ans = min(ans, s[i] - '0');
        cout << ans << endl;
    }

    return 0;
}
