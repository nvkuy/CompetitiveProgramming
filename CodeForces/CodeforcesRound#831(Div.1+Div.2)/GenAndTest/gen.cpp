#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int rand_range(int l, int r) {
    return l + rand() % (r - l + 1);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int limit = 6;
    cout << limit << endl;
    for (int i = 0; i < limit; i++)
        cout << rand_range(1, 20) << ' ';
    cout << endl;

    return 0;
}
