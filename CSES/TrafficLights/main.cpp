#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x, n, ai, l, r;
    map<int, int> darkRanges;
    set<int> lights;
    set<int>::iterator it;

    cin >> x >> n;
    lights.insert(0), lights.insert(x);
    darkRanges.insert(make_pair(x, 1));

    while (n--) {
        cin >> ai;
        it = lights.lower_bound(ai);
        r = (*it);
        it--;
        l = (*it);
        lights.insert(ai);
        darkRanges[r - l]--;
        if (darkRanges[r - l] <= 0)
            darkRanges.erase(darkRanges.find(r - l));
        darkRanges[r - ai]++;
        darkRanges[ai - l]++;
        cout << (darkRanges.rbegin()->first) << ' ';
    }

    return 0;
}
