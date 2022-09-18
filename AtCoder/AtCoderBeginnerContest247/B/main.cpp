#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    string s1, s2;
    map<string, vector<int>> dd;
    map<string, vector<int>>::iterator it;
    cin >> n;
    vector<bool> isDone(n, false);
    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2;
        dd[s1].push_back(i);
        if (s1 != s2)
            dd[s2].push_back(i);
    }
    for (it = dd.begin(); it != dd.end(); it++) {
        if ((*it).second.size() != 1)
            continue;
        int i = (*it).second[0];
        if (!isDone[i]) {
            isDone[i] = true;
            n--;
        }
    }
    cout << ((n <= 0) ? "Yes" : "No");

    return 0;
}
