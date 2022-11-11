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

vector<long long> num;

long long numFromStr(string tmp) {
    bitset<33> bs(tmp);
    long long tans = bs.to_ullong();
    if (tans == 0)
        return 2e9 + 14;
    return tans;
}

void gen(int i, int isEnd, string cur) {
    if (i > 15)
        return;
    if (isEnd == 1) {
        // if (cur[0] == '0')
        //     return;
        string rcur = cur;
        reverse(rcur.begin(), rcur.end());
        string tans = cur + rcur;
        // cout << tans << endl;
        num.push_back(numFromStr(tans));
        tans = cur + "0" + rcur;
        num.push_back(numFromStr(tans));
        tans = cur + "1" + rcur;
        num.push_back(numFromStr(tans));
        return;
    }
    gen(i + 1, 0, cur + "0");
    gen(i + 1, 1, cur + "0");
    gen(i + 1, 0, cur + "1");
    gen(i + 1, 1, cur + "1");
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    gen(0, 0, "");
    num.push_back(0);
    num.push_back(1);
    sort(num.begin(), num.end());
    for (int i = 0; i < 20; i++)
        cout << num[i] << endl;
    long long q, a, b;
    cin >> q;
    while (q--) {
        cin >> a >> b;
        long long l = lower_bound(num.begin(), num.end(), a) - num.begin();
        long long r = upper_bound(num.begin(), num.end(), b) - num.begin();
        r--;
        if (l == num.size() || r < 0) {
            cout << 0 << endl;
            continue;
        }
        cout << r - l + 1 << endl;
    }

    return 0;
}
