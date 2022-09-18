#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, a[51];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        if (i < (n / 2))
            ans += a[i];
        else
            ans -= a[i];
    }
    cout << abs(ans);

    return 0;
}
