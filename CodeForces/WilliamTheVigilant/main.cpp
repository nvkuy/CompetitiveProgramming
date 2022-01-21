#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q, p, co = -1;
    char dd[100001];
    memset(dd, 0, sizeof(dd));
    string s;
    char c;
    cin >> n >> q;
    cin.ignore();
    getline(cin, s);
    while (q--) {
        cin >> p >> c;
        //cout << c << endl;
        s[p - 1] = c;
        //cout << s << endl;
        if (co >= 0) {
            if (dd[p - 1] > 0) {
                if (c != dd[p - 1]) {
                    co--;
                    if (dd[p - 1] == 'a') {
                        dd[p] = 0;
                        dd[p + 1] = 0;
                    } else if (dd[p - 1] == 'b') {
                        dd[p - 2] = 0;
                        dd[p] = 0;
                    } else {
                        dd[p - 3] = 0;
                        dd[p - 2] = 0;
                    }
                    dd[p - 1] = 0;
                } else {
                    cout << co << endl;
                    continue;
                }
            }
            for (int i = p - 3; i <= p + 1; i++) {
                if (i - 2 >= 0 && i + 2 < n) {
                    if (s[i] == 'c' && s[i - 1] == 'b' && s[i - 2] == 'a') {
                        dd[i - 1] = 'b';
                        dd[i] = 'c';
                        dd[i - 2] = 'a';
                        co++;
                    }
                }
            }
            cout << co << endl;
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (i - 2 >= 0) {
                if (s[i] == 'c' && s[i - 1] == 'b' && s[i - 2] == 'a') {
                    dd[i - 1] = 'b';
                    dd[i] = 'c';
                    dd[i - 2] = 'a';
                    co++;
                }
            }
        }
        //cout << s << endl;
        cout << co << endl;
    }

    return 0;
}
