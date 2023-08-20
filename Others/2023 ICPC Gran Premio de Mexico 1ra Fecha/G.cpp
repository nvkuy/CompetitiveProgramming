#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
#define endl '\n'
#define bit_cnt(x) __builtin_popcountll(x)

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MAXN = 5001;
int f[MAXN][MAXN];

int cal(int coin, int turn) {
    if (coin == 0) return false;
    if (f[coin][turn] != -1) return f[coin][turn];
    int canWin = false;
    for (int i = min(turn, coin); i >= 1; i--) {
        canWin = (!(cal(coin - i, turn + 1)));
        if (canWin) break;
    }
    return (f[coin][turn] = canWin);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    memset(f, -1, sizeof(f));
    int n;
    cin >> n;
    cout << (cal(n, 1) ? "Jane" : "John") << endl;

    return 0;
}
