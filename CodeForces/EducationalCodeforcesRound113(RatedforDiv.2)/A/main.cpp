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
        int a1 = -2, a2 = -2;
        for (int l = 0; l < n; l++) {
            if (a1 >= 0)
                break;
            for (int r = l + 1; r < n; r++) {
                int cs = 0;
                for (int i = l; i <= r; i++) {
                    if (s[i] == 'a')
                        cs++;
                    else
                        cs--;
                }
                if (cs == 0) {
                    a1 = l, a2 = r;
                    break;
                }
            }
        }
        cout << a1 + 1 << ' ' << a2 + 1 << endl;
    }

    return 0;
}
