#include <bits/stdc++.h>

using namespace std;

int t, n, tmp, a[20001];
long long h[20001];

int main()
{

    cin >> t;

    while (t > 0) {
        t--;

        cin >> n;

        for (int i = 1; i <= n; i++)
            cin >> a[i];

        sort(a + 1, a + 1 + n);
        //for (int i = 1; i <= n; i++)
        //    cout << a[i] << " ";
        //cout << endl;

        h[0] = 0;
        for (int i = 1; i <= n; i++)
            h[i] = h[i - 1] + a[i];

        tmp = 0;
        for (int i = n; i > 1; i--)
            tmp += h[i];

        cout << tmp;

    }

    return 0;
}
