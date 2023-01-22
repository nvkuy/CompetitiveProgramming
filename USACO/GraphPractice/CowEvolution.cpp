#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

inline void debugLocal() {
    if (!fopen("evolution.in", "r"))
        return;
    freopen("evolution.in", "r", stdin);
    freopen("evolution.out", "w", stdout);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int n;
    cin >> n;
    vector<set<string>> characteristics(n);
    set<string> all_characteristics;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        string s;
        for (int j = 0; j < k; j++) {
            cin >> s;
            characteristics[i].insert(s);
            all_characteristics.insert(s);
        }
    }
    for (string A : all_characteristics) {
        for (string B : all_characteristics) {
            bool hasA = false, hasB = false, hasBoth = false;
            for (int i = 0; i < n; i++) {
                if (characteristics[i].find(A) != characteristics[i].end() && characteristics[i].find(B) != characteristics[i].end())
                    hasBoth = true;
                else {
                    if (characteristics[i].find(A) != characteristics[i].end())
                        hasA = true;
                    if (characteristics[i].find(B) != characteristics[i].end())
                        hasB = true;
                }
            }
            if (hasA & hasB & hasBoth) {
                cout << "no" << endl;
                return 0;
            }
        }
    }
    cout << "yes" << endl;

    return 0;
}
