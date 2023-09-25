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

struct participant {
    long long point, pen, id;
};

bool cmp(const participant &p1, const participant &p2) {
    if (p1.point == p2.point) {
        if (p1.pen == p2.pen) {
            return p1.id < p2.id;
        }
        return p1.pen < p2.pen;
    }
    return p1.point > p2.point;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        vector<participant> participants;
        int n, m, h;
        cin >> n >> m >> h;
        for (int i = 0; i < n; i++) {
            vector<int> a(m);
            for (int j = 0; j < m; j++) cin >> a[j];
            sort(a.begin(), a.end());
            long long point = 0, pen = 0, time = 0;
            for (int j : a) {
                time += j;
                if (time > h) break;
                point++;
                pen += time;
            }
            participants.push_back({point, pen, i});
        }
        sort(participants.begin(), participants.end(), cmp);
        for (int i = 0; i < n; i++) {
            if (participants[i].id == 0) {
                cout << i + 1 << endl;
                break;
            }
        }
    }

    return 0;
}
