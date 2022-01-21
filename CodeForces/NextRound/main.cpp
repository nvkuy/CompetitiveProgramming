#include <bits/stdc++.h>

using namespace std;

int n, k, c, kn, ai;

int main()
{

    cin >> n >> k;
    c = 0; kn = 1;
    while (c < n) {
        cin >> ai;
        if (ai <= 0)
            break;
        else {
            c++;
            if (c >= k) {
                if (ai >= kn)
                    kn = ai;
                else {
                    c--;
                    break;
                }
            }
            //c++;
            //cout << c << " " << kn << "\n";
        }
    }

    cout << c;

    return 0;
}
