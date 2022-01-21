#include <bits/stdc++.h>

using namespace std;

long double d(long long x1, long long y1, long long x2, long long y2) {
    return sqrt((long double)pow(abs(x1 - x2), 2) + (long double)pow(abs(y1 - y2), 2));
}

long double st(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    long double d1 = d(x1, y1, x2, y2);
    long double d2 = d(x3, y3, x2, y2);
    long double d3 = d(x1, y1, x3, y3);
    long double p = (d1 + d2 + d3) / 2;
    return sqrt(p * (p - d1) * (p - d2) * (p - d3));
}

int main()
{
    long long x[4], y[4], t;
    long double s1, s2, s3, s4, er = 1e-14;
    cin >> t;
    while (t--) {
        cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2] >> x[3] >> y[3];
        s1 = st(x[0], y[0], x[1], y[1], x[2], y[2]);
        s2 = st(x[0], y[0], x[1], y[1], x[3], y[3]);
        s3 = st(x[0], y[0], x[2], y[2], x[3], y[3]);
        s4 = st(x[1], y[1], x[2], y[2], x[3], y[3]);
        //cout << s1 << " " << s2 << " " << s3 << " " << s4 <<  endl;
        if ((s1 - (s2 + s3 + s4) <= er) && (s1 - (s2 + s3 + s4) >= -er)) {
            cout << "NO\n";
            continue;
        }
        if ((s2 - (s1 + s3 + s4) <= er) && (s2 - (s1 + s3 + s4) >= -er)) {
            cout << "NO\n";
            continue;
        }
        if ((s3 - (s2 + s1 + s4) <= er) && (s3 - (s2 + s1 + s4) >= -er)) {
            cout << "NO\n";
            continue;
        }
        if ((s4 - (s2 + s3 + s1) <= er) && (s4 - (s2 + s3 + s1) >= -er)) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        //x[4] = x[0], x[5] = x[1], x[6] = x[2], x[7] = x[3];
        //y[4] = y[0], y[5] = y[1], y[6] = y[2], y[7] = y[3];

    }

    return 0;
}
