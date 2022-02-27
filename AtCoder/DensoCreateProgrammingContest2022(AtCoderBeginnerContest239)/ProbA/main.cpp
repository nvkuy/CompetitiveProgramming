#include <bits/stdc++.h>

using namespace std;

int main()
{
    double h, d = 12800000;
    cin >> h;
    cout << std::fixed;
    cout << std::setprecision(6);
    cout << (long double)(sqrt(h) * sqrt(h + d));

    return 0;
}
