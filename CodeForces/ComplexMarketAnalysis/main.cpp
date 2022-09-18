#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

const int mn = 1e6 + 7;
bool snt[mn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

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
        vector<int> a(n);
        long long ans = 0LL, cl, cr;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++) {
            if (!snt[a[i]])
                continue;
            int j;
            cl = 0, cr = 0;
            j = i - e;
            while (j >= 0) {
                if (a[j] != 1)
                    break;
                cl++;
                j -= e;
            }
            j = i + e;
            while (j < n) {
                if (a[j] != 1)
                    break;
                cr++;
                j += e;
            }
            ans += (cr + cl + cr * cl);
        }
        cout << ans << endl;
    }

    return 0;
}
