#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    long long s, a[100001];
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] >= s) {
            cout << 1;
            return 0;
        }
    }
    long long cs = 0;
    int j = 1, ans = 1e9 + 7;
    for (int i = 1; i <= n; i++) {
        cs += a[i];
        if (cs < s)
            continue;
        while (cs >= s) {
            cs -= a[j];
            j++;
            if (cs < s) {
                j--;
                cs += a[j];
                break;
            }
        }
        ans = min(ans, i - j + 1);
        //cout << j << " " << i << " " << ans << endl;
    }
    if (ans > n)
        cout << -1;
    else
        cout << ans;

    return 0;
}
