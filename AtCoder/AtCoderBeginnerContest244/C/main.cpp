#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    vector<bool> dd(2 * n + 1, false);
    int i = 1, rp = -1;
    while (rp != 0) {
        while (dd[i])
            i++;
        cout << i << endl;
        dd[i] = true;
        cout.flush();
        cin >> rp;
        dd[rp] = true;
    }

    return 0;
}
