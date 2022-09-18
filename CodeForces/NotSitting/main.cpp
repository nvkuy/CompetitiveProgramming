#include <bits/stdc++.h>

using namespace std;

int dis(int a, int b, int c, int d) {
    return abs(a - c) + abs(b - d);
}

int main()
{
    int t, n, m;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        vector<int> a;
        int cm;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cm = -1;
                cm = max(cm, dis(i, j, 0, 0));
                cm = max(cm, dis(i, j, n - 1, 0));
                cm = max(cm, dis(i, j, 0, m - 1));
                cm = max(cm, dis(i, j, n - 1, m - 1));
                a.push_back(cm);
            }
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < a.size(); i++)
            printf("%d ", a[i]);
        printf("\n");
    }


    return 0;
}
