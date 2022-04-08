#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

set<int> rm;
set<int>::iterator it;

void nextIter() {
    if ((*it) == (*rm.rbegin()))
        it = rm.begin();
    else
        it++;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, t1, t2;
    cin >> n;
    for (int i = 1; i <= n; i++)
        rm.insert(i);
    it = rm.begin();
    while (it != rm.end()) {
        nextIter();
        t1 = (*it);
        nextIter();
        t2 = (*it);
        rm.erase(rm.find(t1));
        it = rm.find(t2);
        cout << t1 << ' ';
    }

    return 0;
}
