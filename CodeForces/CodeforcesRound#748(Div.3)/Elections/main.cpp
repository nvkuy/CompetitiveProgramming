#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, a[3], mi, cm, ans[3];
    cin >> t;
    while (t--) {
        memset(ans, -1, sizeof(ans));
        cin >> a[0] >> a[1] >> a[2];
        mi = 0, cm = 0;
        for (int i = 0; i < 3; i++) {
            if (a[i] >= a[mi]) {
                if (a[i] > a[mi]) {
                    mi = i;
                    cm = 1;
                } else
                    cm++;
            }
        }
        if (cm <= 1)
            ans[mi] = 0;
        for (int i = 0; i < 3; i++) {
            if (ans[i] != -1)
                cout << ans[i] << ' ';
            else
                cout << a[mi] - a[i] + 1 << ' ';
        }
        cout << endl;
    }

    return 0;
}
