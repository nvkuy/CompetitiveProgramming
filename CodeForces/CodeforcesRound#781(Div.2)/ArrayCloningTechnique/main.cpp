#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, ai, maxcnt;
    cin >> t;
    while (t--) {
        cin >> n;
        map<int, int> cnt;
        maxcnt = 1;
        for (int i = 0; i < n; i++) {
            cin >> ai;
            cnt[ai]++;
            maxcnt = max(maxcnt, cnt[ai]);
        }
        int curNum = maxcnt, freenum = 0, op = 0;
        while (curNum < n) {
            freenum = curNum;
            op++;
            if (curNum + freenum >= n) {
                op += (n - curNum);
                break;
            }
            curNum += freenum;
            op += freenum;
        }
        cout << op << endl;
    }

    return 0;
}
