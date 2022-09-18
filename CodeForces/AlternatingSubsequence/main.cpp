#include <bits/stdc++.h>

using namespace std;

long long a[200002];
long long cal(int n, int j) {
    long long cm = a[j];
    long long ans = 0;
    for (int i = j; i < n; i++) {
        if ((a[i] > 0 && cm > 0) || (a[i] < 0 && cm < 0)) {
            cm = max(cm, a[i]);
        } else {
            ans += cm;
            //cout << cm << "|" << ans << " ";
            cm = a[i];
        }
        if (i == (n - 1))
            ans += cm;
    }
    //cout << endl;
    return ans;
}

int main()
{
    int t, n, j;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%lld", &a[i]);
        printf("%lld\n", cal(n, 0));
        /*
        if ((a[0] < 0 && a[n - 1] > 0) || (a[0] > 0 && a[n - 1] < 0)) {
            j = 0;
            while ((a[j] > 0 && a[0] > 0) || (a[j] < 0 && a[0] < 0))
                j++;
            printf("%lld\n", max(cal(n, j), cal(n, 0)));
        } else
            printf("%lld\n", cal(n, 0));
        */
    }
    return 0;
}
