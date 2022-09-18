#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int st = 1;
        if (n % 2) {
            cout << "2 3 1 ";
            st = 4;
        }
        for (int i = st; i <= n; i += 2)
            cout << i + 1 << ' ' << i << ' ';
        cout << endl;
    }

    return 0;
}
