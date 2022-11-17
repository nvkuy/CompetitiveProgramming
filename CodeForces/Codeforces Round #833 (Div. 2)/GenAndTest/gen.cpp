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

    cout << 1 << endl;
    cout << 7 << endl;
    vector<int> test(7, 0);
    test[rand_range(0, 3)] = rand_range(-5, 5);
    test[rand_range(2, 4)] = rand_range(-5, 5);
    test[rand_range(3, 6)] = rand_range(-5, 5);
    for (int i = 0; i < 7; i++)
        cout << test[i] << ' ';
    cout << endl;

    return 0;
}
