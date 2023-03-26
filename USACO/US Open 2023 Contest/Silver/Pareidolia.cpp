#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;
    cin >> s;
    int n = s.length();
    long long ans = 0;
    string pt = "bessie";
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            int j = 0;
            for (int i = l; i <= r; i++) {
                if (s[i] == pt[j]) {
                    j = (j + 1) % pt.length();
                    if (j == 0) ans++;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
