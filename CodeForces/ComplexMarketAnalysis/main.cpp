#include <bits/stdc++.h>

using namespace std;

long long f[200002][2];
bool snt[1000001];
int a[200002];

int main()
{

    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    memset(snt, true, sizeof(snt));
    snt[0] = false;
    snt[1] = false;
    for(int i = 2; i * i <= 1000001; ++i) {
         if(snt[i] == true) {
             for(int j = i * i; j <= 1000001; j += i)
                 snt[j] = false;
        }
    }
    long long ans;
    int t, n, e;
    cin >> t;
    while (t--) {
        //memset(f[0], 0, sizeof(f[0]));
        //memset(f[1], 0, sizeof(f[1]));
        ans = 0;
        cin >> n >> e;
        for (int i = 0; i < n; i++) {
            //cout << ans << "|" << i << endl;
            cin >> a[i];
            f[i][0] = 0, f[i][1] = 0;
            //if ((a[i] == 1) && (i - e < 0))
            //    f[i][0] = 1;
            //if ((snt[a[i]]) && (i - e < 0))
            //    f[i][1] = 1;
            if (((!snt[a[i]]) && (a[i] > 1)) || (i - e < 0))
                continue;
            if (a[i] == 1) {
                if (a[i - e] == 1) {
                    f[i][0] = f[i - e][0] * 2 + (f[i - e][0] <= 0);
                    f[i][1] = f[i - e][1] * 2;
                    if (f[i - e][1] > 0 && f[i][0] > 0) {
                        f[i][1] = max(f[i][1] - f[i][0], 0LL);
                        ans += max(f[i - e][1] + 1 - f[i][0], 0LL);
                    }
                    ans += (f[i - e][1] + 1 - (f[i - e][1] <= 0));
                    //cout << ans << "|" << i << endl;
                    continue;
                }
                //if (!snt[a[i - e]])
                //    f[i][0] = 1;
                if (snt[a[i - e]]) {
                    f[i][1] = f[i - e][1] * 2 + (f[i - e][1] <= 0);
                    //f[i][0] = 0;
                    ans += (f[i - e][1] + 1);
                    //cout << ans << "|" << i << endl;
                }
            } else {
                if (a[i - e] == 1) {
                    f[i][1] = f[i - e][0] * 2 + (f[i - e][0] <= 0);
                    ans += (f[i - e][0] + 1);
                    //cout << ans << "|" << i << endl;
                    continue;
                }
                //f[i][1] = 1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
