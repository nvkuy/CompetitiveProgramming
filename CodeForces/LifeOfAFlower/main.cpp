#include <bits/stdc++.h>

using namespace std;

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cin >> t;
    int t, n, ans, ai;
    bool pw, nw, id;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        ans = 1;
        pw = false, nw = false, id = false;
        for (int i = 0; i < n; i++) {
            scanf("%d", &ai);
            //cout << ai << " " << ans << endl;
            if (ai == 0) {
                if (nw) {
                    id = true;
                    //break;
                }
                nw = true;
                pw = false;
            } else {
                ans++;
                if (pw)
                    ans += 4;
                pw = true;
                nw = false;
            }
            //cout << nw << " " << pw << endl;
            //cout << ans << endl;
        }
        //cout << ans << endl;
        if (!id)
            printf("%d\n", ans);
        else
            printf("-1\n");
    }

    return 0;
}
