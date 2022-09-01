#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int fr = 2, ba = 5, to = 1, bo = 6, le = 4, ri = 3;

int go(string &way) {
    if (way == "North") {
        int tfr = bo, tba = to, tto = fr, tbo = ba, tle = le, tri = ri;
        fr = tfr, ba = tba, to = tto, bo = tbo, le = tle, ri = tri;
    } else if (way == "East") {
        int tfr = fr, tba = ba, tto = le, tbo = ri, tle = bo, tri = to;
        fr = tfr, ba = tba, to = tto, bo = tbo, le = tle, ri = tri;
    } else if (way == "West") {
        int tfr = fr, tba = ba, tto = ri, tbo = le, tle = to, tri = bo;
        fr = tfr, ba = tba, to = tto, bo = tbo, le = tle, ri = tri;
    } else if (way == "South") {
        int tfr = to, tba = bo, tto = ba, tbo = fr, tle = le, tri = ri;
        fr = tfr, ba = tba, to = tto, bo = tbo, le = tle, ri = tri;
    } else if (way == "Right") {
        int tfr = ri, tba = le, tto = to, tbo = bo, tle = fr, tri = ba;
        fr = tfr, ba = tba, to = tto, bo = tbo, le = tle, ri = tri;
    } else {
        int tfr = le, tba = ri, tto = to, tbo = bo, tle = ba, tri = fr;
        fr = tfr, ba = tba, to = tto, bo = tbo, le = tle, ri = tri;
    }
    return to;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, ans = 0;
    string s;
    cin >> n;
    while (n--) {
        cin >> s;
        ans += go(s);
    }
    cout << ans + 1;

    return 0;
}
