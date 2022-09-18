#include <bits/stdc++.h>

using namespace std;

int n, t, a[30001], cl;

int main()
{

    cin >> n >> t;

    for (int i = 0; i < (n - 1); i++)
        cin >> a[i];

    cl = 1;
    while (cl < t) {
        //cout << cl << " ";
        cl += a[cl - 1];
    }
    //cout << endl;

    if (cl == t)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
