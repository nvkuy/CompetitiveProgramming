#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

//Convex Hull
const int N = 20000;
struct Point {
    long long x, y;
    bool operator<(const Point &v) const { return x == v.x ? y < v.y : x < v.x; }
    long long cross(const Point &p, const Point &q) const { return (p.x - x) * (q.y - y) - (p.y - y) * (q.x - x); }
} p[N], poly[N];

int n;

void enter() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%lld%lld", &p[i].x, &p[i].y);
}

long long size(Point poly[], int k) {
    long long S = (poly[k - 1].x - poly[0].x) * (poly[k - 1].y + poly[0].y);
    for (int i = 1; i < k; ++i)
        S += (poly[i - 1].x - poly[i].x) * (poly[i - 1].y + poly[i].y);
    return S;
    printf("%lld\n", S);
}

void solve() {
    sort(p, p + n);
    int k = 0;
    for (int i = 0; i < n; ++i) {
        while (k >= 2 && poly[k - 2].cross(poly[k - 1], p[i]) <= 0) --k;
        poly[k++] = p[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; --i) {
        while (k >= t && poly[k - 2].cross(poly[k - 1], p[i]) <= 0) --k;
        poly[k++] = p[i];
    }
    printf("%lld\n", size(poly, k));
}

//get vector point1->point2 (to check inline without error)
pair<long long, long long> getVector(pair<long long, long long> p1, pair<long long, long long> p2) {
    return {p1.first - p2.first, p1.second - p2.second};
}
//check inline point1 point2 point3 with vector point1->point2
bool isInLine(pair<long long, long long> p1, pair<long long, long long> p2, pair<long long, long long> vec) {
    return ((p1.first - p2.first) * vec.second) == ((p1.second - p2.second) * vec.first);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);



    return 0;
}
