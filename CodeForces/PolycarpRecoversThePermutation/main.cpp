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
        if (a[0] != n && a[n - 1] != n)
            printf("-1\n");
        else {
            for (int i = n - 1; i >= 0; i--)
                printf("%d ", a[i]);
            printf("\n");
        }
    }

    return 0;
}
