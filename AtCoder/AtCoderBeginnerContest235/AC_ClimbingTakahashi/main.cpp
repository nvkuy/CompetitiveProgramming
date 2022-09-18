#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, hi, fh = 0;
    cin >> n;
    bool id = false;
    for (int i = 0; i < n; i++) {
        cin >> hi;
        if (id)
            continue;
        if (hi > fh)
            fh = hi;
        else
            id = true;
    }
    cout << fh;

    return 0;
}
