#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, m;
    string s, ans;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        cin.ignore();
        getline(cin, s);
        while (m--) {
            ans = s;
            for (int i = 0; i < n; i++) {
                if (s[i] == '0') {
                    bool iok = false;
                    if (i > 0 && s[i - 1] == '1')
                        iok = !iok;
                    if (i < n - 1 && s[i + 1] == '1')
                        iok = !iok;
                    if (iok)
                        ans[i] = '1';
                }
            }
            if (ans == s)
                break;
            s = ans;
        }
        cout << ans << endl;
    }


    return 0;
}
