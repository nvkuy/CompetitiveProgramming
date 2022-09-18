#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    long long n, mai, s, ai;
    cout << fixed << setprecision(10);
    cin >> t;
    while (t--) {
        cin >> n;
        mai = -1e9, s = 0LL;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            s += ai;
            mai = max(mai, ai);
        }
        cout << (mai + (1.0 * (s - mai) / (n - 1))) << endl;
    }

    return 0;
}
