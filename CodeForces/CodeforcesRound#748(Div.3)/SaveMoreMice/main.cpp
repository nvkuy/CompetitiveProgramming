#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, k, cp, ans;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> x(k);
        for (int i = 0; i < k; i++)
            cin >> x[i];
        sort(x.begin(), x.end(), greater<int>());
        cp = 0, ans = 0;
        for (int i = 0; i < k; i++) {
            if (cp >= x[i])
                break;
            ans++;
            cp += (n - x[i]);
        }
        cout << ans << endl;
    }

    return 0;
}
