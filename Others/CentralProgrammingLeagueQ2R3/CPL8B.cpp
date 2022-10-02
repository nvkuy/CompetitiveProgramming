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

    int n;
    string s;
    cin >> n;
    cin >> s;
    while (n--) {
        string tmp;
        char curC = s[0];
        int curCnt = 0;
        for (int i = 0; i < s.length(); i++) {
            if (curC == s[i])
                curCnt++;
            else {
                tmp += to_string(curCnt);
                tmp.push_back(curC);
                curC = s[i];
                curCnt = 1;
            }
            if (i + 1 == s.length()) {
                tmp += to_string(curCnt);
                tmp.push_back(curC);
            }
        }
        s = tmp;
    }
    cout << s << endl;

    return 0;
}
