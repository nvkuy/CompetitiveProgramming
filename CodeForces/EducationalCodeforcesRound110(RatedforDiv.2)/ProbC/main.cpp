#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    /*
    freopen("test.out", "w", stdout);
    cout << "1\n";
    for (int i = 0; i < 2e5; i++)
        cout << '?';
    */
    //freopen("test.out", "r", stdin);
    int t;
    string s;
    cin >> t;
    cin.ignore();
    while (t--) {
        getline(cin, s);
        vector<bool> dd(s.length());
        for (int i = 0; i < s.length(); i++)
            dd[i] = (s[i] == '?');
        long long ans = 1, j = 0;
        for (long long i = 1; i < s.length(); i++) {
            if (s[i - 1] != '?' && s[i] == '?') {
                if (s[i - 1] == '1')
                    s[i] = '0';
                else
                    s[i] = '1';
            }
            if (s[i - 1] == '?') {
                if (s[i] == '1')
                    s[i - 1] = '0';
                else
                    s[i - 1] = '1';
            }
            if (s[i] == s[i - 1]) {
                j = i;
                while (j > 0 && dd[j - 1])
                    j--;
            }
            ans += (i - j + 1);
        }
        cout << ans << endl;
    }

    return 0;
}
