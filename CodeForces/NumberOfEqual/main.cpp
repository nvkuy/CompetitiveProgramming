#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, m, a[100001], b[100001];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    a[n] = 1e9 + 7;
    int i = 0, j = 0;
    long long ans = 0, c1 = 0, c2 = 0;
    while (j < m) {
        while (b[j] > a[i])
            i++;
        if (b[j] == a[i]) {
            c1 = 0, c2 = 0;
            while (b[j] == a[i]) {
                j++;
                c1++;
            }
            while (b[j - 1] == a[i]) {
                i++;
                c2++;
            }
            ans += (long long)(c1 * c2);
            //cout << ans << endl;
            continue;
        }
        j++;
    }
    cout << ans;

    return 0;
}
