#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long hc, dc, hm, dm, k, w, a, bh, bd, t1, t2;
    int t;
    cin >> t;
    while (t--) {
        cin >> hc >> dc >> hm >> dm >> k >> w >> a;
        bool iok = false;
        for (int i = 0; i <= k; i++) {
            if (iok)
                break;
            bh = i * a;
            bd = (k - i) * w;
            t1 = t2 = 1;
            t1 = t2 = 0LL;
            if ((hc + bh) % dm > 0)
                t1++;
            t1 += ((hc + bh) / dm);
            if (hm % (dc + bd) > 0)
                t2++;
            t2 += (hm / (dc + bd));
            if (t1 >= t2)
                iok = true;
        }
        cout << (iok ? "YES" : "NO") << '\n';
    }

    return 0;
}
