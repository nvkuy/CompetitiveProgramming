#include <bits/stdc++.h>

using namespace std;

int a[200002];
bool check(int i, int j, int x) {
    if (i > j)
        return true;
    if (a[i] == a[j])
        return (true & check(i + 1, j - 1, x));
    else {
        if (x != -1) {
            if ((x != a[i]) && (x != a[j]))
                return false;
            bool iok = false;
            if (x == a[i])
                iok |= check(i + 1, j, x);
            if (x == a[j])
                iok |= check(i, j - 1, x);
            return iok;
            //return ((x == a[i] & check(i + 1, j, x)) | (x == a[j] & check(i, j - 1, x)));
        } else
            return ((check(i + 1, j, a[i])) | (check(i, j - 1, a[j])));
    }
}

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (check(0, n - 1, -1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
