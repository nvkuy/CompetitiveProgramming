#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

bool cmpChar(char c1, char c2) {
    return (int)c1 > (int)c2;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, n, m, k;
    string s1, s2;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        cin.ignore();
        getline(cin, s1);
        getline(cin, s2);
        sort(s1.begin(), s1.end(), cmpChar);
        sort(s2.begin(), s2.end(), cmpChar);
        //cout << s1 << ' ' << s2 << endl;
        string ans;
        int lastPick = 1, pick_count = 0;
        while (s1.size() > 0 && s2.size() > 0) {
            if (((!cmpChar(s1.back(), s2.back())) && ((lastPick == 0) || (lastPick == 1 && pick_count < k))) || (lastPick == 0 && pick_count == k)) {
                if (lastPick == 1)
                    pick_count++;
                else
                    lastPick = 1, pick_count = 1;
                ans.push_back(s1.back());
                s1.pop_back();
            } else {
                if (lastPick == 0)
                    pick_count++;
                else
                    lastPick = 0, pick_count = 1;
                ans.push_back(s2.back());
                s2.pop_back();
            }
        }
        cout << ans << endl;
    }

    return 0;
}
