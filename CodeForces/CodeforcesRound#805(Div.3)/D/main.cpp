#include <bits/stdc++.h>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t, p;
    string s;
    cin >> t;
    cin.ignore();
    while (t--) {
        getline(cin, s);
        cin >> p;
        cin.ignore();
        map<int, int> cnt;
        map<int, int>::reverse_iterator it;
        int ss = 0;
        for (int i = 0; i < s.length(); i++) {
            int num = s[i] - 'a' + 1;
            cnt[num]++;
            ss += num;
        }
        for (it = cnt.rbegin(); it != cnt.rend(); it++) {
            while (ss > p && (*it).second > 0) {
                ss -= (*it).first;
                (*it).second--;
            }
            if (ss <= p)
                break;
        }
        for (int i = 0; i < s.length(); i++) {
            int num = s[i] - 'a' + 1;
            if (cnt[num] > 0) {
                cout << s[i];
                cnt[num]--;
            }
        }
        cout << endl;
    }

    return 0;
}
