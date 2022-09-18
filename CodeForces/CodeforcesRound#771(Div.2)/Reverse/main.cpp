#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int i = 0, j = 0;
        for (i = 0; i < n; i++)
            if (a[i] != i + 1)
                break;
        for (j = i; j < n; j++)
            if (a[j] == i + 1)
                break;
        reverse(a.begin() + i, a.begin() + max(i, j) + 1);
        for (int i = 0; i < n; i++)
            cout << a[i] << ' ';
        cout << endl;
    }

    return 0;
}
