#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    long long c = 0, ai, so = 0, se = 0;
    string q;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ai;
        if (ai % 2) {
            c++;
            so += ai;
        } else
            se += ai;
    }
    cin >> q;
    for (int i = 0; i < q.length(); i++) {
        if (q[i] == '0')
            se /= 2;
        else {
            if (so == 0) {
                cout << se + so << '\n';
                continue;
            }
            so -= c;
            se += so;
            so = 0;
        }
        cout << se + so << '\n';
    }

    return 0;
}
