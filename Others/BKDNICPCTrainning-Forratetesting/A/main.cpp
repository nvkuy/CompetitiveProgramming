#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

pair<int, int> getVector(int x1, int y1, int x2, int y2) {
    return {x2 - x1, y2 - y1};
}

long long crossProduct(pair<int, int> v1, pair<int, int> v2) {
    long long a1 = v1.first, b1 = v1.second;
    long long a2 = v2.first, b2 = v2.second;
    return a1 * b2 - a2 * b1;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    long long cp = crossProduct(getVector(x1, y1, x2, y2), getVector(x2, y2, x3, y3));
    if (cp == 0)
        cout << "TOWARDS";
    else {
        if (cp < 0)
            cout << "RIGHT";
        else
            cout << "LEFT";
    }

    return 0;
}
