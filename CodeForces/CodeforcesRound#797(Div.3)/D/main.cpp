#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, k;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cin.ignore();
        getline(cin, s);
        int wc = 0, ans = n;
        for (int i = 0; i < k; i++) {
            if (s[i] == 'W')
                wc++;
        }
        ans = wc;
        int j = 0;
        for (int i = k; i < n; i++) {
            if (s[j] == 'W')
                wc--;
            if (s[i] == 'W')
                wc++;
            j++;
            ans = min(ans, wc);
        }
        cout << ans << endl;
    }

    return 0;
}
