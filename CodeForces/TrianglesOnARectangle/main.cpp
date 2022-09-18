#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, k;
    long long w, h, a[200002], mans;
    cin >> t;
    while (t--) {
        mans = -1;
        cin >> w >> h;
        cin >> k;
        for (int i = 0; i < k; i++)
            cin >> a[i];
        mans = max(mans, (a[k - 1] - a[0]) * h);
        cin >> k;
        for (int i = 0; i < k; i++)
            cin >> a[i];
        mans = max(mans, (a[k - 1] - a[0]) * h);
        cin >> k;
        for (int i = 0; i < k; i++)
            cin >> a[i];
        mans = max(mans, (a[k - 1] - a[0]) * w);
        cin >> k;
        for (int i = 0; i < k; i++)
            cin >> a[i];
        mans = max(mans, (a[k - 1] - a[0]) * w);
        cout << mans << endl;
    }

    return 0;
}
