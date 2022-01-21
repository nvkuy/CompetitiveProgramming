#include <bits/stdc++.h>

using namespace std;

int main()
{

    long long n;
    long long s, a[100001];
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    long long cs = 0, ans = 0;
    long long j = 1;
    for (long long i = 1; i <= n; i++) {
        if (a[i] > s) {
            j = i + 1;
            cs = 0;
            continue;
        }
        cs += a[i];
        if (cs <= s) {
            ans += (i - j + 1);
            continue;
        }
        while (cs > s) {
            cs -= a[j];
            j++;
            if (cs <= s) {
                ans += (i - j + 1);
                break;
            }
        }
    }
    cout << ans;

    return 0;
}
