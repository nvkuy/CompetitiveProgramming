#include <bits/stdc++.h>

using namespace std;

int main()
{

    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    int t, n;
    bool c;
    string a, b, x;
    scanf("%d", &t);
    while (t--) {
        b.clear(); a.clear(); x.clear();
        scanf("%d", &n);
        cin.ignore();
        getline(cin, x);
        c = true;
        for (int i = 0; i < n; i++) {
            if (x[i] == '0') {
                a.push_back('0');
                b.push_back('0');
            } else if (x[i] == '1') {
                if (c) {
                    a.push_back('0');
                    b.push_back('1');
                    c = false;
                    continue;
                }
                a.push_back('1');
                b.push_back('0');
            } else {
                if (!c) {
                    a.push_back('2');
                    b.push_back('0');
                    continue;
                }
                a.push_back('1');
                b.push_back('1');
            }
        }
        printf("%s\n%s\n", a.c_str(), b.c_str());
    }

    return 0;
}
