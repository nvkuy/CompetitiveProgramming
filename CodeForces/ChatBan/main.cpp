#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t, h, l, m;
    long long x, k;
    cin >> t;
    while (t--) {
        cin >> k >> x;
        if (((k - 1) * k) >= (2 * x)) {
            l = 0, h = k;
            while (l <= h) {
                if (h - l <= 1) {
                    if (l * (l + 1) < (2 * x))
                        break;
                }
                m = (l + h) / 2;
                //cout << "TEST: " << l << "|" << h << "|" << m << endl;
                if (((m + 1) * m) == (2 * x)) {
                    h = m;
                    //cout << "TEST: " << l << "|" << h << "|" << m << endl;
                    break;
                } else if (((m + 1) * m) < (2 * x))
                    l = m;
                else
                    h = m;
            }
            cout << h << endl;
        } else {
            l = 0, h = k;
            while (l < h) {
                if (h - l == 1) {
                    if ((2 * k * k - h * (h + 1)) < (2 * x))
                        break;
                }
                m = (l + h) / 2;
                if (((2 * k * k - m * (m + 1)) == 2 * x)) {
                    l = m;
                    break;
                } else if (((2 * k * k - m * (m + 1)) < 2 * x))
                    h = m;
                else
                    l = m;
            }
            cout << 2 * k - 1 - l << endl;
        }
    }

    return 0;
}
