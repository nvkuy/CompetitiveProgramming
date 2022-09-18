#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void findLine(double x1, double y1, double x2, double y2, double &a, double &b, double &c) {
    a = -(y2 - y1);
    b = x2 - x1;
    c = -(x1 * a + y1 * b);
}

double getDisLine(double x1, double y1, double x2, double y2, double x3, double y3) {
    double a, b, c;
    findLine(x2, y2, x3, y3, a, b, c);
    cout << a << ' ' << b << ' ' << c << endl;
    return (fabs(a * x1 + b * y1 + c) / sqrt(a * a + b * b));
}

double getDisPoint(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    double ax, ay, bx, by, cx, cy, mx, my;
    cin >> ax >> ay >> bx >> by >> cx >> cy >> mx >> my;
    cout << setprecision(1) << fixed;
    vector<pair<double, pair<double, double>>> nearPoint;
    nearPoint.push_back({getDisPoint(ax, ay, mx, my), {ax, ay}});
    nearPoint.push_back({getDisPoint(bx, by, mx, my), {bx, by}});
    nearPoint.push_back({getDisPoint(cx, cy, mx, my), {cx, cy}});
    sort(nearPoint.begin(), nearPoint.end());
    cout << getDisLine(mx, my, nearPoint[0].second.first, nearPoint[0].second.second, nearPoint[1].second.first, nearPoint[1].second.second);

    return 0;
}
