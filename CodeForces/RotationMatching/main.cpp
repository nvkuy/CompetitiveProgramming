#include <bits/stdc++.h>

using namespace std;

int dd[200002], l[400004];

int main()
{
    int n, t;
    memset(dd, 0, sizeof(dd));
    memset(l, 0, sizeof(l));
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        dd[t] = i;
    }
    int ml = 0, j;
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        j = dd[t] - i;
        if (j < 0)
            j += n;
        l[j]++;
        ml = max(ml, l[j]);
    }
    printf("%d", ml);

    return 0;
}
