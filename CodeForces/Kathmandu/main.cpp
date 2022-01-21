#include <bits/stdc++.h>

using namespace std;

int t, d, m, t1, t2;
bool fl;

int main()
{
    cin >> t >> d >> m;
    fl = false;
    t1 = 0;
    for (int i = 0; i < m; i++) {
        cin >> t2;
        if (t2 - t1 >= t)
            fl = true;
        t1 = t2;
    }
    if (d - t1 >= t)
        fl = true;

    cout << (fl ? "Y" : "N");

    return 0;
}
