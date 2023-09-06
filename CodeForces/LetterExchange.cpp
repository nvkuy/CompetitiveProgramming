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

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> hashF(333, 0);
    hashF['w'] = 0, hashF['i'] = 1, hashF['n'] = 2;
    vector<char> deHashF = { 'w', 'i', 'n' };

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n, vector<int>(3, 0));
        vector<vector<set<int>>> b(3, vector<set<int>>(3));
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (char c : s) a[i][hashF[c]]++;
            vector<int> need, dont_need;
            for (int c = 0; c < 3; c++) {
                if (a[i][c] == 0) need.push_back(c);
                if (a[i][c] > 1) dont_need.push_back(c);
            }
            for (int c : need) b[c][dont_need[0]].insert(i);
        }
        vector<pair<int, int>> ans_pos, ans_char;
        for (int i = 0; i < n; i++) {
            vector<int> need, dont_need;
            for (int c = 0; c < 3; c++) {
                if (a[i][c] == 0) need.push_back(c);
                if (a[i][c] > 1) dont_need.push_back(c);
            }
            for (int c : need) b[c][dont_need[0]].erase(i);
            for (int c : need) {
                if (b[dont_need[0]][c].size() > 0) {
                    int j = *b[dont_need[0]][c].begin();
                    b[dont_need[0]][c].erase(j);
                    a[j][c]--;
                    a[j][dont_need[0]]++;
                    ans_pos.push_back({i, j});
                    ans_char.push_back({deHashF[dont_need[0]], deHashF[c]});
                    continue;
                }
                int other = 3 - dont_need[0] - c;
                int j = *b[dont_need[0]][other].begin(), k = *b[other][c].begin();
                b[dont_need[0]][other].erase(j);
                b[other][c].erase(k);
                a[j][dont_need[0]]++;
                a[j][other]--;
                a[k][other]++;
                a[k][c]--;
                ans_pos.push_back({i, j});
                ans_char.push_back({deHashF[dont_need[0]], deHashF[other]});
                ans_pos.push_back({i, k});
                ans_char.push_back({deHashF[other], deHashF[c]});
            }
        }
        cout << ans_pos.size() << endl;
        for (int i = 0; i < ans_char.size(); i++)
            cout << ans_pos[i].first + 1 << ' ' << char(ans_char[i].first) << ' ' << ans_pos[i].second + 1 << ' ' << char(ans_char[i].second) << endl;
    }

    return 0;
}
