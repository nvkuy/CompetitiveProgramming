#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string s;
    map<char, int> co;
    map<char, int>::iterator it;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++)
        co[s[i]]++;
    int no = 0;
    for (it = co.begin(); it != co.end(); it++) {
        if ((*it).second % 2)
            no++;
    }
    if (no > 1) {
        cout << "NO SOLUTION";
        return 0;
    }
    deque<char> ans;
    for (it = co.begin(); it != co.end(); it++) {
        if ((*it).second % 2) {
            for (int j = 0; j < (*it).second; j++)
                ans.push_back((*it).first);
            (*it).second = 0;
        }
    }
    for (it = co.begin(); it != co.end(); it++) {
        for (int j = 0; j < (*it).second / 2; j++) {
            ans.push_back((*it).first);
            ans.push_front((*it).first);
        }
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i];

    return 0;
}
