#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x, y;
    map<int, int> ddx, ddy;
    map<int, int>::iterator it;
    for (int i = 0; i < 3; i++) {
        cin >> x >> y;
        ddx[x]++;
        ddy[y]++;
    }
    for (it = ddx.begin(); it != ddx.end(); it++)
        if ((*it).second == 1)
            cout << (*it).first << ' ';
    for (it = ddy.begin(); it != ddy.end(); it++)
        if ((*it).second == 1)
            cout << (*it).first << ' ';

    return 0;
}
