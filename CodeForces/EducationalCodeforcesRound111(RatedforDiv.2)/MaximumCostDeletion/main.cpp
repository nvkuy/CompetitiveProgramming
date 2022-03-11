#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    long long n, a, b, ans, co;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> a >> b;
        cin.ignore();
        getline(cin, s);
        ans = 0LL;
        if (b < 0) {
            co = 1;
            for (int i = 1; i < n; i++) {
                if (s[i] != s[i - 1])
                    co++;
            }
            ans += ((co / 2 + 1) * b);
            ans += (n * a);
        } else
            ans = ((a + b) * n);
        cout << ans << endl;
    }

    return 0;
}
