#include <bits/stdc++.h>

using namespace std;

long long t, n, k, m = 1e9 + 7, s, i, tmp;

void itob(long long k) {
    if (k > 0) {
        if (k % 2) {
            tmp = 1;
            for (int j = 1; j <= i; j++)
                tmp = (tmp * n) % m;
            s = (s + tmp) % m;
        }
        //cout << "TEST: " << s << " " << i << " " << k << endl;
        i++;
        itob(k / 2);
    }
}

int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> k;
        s = 0;
        i = 0;
        itob(k);
        cout << s << endl;
    }

    return 0;
}
