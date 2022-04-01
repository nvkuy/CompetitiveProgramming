#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, ai;
    set<int> s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ai;
        s.insert(ai);
    }
    cout << s.size();

    return 0;
}
