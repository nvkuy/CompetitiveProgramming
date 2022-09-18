#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, a[10];
    cin >> t;
    while (t--) {
        for (int i = 0; i < 7; i++)
            cin >> a[i];
        sort(a, a + 7);
        cout << a[0] << ' ' << a[1] << ' ';
        if (a[0] + a[1] == a[2])
            cout << a[3] << endl;
        else
            cout << a[2] << endl;
    }

    return 0;
}
