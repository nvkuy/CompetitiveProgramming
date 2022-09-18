#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, l, a[1002];
    double ans = 0.0;
    scanf("%d %d", &n, &l);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    for (int i = 1; i < n; i++)
        ans = max(ans, (double)((a[i] - a[i - 1]) / 2.0));
    ans = max(ans, (double)a[0]);
    ans = max(ans, (double)(l - a[n - 1]));
    printf("%lf", ans);

    return 0;
}
