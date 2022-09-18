#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, q, j, xi;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    while (q--) {
        cin >> xi;
        j = lower_bound(a.begin(), a.end(), xi) - a.begin();
        cout << n - j << endl;
    }

    return 0;
}
