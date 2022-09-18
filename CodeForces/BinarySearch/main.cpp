#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, x, a[100001];
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (k--) {
        cin >> x;
        int l = 0, r = n - 1, m;
        while (l <= r) {
            if (l == r) {
                if (a[l] == x)
                    cout << "YES\n";
                else
                    cout << "NO\n";
                break;
            } else {
                m  = (l + r) / 2;
                if (a[m] == x) {
                    cout << "YES\n";
                    break;
                } else {
                    if (a[m] < x)
                        l = m + 1;
                    else
                        r = m - 1;
                }
            }

        }
    }

    return 0;
}
