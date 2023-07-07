#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

inline void debugLocal() {
    if (!fopen("input.txt", "r"))
        return;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        vector<int> pm(s.length() + 1, 0), cntNeg(5, 0), cntPos(5, 0);
        vector<vector<int>> ps(s.length() + 1, vector<int>(5, 0));
        for (int i = 0; i < s.length(); i++) {
            pm[i + 1] = max(pm[i], s[i] - 'A');
            ps[i + 1][s[i] - 'A']++;
            for (int j = 0; j < 5; j++) ps[i + 1][j] += ps[i][j];
        }
        long long initAns = 0;
        for (int i = 1; i <= s.length(); i++) {
            if (pm[i] > s[i - 1] - 'A')
                initAns -= pow(10, s[i - 1] - 'A');
            else
                initAns += pow(10, s[i - 1] - 'A');
        }
        long long ans = initAns;
        for (int i = s.length(); i > 0; i--) {
            // cout << ans << endl;
            for (int j = 0; j < 5; j++) {
                long long tans = initAns;
                if (pm[i] > s[i - 1] - 'A')
                    tans += pow(10, s[i - 1] - 'A');
                else
                    tans -= pow(10, s[i - 1] - 'A');
                if (pm[i - 1] > j)
                    tans -= pow(10, j);
                else
                    tans += pow(10, j);
                for (int k = 0; k < s[i - 1] - 'A'; k++) {
                    long long tmp = 2LL * pow(10, k) * cntNeg[k];
                    tans += tmp;
                }
                for (int k = 0; k < j; k++) {
                    long long tmp = 2LL * pow(10, k) * cntNeg[k];
                    tans -= tmp;
                }
                for (int k = s[i - 1] - 'A'; k <= 'E' - 'A'; k++) {
                    long long tmp = 2LL * pow(10, k) * cntPos[k];
                    tans -= tmp;
                }
                for (int k = j; k <= 'E' - 'A'; k++) {
                    long long tmp = 2LL * pow(10, k) * cntPos[k];
                    tans += tmp;
                }
                ans = max(ans, tans);
            }
            int nextGreaterCnt = 0;
            for (int j = s[i - 1] - 'A' + 1; j <= 'E' - 'A'; j++)
                nextGreaterCnt += ps[i][j];
            if (nextGreaterCnt == 1)
                cntNeg[s[i - 1] - 'A']++;
            if (pm[i] <= s[i - 1] - 'A')
                cntPos[s[i - 1] - 'A']++;
        }
        cout << ans << endl;
    }

    return 0;
}
