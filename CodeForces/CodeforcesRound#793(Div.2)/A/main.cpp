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
        int ans = 0, l;
        l = (n / 2) - 1;
        if (n % 2)
            ans++;
        while (l >= 0 && s[l] == s[n / 2]) {
            ans += 2;
            l--;
        }
        cout << ans << endl;
    }

    return 0;
}
