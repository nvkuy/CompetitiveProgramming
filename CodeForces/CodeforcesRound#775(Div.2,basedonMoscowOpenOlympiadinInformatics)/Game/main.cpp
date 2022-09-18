#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, n, c;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        c = 0;
        int i = 0;
        for (i = 0; i < n; i++) {
            if (a[i] == 0)
                break;
            c++;
        }
        if (c == n) {
            cout << "0\n";
            continue;
        }
        for (int j = n - 1; j >= i; j--) {
            if (a[j] == 0)
                break;
            c++;
        }
        cout << n - c + 1 << endl;
    }

    return 0;
}
