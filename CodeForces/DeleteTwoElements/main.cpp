#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, a[200002];
    long long k, ans;
    map<int, int> m;
    map<int, int>::iterator itr1, itr2;
    scanf("%d", &t);
    while (t--) {
        ans = 0; k = 0;
        m.clear();
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            k += a[i];
        }
        if ((k * 2) % n > 0) {
            printf("0\n");
            continue;
        }
        k = (k * 2) / n;
        for (int i = 0; i < n; i++) {
            itr1 = m.find(k - a[i]);
            if (itr1 != m.end()) {
                ans += (*itr1).second;
            }
            itr2 = m.find(a[i]);
            if (itr2 == m.end())
                m.insert(pair<int, int>(a[i], 1));
            else
                (*itr2).second++;
        }
        printf("%lld\n", ans);
    }

    return 0;
}
