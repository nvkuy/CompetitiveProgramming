#include <bits/stdc++.h>

using namespace std;

int b[200002], dis[200002], per[200002];

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        memset(dis, -1, (n + 1) * sizeof *dis);
        int root = 1;
        for (int i = 1; i <= n; i++)
            scanf("%d", &b[i]);
        while (b[root] != root)
            root = b[root];
        for (int i = 1; i <= n; i++)
            scanf("%d", &per[i]);
        bool iok = (per[1] == root);
        dis[per[1]] = 0;
        for (int i = 2; i <= n; i++) {
            dis[per[i]] = dis[per[i - 1]] + 1;
            if (dis[per[i]] <= dis[b[per[i]]] || dis[b[per[i]]] == -1)
                iok = false;
        }
        if (!iok) {
            printf("-1\n");
            continue;
        }
        for (int i = 1; i <= n; i++)
            printf("%d ", dis[i] - dis[b[i]]);
        printf("\n");
    }

    return 0;
}
