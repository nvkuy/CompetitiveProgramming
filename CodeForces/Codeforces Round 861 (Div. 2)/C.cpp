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

bool ok(string l, string r, string m) {
    if (stoll(l) <= stoll(m) && stoll(m) <= stoll(r))
        return true;
    return false;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    debugLocal();

    int t;
    cin >> t;
    while (t--) {
        string l, r;
        cin >> l >> r;
        if (l.length() != r.length()) {
            string ans = "";
            for (int i = 0; i < l.length(); i++)
                ans.push_back('9');
            cout << ans  << endl;
        } else {
            if (l == r) {
                cout << l << endl;
                continue;
            }
            bool isEnd = false;
            for (int diff = 0; diff < 10; diff++) {
                if (isEnd) break;
                for (int high = 0; high < 10; high++) {
                    if (isEnd) break;
                    int low = high - diff;
                    if (low < 0) continue;
                    string ans = "";
                    for (int i = 0; i < l.length(); i++) {
                        if (isEnd) break;
                        if (l[i] == r[i]) {
                            int num = l[i] - '0';
                            if (num > high || num < low)
                                break;
                            ans += to_string(num);
                        } else {
                            string tans = ans;
                            int num = max(l[i] - '0' + 1, low);
                            if (high >= num && r[i] - '0' >= num) {
                                tans += to_string(num);
                                for (int j = i + 1; j < l.length(); j++)
                                    tans += to_string(low);
                                if (ok(l, r, tans)) {
                                    cout << tans << endl;
                                    isEnd = true;
                                    // cout << "TEST: " << tans << ' ' << diff << ' ' << high << ' ' << low << ' ' << isEnd << endl;
                                    break;
                                }
                            }
                            tans = ans;
                            num = min(r[i] - '0' - 1, high);
                            if (num >= l[i] - '0' && num >= low) {
                                tans += to_string(num);
                                for (int j = i + 1; j < l.length(); j++)
                                    tans += to_string(high);
                                if (ok(l, r, tans)) {
                                    cout << tans << endl;
                                    isEnd = true;
                                    // cout << "TEST: " << tans << ' ' << diff << ' ' << high << ' ' << low << ' ' << isEnd << endl;
                                    break;
                                }
                            }
                        }
                    }
                    // cout << "TEST: " << diff << ' ' << high << ' ' << low << ' ' << isEnd << endl;
                }
            }
        }
    }

    return 0;
}
