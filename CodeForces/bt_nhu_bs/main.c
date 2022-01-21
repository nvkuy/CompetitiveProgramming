#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, a[100000], j = 0, b;
    scanf("%d %d", &n, &b);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    while (a[j] >= b)
        j++;
    for (int i = n - 1; i >= j; i--)
        a[i + 1] = a[i];
    a[j] = b;
    for (int i = 0; i <= n; i++)
        printf("%d ", a[i]);

    return 0;
}
