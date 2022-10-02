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

    int n, cnta = 0, cntb = 0, cntd = 0;
    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        bitset<33> bs(i);
        if (bs.count() * 2 != n)
            continue;
        vector<set<int>> card(2);
        for (int i = 0; i < n; i++) {
            if (bs[i])
                card[0].insert(i);
            else
                card[1].insert(i);
        }
        int win = -1;
        for (int j = 0; j * 2 < n; j++) {
            int first = 0, second = 1;
            if (j % 2)
                swap(first, second);
            int t1 = *card[first].rbegin();
            card[first].erase(card[first].find(t1));
            auto it = card[second].upper_bound(t1);
            if (it == card[second].end()) {
                win = first;
                break;
            }
            card[second].erase(it);
        }
        cout << i << " - ";
        if (win == -1) {
            cout << "DRAW: ";
            cntd++;
        } else if (win == 0) {
            cout << "ALEX: ";
            cnta++;
        } else {
            cout << "BORIS: ";
            cntb++;
        }
        for (int j = 0; j < n; j++)
            if (bs[j]) cout << j << ' ';
        cout << endl;
    }
    cout << cnta << ' ' << cntb << ' ' << cntd << endl;

    return 0;
}
