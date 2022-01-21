#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t, n;
    long long k, s;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<long long> a(n);
        s = 0LL;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
        }
        if (s <= k) {
            cout << "0\n";
            continue;
        }
        sort(a.begin(), a.end());
        long long st = 0;
        long long lm = 0, rm = a[0], mm;
        while (lm < rm) {
            if (rm - lm == 1) {
                if ((rm * n) <= k)
                    lm = rm;
                break;
            }
            mm = (lm + rm) / 2;
            if ((mm * n) <= k)
                lm = mm;
            else
                rm = mm - 1;
        }
        st += (a[0] - lm);
        s -= st;
        for (int i = a.size() - 1; i > 0; i--) {
            if (s <= k)
                break;
            s -= (a[i] - lm);
            st++;
        }
        cout << st << endl;
    }

    return 0;
}
