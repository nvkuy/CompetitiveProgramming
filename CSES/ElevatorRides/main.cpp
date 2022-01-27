#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x, tmp, c;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    c = 1, tmp = x;
    while (a.size() > 0) {
        int l = 0, r = a.size() - 1, m;
        while (l < r) {
            if (r - l == 1) {
                if (a[r] <= tmp)
                    l = r;
                break;
            }
            m = (l + r) / 2;
            if (a[m] <= tmp)
                l = m;
            else
                r = m - 1;
        }
        if (a[l] > tmp) {
            tmp = x;
            c++;
        } else {
            tmp -= a[l];
            a.erase(a.begin() + l);
        }
    }
    cout << c;

    return 0;
}
