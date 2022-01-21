#include <bits/stdc++.h>

using namespace std;

bool dd[100001][101];
int xs[101];

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> ans;
    for (int i = 1; i <= n; i++)
        scanf("%d", &xs[i]);
    memset(dd, false, (1e5 + 1) * sizeof *dd[0]);
    dd[0][0] = true;
    for (int i = 0; i <= 1e5; i++) {
        for (int j = 1; j <= n; j++) {
            dd[i][j] = dd[i][j - 1];
            if (i >= xs[j])
                dd[i][j] |= dd[i - xs[j]][j - 1];
        }
    }
    for (int i = 1; i <= 1e5; i++) {
        if (dd[i][n])
            ans.push_back(i);
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);

    return 0;
}
