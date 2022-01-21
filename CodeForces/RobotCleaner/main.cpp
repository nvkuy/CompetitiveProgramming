#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, m, rb, rd, cb, cd, drh, drv, ti;
    cin >> t;
    while (t--) {
        cin >> n >> m >> rb >> cb >> rd >> cd;
        drh = 1, drv = 1, ti = 0;
        if (cb == cd || rb == rd)
            cout << "0\n";
        else {
            while (cb != cd && rd != rb) {
                if (cb + drh > m || cb + drh < 1)
                    drh = -drh;
                if (rb + drv > n || rb + drv < 1)
                    drv = -drv;
                cb += drh;
                rb += drv;
                ti++;
            }
            cout << ti << '\n';
        }
        /*
        else if (cb < cd) {
            if (rd > rb)
                cout << min((cd - cb), (rd - rb)) << '\n';
            else
                cout << (cd - cb) << '\n';
        } else {
            if (n - rb < m - cb) {
                if ()
                cout << (n - rb + n - rd) << '\n';
            } else {
                if ()
                cout << (m - cb + n - (rb + m - cb) + n - rd) << '\n';
            }
        }
        */
    }

    return 0;
}
