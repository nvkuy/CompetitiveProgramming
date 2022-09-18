#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, ma = -1, ca, st = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ma = max(ma, a[i]);
    }
    ca = a[n - 1];
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > ca) {
            ca = a[i];
            st++;
            if (a[i] == ma)
                break;
        }
    }
    cout << st;

    return 0;
}
