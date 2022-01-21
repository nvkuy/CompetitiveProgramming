#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n, a[200002], bi;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) {
        scanf("%d", &bi);
        a[i] -= bi;
    }
    sort(a, a + n, greater<int>());
    //for (int i = 0; i < n; i++)
    //    cout << a[i] << " ";
    //cout << endl;
    long long ans = 0;
    int j = 0, l, r, m;
    for (int i = 1; i < n; i++) {
        if (a[i] + a[j] > 0) {
            while ((a[i] + a[j] > 0) && (i > j))
                j++;
            if ((a[i] + a[j] <= 0) || (j >= i))
                j--;
        } else {
            if (a[i] + a[0] <= 0)
                break;
            else {
                l = 0;
                r = j;
                while (r - l > 1) {
                    m = (l + r) / 2;
                    if (a[m] + a[i] <= 0)
                        r = m - 1;
                    else
                        l = m;
                    //cout << m << " ";
                }
                //cout << endl;
                j = l;
                if ((a[r] + a[i] > 0) && (r < i))
                    j = r;
            }
        }
        ans += (j + 1);
        //cout << ans << " " << j << endl;
    }
    printf("%lld", ans);

    return 0;
}
