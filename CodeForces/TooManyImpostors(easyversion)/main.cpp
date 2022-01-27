#include <bits/stdc++.h>

using namespace std;

int query(int a, int b, int c) {
    cout << "? " << a << ' ' << b << ' ' << c << endl;
    cout.flush();
    int rp;
    cin >> rp;
    return rp;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> ans(n + 1);
        vector<int> qrs(n + 3);
        for (int i = 1; i <= n; i++)
            qrs[i] = i;
        qrs[n + 1] = 1, qrs[n + 2] = 2;
        int bl = -1, wh = -1, pq = query(1, 2, 3), cq;
        for (int i = 2; i <= n; i++) {
            cq = query(qrs[i], qrs[i + 1], qrs[i + 2]);
            if (cq == -1)
                break;
            if (cq == pq)
                pq = cq;
            else if (cq > pq) {
                wh = qrs[i + 2];
                bl = qrs[i - 1];
                break;
            } else {
                bl = qrs[i + 2];
                wh = qrs[i - 1];
                break;
            }
        }
        if (bl < 0 && wh < 0)
            break;
        ans[bl] = false;
        ans[wh] = true;
        for (int i = 1; i <= n; i++) {
            if (i == bl || i == wh)
                continue;
            cq = query(bl, wh, i);
            if (cq == -1)
                break;
            ans[i] = cq;
        }
        if (cq == -1)
            break;
        int k = 0;
        vector<int> fa;
        for (int i = 1; i <= n; i++) {
            if (!ans[i]) {
                k++;
                fa.push_back(i);
            }
        }
        cout << "! " << k;
        for (int i = 0; i < fa.size(); i++)
            cout << ' ' << fa[i];
        cout << endl;
        cout.flush();
    }

    return 0;
}
