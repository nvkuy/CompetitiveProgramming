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

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        bool isOk = true, needInc = false;
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i]) {
                isOk = false;
                //cout << "Fail at " << i << endl;
                break;
            }
            if (a[i] < b[i] || needInc) {
                needInc = false;
                a[i] = b[i];
                int next = ((i + 1) % n);
                if (a[next] < b[i] - 1) {
                    needInc = true;
                    a[next] = b[i] - 1;
                }
                if (a[next] < b[next])
                    needInc = true;
                //cout << next << '|' << a[next] << '|' << b[next] << endl;
                if (a[next] > b[next]) {
                    isOk = false;
                    //cout << "Fail at " << next << endl;
                    break;
                }
            }
        }

        cout << (isOk ? "YES" : "NO") << endl;
    }

    return 0;
}
