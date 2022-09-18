#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, n, ai, c[200002];
    long long f;
    deque<int> dq;
    cin >> t;
    while (t--) {
        memset(c, 0, sizeof(c));
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            c[ai]++;
        }
        f = 0;
        dq.clear();
        bool ic = true;
        for (int i = 0; i <= n; i++) {
            if (!ic) {
                cout << "-1 ";
                continue;
            }
            if (i <= 0) {
                if (c[0] <= 0) {
                    ic = false;
                    cout << "0 ";
                } else {
                    cout << c[0] << ' ';
                    while (c[0] > 1) {
                        dq.push_back(0);
                        c[0]--;
                    }
                }
                continue;
            }
            if (c[i] > 0) {
                cout << f + c[i] << ' ';
                while (c[i] > 1) {
                    dq.push_back(i);
                    c[i]--;
                }
            } else {
                if (dq.size() <= 0) {
                    ic = false;
                    cout << f << ' ';
                    continue;
                }
                cout << f << ' ';
                f += (i - dq.back());
                dq.pop_back();
            }
        }
        cout << '\n';
    }

    return 0;
}
