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
        int ans = 1;
        set<char> dd;
        for (int i = 0; i < s.length(); i++) {
            if (dd.size() < 3 || dd.find(s[i]) != dd.end()) {
                dd.insert(s[i]);
                continue;
            }
            ans++;
            dd.clear();
            dd.insert(s[i]);
        }
        cout << ans << endl;
    }

    return 0;
}
