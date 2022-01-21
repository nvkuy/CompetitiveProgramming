#include <bits/stdc++.h>

using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--) {
        int c = 0, ans = 0, n;
        char br;
        cin >> n;
        while (n--) {
            cin >> br;
            if (br == '(')
                c++;
            else {
                if (c <= 0)
                    ans++;
                else
                    c--;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
