#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, dd[102], a[102], cpdd[102];
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        memset(dd, 0, sizeof(dd));
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            dd[a[i]]++;
        }
        int mt = 0, ct;
        for (int i = 2; i <= (n * 2); i++) {
            //cout << mt << endl;
            memset(cpdd, 0, sizeof(cpdd));
            for (int j = 0; j <= n; j++)
                cpdd[j] = dd[j];
            ct = 0;
            for (int j = 0; j < n; j++) {
                if ((i - a[j] <= 0) || (i - a[j] > n) || (cpdd[a[j]] <= 0))
                    continue;
                if ((a[j] == i - a[j]) && (cpdd[a[j]] < 2))
                    continue;
                if (cpdd[i - a[j]] > 0) {
                    ct++;
                    cpdd[a[j]]--;
                    cpdd[i - a[j]]--;
                }
            }
            if (ct > mt)
                mt = ct;
        }
        cout << mt << '\n';
    }

    return 0;
}
