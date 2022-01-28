#include <bits/stdc++.h>

using namespace std;

const int mn = 1e6 + 7;
bool snt[mn];

int main()
{

    memset(snt, true, sizeof(snt));
    snt[0] = false;
    snt[1] = false;
    for(int i = 2; i * i < mn; ++i) {
         if(snt[i] == true) {
             for(int j = i * i; j < mn; j += i)
                 snt[j] = false;
        }
    }
    int t, n, e;
    cin >> t;
    while (t--) {
        cin >> n >> e;
        vector<int> a(n + 1), co(n + 1, 0), cpo(n + 1, 0);
        vector<bool> ia(n + 1, false);
        vector<long long> f(n + 1);
        a[0] = 0, f[0] = 0LL;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1];
            if (a[i] == 1) {
                co[i]++;
                if (i - e > 0) {
                    if (a[i - e] == 1) {
                        co[i] += co[i - e];
                        if (ia[i - e]) {
                            f[i]++;
                            cpo[i] = cpo[i - e];
                            f[i] += cpo[i];
                        }
                    }
                    if (snt[a[i - e]]) {
                        ia[i] = true;
                        f[i]++;
                        if (i - 2 * e > 0) {
                            if (a[i - 2 * e] == 1) {
                                cpo[i] = co[i - 2 * e];
                                f[i] += cpo[i];
                            }
                        }
                    }
                }
            }
            if (snt[a[i]]) {
                //f[i]++;
                if (i - e > 0) {
                    if (a[i - e] == 1)
                        f[i] += co[i - e];
                }
            }
        }

        cout << f[n] << endl;
    }

    return 0;
}
