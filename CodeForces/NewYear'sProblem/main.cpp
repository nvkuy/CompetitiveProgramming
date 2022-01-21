#include <bits/stdc++.h>

using namespace std;

int n, m, mi[100001];
vector<vector<int>> p(100001);

bool check(int x) {
    int c;
    for (int i = 0; i < m; i++) {
        c = 0;
        for (int j = 0; j < n; j++) {
            if (p[i][j] >= x)
                c++;
            if (c >= 2)
                break;
        }
        if (c >= 2) {
            for (int j = 0; j < n; j++)
                if (mi[j] < x)
                    return false;
            return true;
        }
    }
    return false;
}

int main()
{
    int t, l, r, x, pij;
    scanf("%d", &t);
    while (t--) {
        memset(mi, 0, sizeof(mi));
        scanf("%d %d", &m, &n);
        for (int i = 0; i < m; i++) {
            p[i].clear();
            for (int j = 0; j < n; j++) {
                scanf("%d", &pij);
                p[i].push_back(pij);
                mi[j] = max(mi[j], pij);
            }
        }
        //for (int j = 0; j < m; j++) {
        //    for (int i = 0; i < n; i++)
        //        cout << p[j][i] << " ";
        //    cout << endl;
        //}
        //cout << endl;
        l = 1, r = 1e9, x;
        while (l < r) {
            if (r - l <= 1) {
                if (check(r))
                    l = r;
                break;
            }
            x = (l + r) / 2;
            if (check(x))
                l = x;
            else
                r = x - 1;
        }
        printf("%d\n", l);
    }

    return 0;
}
