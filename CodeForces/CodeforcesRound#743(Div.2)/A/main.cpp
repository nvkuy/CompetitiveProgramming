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
        vector<int> a(n);
        getline(cin, s);
        for (int i = 0; i < n; i++)
            a[i] = s[n - i - 1] - '0';
        int ans = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] > 0)
                ans += (a[i] + 1);
        }
        cout << ans << endl;
    }

    return 0;
}
