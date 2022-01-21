#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << (int)((int)sqrt(n) + (int)cbrt(n) - (int)sqrt((int)cbrt(n))) << endl;
    }

    return 0;
}
