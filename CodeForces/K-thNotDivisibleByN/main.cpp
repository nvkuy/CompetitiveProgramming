#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    long long k, ans, n;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        ans = ((k / (n - 1)) * n);
        if (k % (n - 1) == 0)
            cout << ans - 1;
        else
            cout << ans + (k % (n - 1));
        cout << '\n';
    }

    return 0;
}
