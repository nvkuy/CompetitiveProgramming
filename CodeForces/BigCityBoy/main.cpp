#include <iostream>

using namespace std;

int main()
{

    long long n, x[1001], y[1001];
    cin >> n;
    for (long long i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    long long d = 0, md = 1e18 + 7;
    long long xm = -1, ym = -1;
    for (long long i = 0; i < n; i++) {
        d = 0;
        for (long long j = 0; j < n; j++) {
            d += (abs(x[i] - x[j]) + abs(y[i] - y[j]));
        }
        if (d <= md) {
            if (d == md) {
                if (x[i] == xm) {
                    if (y[i] < ym) {
                        ym = y[i];
                        xm = x[i];
                    }
                } else {
                    if (x[i] < xm) {
                        xm = x[i];
                        ym = y[i];
                    }
                }
                continue;
            }
            md = d;
            xm = x[i];
            ym = y[i];
        }
    }
    cout << xm << " " << ym;

    return 0;
}
