#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

double getD(pair<double, double> p1, pair<double, double> p2) {
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

double heron(double d1, double d2, double d3) {
    double d = (d1 + d2 + d3) / 2.0;
    return sqrt(d * (d - d1) * (d - d2) * (d - d3));
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, ans = 0;
    pair<double, double> apple;
    vector<pair<double, double>> sq(3);
    for (int i = 0; i < 3; i++)
        cin >> sq[i].first >> sq[i].second;
    double d1 = getD(sq[0], sq[1]), d2 = getD(sq[1], sq[2]), d3 = getD(sq[0], sq[2]);
    double s = heron(d1, d2, d3);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> apple.first >> apple.second;
        double s1 = heron(getD(apple, sq[0]), getD(apple, sq[1]), d1);
        double s2 = heron(getD(apple, sq[1]), getD(apple, sq[2]), d2);
        double s3 = heron(getD(apple, sq[2]), getD(apple, sq[0]), d3);
        if (fabs(s - s1 - s2 - s3) < 1e-5)
            ans++;
    }
    cout << fixed << setprecision(1) << s << endl;
    cout << fixed << setprecision(0) << ans;

    return 0;
}
