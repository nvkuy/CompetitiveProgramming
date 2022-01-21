#include <bits/stdc++.h>

using namespace std;

int cc(int c, int c1, int c2) {
    if (c == 2)
        return c1;
    else
        return c1 + c2;
}

int main()
{
    vector<int> ans;
    int t, n, li, ri, ci;
    int hi, lo, c1, c2, c3, c4;
    cin >> t;
    while (t--) {
        hi = 0, lo = 1e9 + 7, c1 = 1e9 + 7, c2 = 1e9 + 7, c4 = 1;
        cin >> n;
        ans.clear();
        for (int i = 0; i < n; i++) {
            cin >> li >> ri >> ci;
            if ((li == lo && ri >= hi) || (li <= lo && ri == hi)) {
                if (li == lo && hi == ri) {
                    if (ci < cc(c4, c1, c2)) {
                        c4 = 2;
                        hi = ri;
                        lo = li;
                        c1 = c2 = ci;
                        ans.push_back(cc(c4, c1, c2));
                        continue;
                    }
                } else {
                    if (ci < cc(c4, c1, c2)) {
                        c4 = 2;
                        hi = ri;
                        lo = li;
                        c1 = c2 = ci;
                        ans.push_back(cc(c4, c1, c2));
                        continue;
                    }
                    if (li < lo) {
                        c4 = 1;
                        lo = li;
                        c1 = ci;
                    } else {
                        c4 = 1;
                        hi = ri;
                        c2 = ci;
                    }
                    ans.push_back(cc(c4, c1, c2));
                    continue;
                }
            }
            c3 = 0;
            if (li <= lo) {
                if (li < lo) {
                    lo = li;
                    c1 = ci;
                    c3++;
                } else {
                    if (ci < c1 && c4 == 1) {
                        lo = li;
                        c1 = ci;
                        c3++;
                    }
                }
            }
            if (ri >= hi) {
                if (ri > hi) {
                    hi = ri;
                    c2 = ci;
                    c3++;
                } else {
                    if (ci < c2 && c4 == 1) {
                        hi = ri;
                        c2 = ci;
                        c3++;
                    }
                }
            }
            if (c3 > 0)
                c4 = c3;
            ans.push_back(cc(c4, c1, c2));
        }
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << endl;
    }

    return 0;
}
