#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, a, b;
    long long ans;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        //cout << (long long)((a + b) / 4) << '\n';
        ans = (long long)((a + b) / 4);
        if (ans > min(a, b))
            cout << min(a, b) << '\n';
        else
            cout << ans << '\n';
    }

    return 0;
}
