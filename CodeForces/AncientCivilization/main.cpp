#include <bits/stdc++.h>

using namespace std;

int b[33];

void dtb(int n, int &i) {
    if (n > 0) {
        b[i] += (n % 2);
        i--;
        dtb(n / 2, i);
    }
}

int main()
{
    int t, n, l;
    long long xi, ans;
    cin >> t;
    while (t--) {
        cin >> n >> l;
        memset(b, 0, sizeof(b));
        for (int i = 0; i < n; i++) {
            cin >> xi;
            int j = l;
            dtb(xi, j);
        }
        ans = 0LL;
        for (int i = l; i >= 0; i--) {
            if (b[i] > (n - b[i]))
                ans += pow(2, l - i);
        }
        cout << ans << endl;
    }

    return 0;
}
