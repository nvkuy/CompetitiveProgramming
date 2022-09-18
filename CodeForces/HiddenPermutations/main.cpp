#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int query(int i) {
    cout << "? " << i << endl;
    cout.flush();
    int rp;
    cin >> rp;
    return rp;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> ans(n, 0);
        int i = 0;
        while (i < n) {
            if (ans[i] != 0) {
                i++;
                continue;
            }
            int pq = query(i + 1), iq = pq, cq = 0;
            while (cq != iq) {
                cq = query(i + 1);
                if (cq == 0)
                    return 0;
                ans[pq - 1] = cq;
                pq = cq;
            }
            i++;
        }
        cout << "! ";
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << endl;
        cout.flush();
    }

    return 0;
}
