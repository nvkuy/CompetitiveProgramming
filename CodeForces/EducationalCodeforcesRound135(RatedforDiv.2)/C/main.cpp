#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int f(int a) {
    string tmp = to_string(a);
    return tmp.size();
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, ai;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<map<int, int>> ss(2);
        for (int i = 0; i < n; i++) {
            cin >> ai;
            ss[0][ai]++;
        }
        for (int i = 0; i < n; i++) {
            cin >> ai;
            ss[1][ai]++;
        }
        int ans = 0;
        while (n > 0) {
            int fe = 0, se = 1;
            if ((*ss[se].rbegin()).first > (*ss[fe].rbegin()).first)
                swap(fe, se);
            int num1 = (*ss[fe].rbegin()).first;
            //cout << "Before " << ss[0].size() << ' ' << ss[1].size() << endl;
            //cout << num1 << ' ' << fe << ' ' << se << endl;
            if (ss[fe][num1] == 1)
                ss[fe].erase(ss[fe].find(num1));
            else
                ss[fe][num1]--;
            if (ss[se].find(num1) != ss[se].end()) {
                //cout << "Match " << num1 << endl;
                n--;
                if (ss[se][num1] == 1)
                    ss[se].erase(ss[se].find(num1));
                else
                    ss[se][num1]--;
                continue;
            }
            //cout << "After " << ss[0].size() << ' ' << ss[1].size() << endl;
            ans++;
            num1 = f(num1);
            ss[fe][num1]++;
            //cout << fe << ' ' << num1 << endl;
        }
        //cout << "ANS: ";
        cout << ans << endl;
    }

    return 0;
}
