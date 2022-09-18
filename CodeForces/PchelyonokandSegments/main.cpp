#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

/*
1
55
28 1376227 3548650 119796 75196 514569 732545686 1157778 20 5975 849 7922 3912863 830 113 661847789 38164494 70886500 6121250 238801764 8084592 96658305 443438005 9278750 1549 63359125 217582 19596833 591938232 10172272 733 124825403 27367166 183457700 97601 590 489306293 35869714 1 444758157 250384132 36287375 659021216 27073642 7056573 684028268 313486970 18810 34 22645260 461427682 514548531 484225880 514668863 999959028
*/

long long n, a[100001], f[100001];

bool check(int k) {
    long long i = n, ck = 0, msi, cs, ms, ps = 1e18 + 12, need = 0LL;
    for (int j = 1; j <= k; j++)
        need += j;
    while (true) {
        if (i < need)
            return false;
        ms = -1;
        msi = i;
        ck++;
        need -= ck;
        for (int j = i; j > need; j--) {
            if (j - ck < 0)
                break;
            cs = f[j] - f[j - ck];
            //cout << k << '|' << j - ck << '|' << j << '|' << cs << endl;
            if (cs > ms && cs < ps) {
                ms = cs;
                msi = j;
            }
        }
        if (ms < 0)
            return false;
        ps = ms;
        i = msi - ck;
        //cout << k << '|' << msi - ck << '|' << msi << '|' << ps << endl;
        if (ck >= k)
            break;
    }
    return true;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        f[0] = 0;
        for (int i = 1; i <= n; i++)
            f[i] = f[i - 1] + a[i];
        int l = 1, r = n, m;
        while (l < r) {
            if (r - l == 1) {
                if (check(r))
                    l = r;
                break;
            }
            m = (l + r) / 2;
            if (check(m))
                l = m;
            else
                r = m - 1;
        }
        cout << l << endl;
    }

    return 0;
}
