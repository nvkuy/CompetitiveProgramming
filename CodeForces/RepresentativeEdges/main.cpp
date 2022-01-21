#include <bits/stdc++.h>

using namespace std;

int n, a[100];

int cal(int d, int s) {
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != s)
            c++;
        s += d;
    }
    return c;
}

int main()
{
    int t, mo, d;
    cin >> t;
    while (t--) {
        cin >> n;
        mo = n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++) {
            for (int j = -101; j <= 101; j++)
                mo = min(mo, cal(j, a[i] - (j * i)));
        }
        cout << mo << endl;
    }

    return 0;
}
