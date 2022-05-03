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
        bool id = false;
        int ans = 0;
        for (char c1 = 'a'; c1 <= 'z'; c1++) {
            if (id)
                break;
            for (char c2 = 'a'; c2 <= 'z'; c2++) {
                if (c1 == c2)
                    continue;
                ans++;
                if (c1 == s[0] && c2 == s[1]) {
                    id = true;
                    break;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
