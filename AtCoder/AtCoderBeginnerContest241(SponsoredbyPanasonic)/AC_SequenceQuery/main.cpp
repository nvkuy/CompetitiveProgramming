#include <bits/stdc++.h>

using namespace std;

int main()
{
    multiset<long long> ms;
    multiset<long long>::iterator it;
    long long q, x, k, t;
    cin >> q;
    while (q--) {
        cin >> t;
        if (t == 1) {
            cin >> x;
            ms.insert(x);
        } else if (t == 2) {
            cin >> x >> k;
            it = ms.upper_bound(x);
            if (it != ms.begin()) {
                it--;
                k--;
            }
            while (k > 0) {
                if (it == ms.begin())
                    break;
                k--;
                it--;
            }
            if (k > 0)
                cout << "-1\n";
            else
                cout << (*it) << endl;
        } else {
            cin >> x >> k;
            it = ms.lower_bound(x);
            if (it != ms.end())
                k--;
            while (it != ms.end() && k > 0) {
                it++;
                if (it == ms.end())
                    break;
                k--;
            }
            if (k > 0)
                cout << "-1\n";
            else
                cout << (*it) << endl;
        }
    }

    return 0;
}
