#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t, n, a[200002];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        sort(a, a + n);
        for (int i = 1; i <= (n / 2 ); i++)
            printf("%d %d\n", a[i], a[0]);
    }

    return 0;
}
