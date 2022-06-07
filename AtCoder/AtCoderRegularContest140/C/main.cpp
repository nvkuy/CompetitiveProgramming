#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, x, diff = 0;
    cin >> n >> x;
    vector<int> a, b, ans;
    for (int i = 1; i < x; i++)
        a.push_back(i);
    for (int i = n; i > x; i--)
        b.push_back(i);
    ans.push_back(x);
    if (a.size() < b.size())
        swap(a, b);
    while (b.size() > 0) {
        diff = abs(a.back() - b.back());
        ans.push_back(a.back()); a.pop_back();
        ans.push_back(b.back()); b.pop_back();
    }
    set<int> rm;
    set<int>::iterator it;
    while (!a.empty()) {
        rm.insert(a.back());
        a.pop_back();
    }
    while (true) {
        diff++;
        it = rm.find(ans.back() + diff);
        if (it != rm.end()) {
            ans.push_back((*it));
            rm.erase(it);
            continue;
        }
        it = rm.find(ans.back() - diff);
        if (it != rm.end()) {
            ans.push_back((*it));
            rm.erase(it);
            continue;
        }
        break;
    }
    for (it = rm.begin(); it != rm.end(); it++)
        ans.push_back((*it));
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';

    return 0;
}
