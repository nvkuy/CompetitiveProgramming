#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        if (n % 2)
            if ((n / 2) % 2)
                cout << (n / 2 + 2) << " " << (n / 2 - 2) << " " << 1 << endl;
            else
                cout << (n / 2 + 1) << " " << (n / 2 - 1) << " " << 1 << endl;
        else
            cout << (n / 2) << " " << (n / 2 - 1) << " " << 1 << endl;
    }

    return 0;
}
