#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n);
        map<int, int> mask, unMask;
        vector<vector<int>> c(n + 1);
        int mask_num = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (mask.find(a[i]) == mask.end()) {
                mask_num++;
                mask.insert({a[i], mask_num});
                unMask.insert({mask_num, a[i]});
            }
            a[i] = mask[a[i]];
            c[a[i]].push_back(i);
        }
        int num_ans, l, r, max_ans = 0;
        for (int num = 1; num < c.size(); num++) {
            if (c[num].size() == 0)
                break;
            int j = 0;
            for (int i = 0; i < c[num].size(); i++) {
                int p1 = c[num][i], p2 = c[num][j], notNumCnt = (p1 - p2) - (i - j);
                while (notNumCnt >= (i - j + 1)) {
                    j++;
                    p2 = c[num][j];
                    notNumCnt = (p1 - p2) - (i - j);
                }
                if (max_ans < (i - j + 1 - notNumCnt)) {
                    max_ans = i - j + 1 - notNumCnt;
                    num_ans = num, l = p2, r = p1;
                }
            }
        }
        cout << unMask[num_ans] << ' ' << l + 1 << ' ' << r + 1 << endl;
    }

    return 0;
}
