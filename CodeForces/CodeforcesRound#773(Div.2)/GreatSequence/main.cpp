#include <bits/stdc++.h>

using namespace std;

map<long long, int> co;
map<long long, int>::iterator it;

int main()
{
    long long t, n, x, c, ai;
    cin >> t;
    while (t--) {
        cin >> n >> x;
        vector<long long> a(n);
        co.clear();
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        for (int i = 0; i < n; i++) {
            it = co.find(a[i]);
            if (it != co.end())
                (it->second)++;
            else {
                if (a[i] % x == 0) {
                    it = co.find(a[i] / x);
                    if (it != co.end()) {
                        if ((*it).second > 0) {
                            (it->second)--;
                            continue;
                        }
                    }
                }
                /*
                it = co.find(a[i] * x);
                if (it != co.end()) {
                    if ((*it).second > 0) {
                        (it->second)--;
                        continue;
                    }
                }
                */
                co.insert(make_pair(a[i], 1));
            }
        }
        int c = 0;
        for (it = co.begin(); it != co.end(); it++) {
            if ((*it).second > 0)
                c += ((*it).second);
        }
        cout << c << endl;
    }

    return 0;
}
