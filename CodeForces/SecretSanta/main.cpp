#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, co, ai;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<bool> dd(n + 1, false);
        vector<int> ans(n + 1, 0), a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (!dd[a[i]])
                ans[i] = a[i];
            dd[a[i]] = true;
        }
        deque<int> rm;
        for (int i = 1; i <= n; i++) {
            if (!dd[i])
                rm.push_front(i);
        }
        co = n - rm.size();
        for (int i = 1; i <= n; i++) {
            if (ans[i] != 0)
                continue;
            if (rm.front() == i) {
                int tmp = rm.front();
                rm.pop_front();
                if (rm.size() > 0) {
                    ans[i] = rm.front();
                    rm.pop_front();
                    rm.push_front(i);
                } else {
                    ans[tmp] = a[tmp];
                    for (int j = 1; j <= n; j++) {
                        if (j == tmp)
                            continue;
                        if (ans[j] == ans[tmp]) {
                            ans[j] = tmp;
                            break;
                        }
                    }
                }
            } else {
                ans[i] = rm.front();
                rm.pop_front();
            }
        }
        cout << co << endl;
        for (int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}
