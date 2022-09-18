#include <bits/stdc++.h>

using namespace std;

int n, m, a[202], b[202];

bool try_ans(int ans) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int tmp = (a[i] & b[j]);
            if ((j == m - 1) && ((tmp | ans) != ans))
                return false;
            if ((tmp | ans) == ans)
                break;
        }
    }
    return true;
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int ans = 1e9;
    for (int i = 0; i < (1 << 9); i++) {
        if (try_ans(i)) {
            ans = i;
            break;
        }
    }
    cout << ans;

    return 0;
}
