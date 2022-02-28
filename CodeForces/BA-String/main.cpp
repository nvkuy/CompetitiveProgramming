#include <bits/stdc++.h>

using namespace std;

long long k, a[2002], ans[2002], an;

void cal(long long x) {

}

int main()
{
    int t, n;
    long long x;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> k >> x;
        cin.ignore();
        getline(cin, s);
        an = -1;
        memset(a, 0, sizeof(a));
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < n; i++) {
            if (s[i] != '*')
                continue;
            if (i == 0) {
                an++;
                a[an]++;
            } else {
                if (s[i - 1] != '*')
                    an++;
                a[an]++;
            }
        }
        for (int i = 0; i <= an; i++)
            a[i] = (a[i] * k) + 1LL;
        cal(x);
        int i = 0, j = 0;
        while (i < n) {
            if (s[i] != '*') {
                cout << s[i];
                i++;
                continue;
            }
            while (s[i] == '*') {
                i++;
                if (i == n)
                    break;
            }
            while (ans[j] > 1) {
                cout << 'b';
                ans[j]--;
            }
            j++;
        }
        cout << endl;
    }

    return 0;
}
