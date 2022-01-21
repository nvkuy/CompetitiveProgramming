#include <bits/stdc++.h>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        if (n < k) {
            cout << "NO\n";
        } else {
            if (n % 2) {
                if (k % 2) {
                    cout << "YES\n";
                    for (int i = 1; i < k; i++)
                        cout << "1 ";
                    cout << (n - k + 1) << '\n';
                } else {
                    cout << "NO\n";
                }
            } else {
                if (k % 2) {
                    if ((k * 2) > n) {
                        cout << "NO\n";
                    } else {
                        cout << "YES\n";
                        for (int i = 1; i < k; i++)
                            cout << "2 ";
                        cout << (n - (2 * (k - 1))) << '\n';
                    }
                } else {
                    cout << "YES\n";
                    for (int i = 1; i < k; i++)
                        cout << "1 ";
                    cout << (n - k + 1) << '\n';
                }
            }
        }
    }

    return 0;
}
