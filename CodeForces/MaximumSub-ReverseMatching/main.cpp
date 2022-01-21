#include <iostream>

using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, n, m1, m2, l, r, c;
    string s1, s2;
    cin >> t;
    cin.ignore();
    while (t--) {
        cin >> n;
        cin.ignore();
        getline(cin, s1);
        getline(cin, s2);
        //cout << s1 << " " << s2 << endl;
        m1 = 0;
        for (int i = 0; i < n; i++)
            if (s1[i] == s2[i])
                m1++;
        m2 = m1, l = 1, r = 1, c = 0;
        for (int i = 0; i < (n - 1); i++) {
            for (int j = i + 1; j < n; j++) {
                c = 0;
                for (int k = i; k <= j; k++) {
                    if (s1[k] == s2[j - k + i])
                        c++;
                }
                if (c >= m2) {
                    if ((c == m2) && (j - i <= r - l)) {
                        if (j - i == r - l) {
                            if ((i + 1) < r) {
                                r = j + 1;
                                l = i + 1;
                            }
                        }
                        if (j - i < r - l) {
                            r = j + 1;
                            l = i + 1;
                        }
                    }
                    if (c > m2) {
                        m2 = c;
                        r = j + 1;
                        l = i + 1;
                    }
                }
                cout << c << "|" << l << "|" << r << endl;
            }
        }
        cout << m1 << " " << m2 << " " << l << " " << r << endl;
    }

    return 0;
}
