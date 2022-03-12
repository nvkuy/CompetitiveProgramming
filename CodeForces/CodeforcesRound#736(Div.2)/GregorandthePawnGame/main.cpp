#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, n, ans;
    string s1, s2;
    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        getline(cin, s1);
        getline(cin, s2);
        vector<int> dd(n);
        for (int i = 0; i < n; i++)
            dd[i] = s1[i] - '0';
        ans = 0;
        for (int i = 0; i < n; i++) {
            if (s2[i] == '0')
                continue;
            if (i > 0 && dd[i - 1] == 1) {
                dd[i - 1] = -1;
                ans++;
                continue;
            }
            if (dd[i] == 0) {
                dd[i] = -1;
                ans++;
                continue;
            }
            if (i + 1 < n && dd[i + 1] == 1) {
                dd[i + 1] = -1;
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
