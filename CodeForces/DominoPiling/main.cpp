#include <bits/stdc++.h>

using namespace std;

int m, n;

int main()
{

    cin >> m >> n;

    if (m % 2 == 0)
        cout << (m / 2) * n;
    else {
        if (n % 2 == 0)
            cout << (((m - 1) / 2) * n) + (n / 2);
        else
            cout << (((m - 1) / 2) * n) + ((n - 1) / 2);
    }

    return 0;
}
