#include <bits/stdc++.h>

using namespace std;

int main()
{

    long long t, n, a[1000];
    cin >> t;
    while (t--) {
        //memset(a, 0, sizeof(a));
        cin >> n;
        for (long long i = 1; i <= (n * 3); i++)
            cin >> a[i];
        sort(a + 1, a + (n * 3) + 1);
        /*
        for (int i = 1; i <= (n * 3) - 1; i++)
            for (int j = i + 1; j < (n * 3); j++)
                if (a[i] > a[j])
                    swap(a[i], a[j]);
        */
        long long ans = 0, i = (3 * n), j = 1;
        while (i > j) {
            ans += ((a[i] - a[j]) * a[i - 1]);
            i -= 2;
            j++;
        }
        cout << ans << '\n';
    }

    return 0;
}
