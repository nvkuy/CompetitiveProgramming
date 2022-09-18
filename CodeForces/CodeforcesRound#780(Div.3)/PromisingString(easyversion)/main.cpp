#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, ans;
    string s;

    cin >> t;
    while (t--) {
        cin >> n;
        cin.ignore();
        getline(cin, s);
        ans = 0;
        vector<int> plusCnt(1, 0), minusCnt(1, 0);
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '+') {
                plusCnt.push_back(plusCnt[i - 1] + 1);
                minusCnt.push_back(minusCnt[i - 1]);
            } else {
                plusCnt.push_back(plusCnt[i - 1]);
                minusCnt.push_back(minusCnt[i - 1] + 1);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                int numPlus = plusCnt[j] - plusCnt[i - 1], numMinus = minusCnt[j] - minusCnt[i - 1];
                if ((numMinus - numPlus) % 3 == 0 && numMinus >= numPlus) {
                    ans++;
                    //cout << i << '|' << j << endl;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
