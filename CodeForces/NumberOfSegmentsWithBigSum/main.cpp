#include <bits/stdc++.h>

using namespace std;

int main()
{

    long long n;
    long long s, a[100001];
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    long long cs = 0;
    long long j = 1, ans = 0;
    for (long long i = 1; i <= n; i++) {
        cs += a[i];
        if (a[i] >= s) {
            ans += i;
            continue;
        }
        if (cs < s)
            continue;
        while (cs >= s) {
            cs -= a[j];
            j++;
            if (cs < s) {
                j--;
                cs += a[j];
                break;
            }
        }
        ans += j;
    }
    cout << ans;

    return 0;
}
