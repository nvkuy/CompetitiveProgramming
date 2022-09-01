#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        vector<int> d4, odd, even;
        vector<pair<int, int>> ans;
        for (int i = 1; i <= n; i++) {
            if (i % 2)
                odd.push_back(i);
            else {
                if (i % 4 == 0)
                    d4.push_back(i);
                else
                    even.push_back(i);
            }
        }
        if (k % 2) {
            while (odd.size() > 0) {
                int num1 = odd.back();
                odd.pop_back();
                int num2;
                if (even.size() > 0) {
                    num2 = even.back();
                    even.pop_back();
                } else {
                    num2 = d4.back();
                    d4.pop_back();
                }
                ans.push_back({num1, num2});
            }
        }
        while (true) {
            int num1 = 0;
            if (even.size() > 0) {
                num1 = even.back();
                even.pop_back();
            }
            if (num1 == 0 && odd.size() > 0) {
                num1 = odd.back();
                odd.pop_back();
            }
            if (num1 == 0)
                break;
            num1 += k;
            if (num1 % 2) {
                if (d4.size() == 0)
                    break;
                int num2 = d4.back();
                d4.pop_back();
                ans.push_back({num1 - k, num2});
                //cout << num1 - k << '|' << num2 << endl;
            } else {
                if (num1 % 4 == 0) {
                    int num2 = odd.back();
                    odd.pop_back();
                    ans.push_back({num1 - k, num2});
                    //cout << num1 - k << '|' << num2 << endl;
                } else {
                    int num2 = 0;
                    if (even.size() > 0) {
                        num2 = even.back();
                        even.pop_back();
                    }
                    if (num2 == 0 && d4.size() > 0) {
                        num2 = d4.back();
                        d4.pop_back();
                    }
                    if (num2 == 0)
                        break;
                    ans.push_back({num1 - k, num2});
                    //cout << num1 - k << '|' << num2 << endl;
                }
            }
            //cout << num1 << '|' << ans.size() << endl;
        }
        /*
        while (true) {
            int num = 0;
            if (odd.size() > 0) {
                num = odd.back();
                odd.pop_back();
            }
            if (num == 0 && d2.size() > 0) {
                num = d2.back();
                d2.pop_back();
            }
            if (num == 0 && d4.size() > 0) {
                num = d4.back();
                d4.pop_back();
            }
            if (num == 0)
                break;
            num += k;
            if (num % 2) {
                if (d4.size() == 0)
                    break;
                ans.push_back({num - k, d4.back()});
                d4.pop_back();
            } else {
                if (num % 4 == 0) {
                    int tmp = 0;
                    if (odd.size() > 0) {
                        tmp = odd.back();
                        odd.pop_back();
                    }
                    if (tmp == 0 && d2.size() > 0) {
                        tmp = d2.back();
                        d2.pop_back();
                    }
                    if (tmp == 0 && d4.size() > 0) {
                        tmp = d4.back();
                        d4.pop_back();
                    }
                    if (tmp == 0)
                        break;
                    ans.push_back({num - k, tmp});
                } else {
                    int tmp = 0;
                    if (d2.size() > 0) {
                        tmp = d2.back();
                        d2.pop_back();
                    }
                    if (tmp == 0)
                        break;
                    ans.push_back({num - k, tmp});
                }
            }
        }
        */
        if (ans.size() * 2 < n) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i].first << ' ' << ans[i].second << endl;
    }

    return 0;
}
