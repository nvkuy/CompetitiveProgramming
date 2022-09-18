#include <bits/stdc++.h>

using namespace std;

int main()
{

    map<string, int> votes;
    map<string, int>::iterator it;
    string s, ans;
    int n, mc;
    cin >> n;
    cin.ignore();
    while (n--) {
        getline(cin, s);
        it = votes.find(s);
        if (it == votes.end()) {
            votes.insert(make_pair(s, 1));
            if (mc < 1) {
                ans = s;
                mc = 1;
            }
        } else {
            (it->second)++;
            if (mc < (it->second)) {
                ans = s;
                mc = it->second;
            }
        }
    }
    cout << ans;

    return 0;
}
