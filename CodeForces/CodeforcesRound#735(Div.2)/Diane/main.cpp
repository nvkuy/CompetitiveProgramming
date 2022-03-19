#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        string ans;
        int tmp, s1, s2;
        tmp = n / 2;
        tmp = max(tmp - (tmp % 2 == 0), 0);
        s1 = tmp, s2 = max(tmp - 1, 0);
        for (int i = 0; i < s1; i++)
            ans.push_back('a');
        for (char c = 'b'; c <= 'z'; c++) {
            if (c - 'b' >= (n - s1 - s2))
                break;
            ans.push_back(c);
        }
        for (int i = 0; i < s2; i++)
            ans.push_back('a');
        cout << ans << endl;
    }

    return 0;
}
