#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    long long n, c, q, k;
    string s;
    cin >> t;
    while (t--) {
        cin >> n >> c >> q;
        cin.ignore();
        getline(cin, s);
        vector<pair<long long, long long>> copy_op(c + 1);
        vector<pair<long long, long long>> cur_str(c + 1);
        copy_op[0] = {1, n}; cur_str[0] = {n, 0};
        for (int i = 1; i <= c; i++) {
            long long l, r;
            cin >> l >> r;
            copy_op[i] = {l, r};
            cur_str[i].first = cur_str[i - 1].first + (r - l + 1LL);
            cur_str[i].second = cur_str[i - 1].first - l + 1LL;
        }
        /*
        for (int i = 0; i <= c; i++)
            cout << cur_str[i].first << '|' << cur_str[i].second << ' ';
        cout << endl;
        */
        while (q--) {
            cin >> k;
            int cur_op = c;
            while (k > n) {
                //cout << s << '|' << k << ' ';
                if (k > cur_str[cur_op - 1].first)
                    k -= cur_str[cur_op].second;
                cur_op--;
            }
            //cout << s << '|' << k << endl;
            cout << s[k - 1] << endl;
        }
    }


    return 0;
}
