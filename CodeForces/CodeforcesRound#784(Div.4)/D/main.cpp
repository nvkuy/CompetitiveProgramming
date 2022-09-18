#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    string s;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        getline(cin, s);
        n += 2, s = 'W' + s + 'W';
        int l = 0, r, c = 0;
        bool iok = true;
        for (int i = 1; i < n; i++) {
            if (s[i] != 'W') {
                if (s[i] == 'R')
                    c++;
                continue;
            }
            r = i;
            if (r - l == 1) {
                l = r;
                continue;
            }
            if (c == r - l - 1 || c == 0) {
                iok = false;
                break;
            }
            l = r, c = 0;
        }
        cout << (iok ? "YES" : "NO") << endl;
    }

    return 0;
}
