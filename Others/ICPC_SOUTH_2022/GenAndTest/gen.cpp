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

    srand(time(0));
    int l = rand_range(1, 1e5);
    int r = rand_range(l, 1e5);
    cout << l << endl << r << endl;

    return 0;
}
