#include <bits/stdc++.h>

using namespace std;

vector<int> par;

int root(int v) {
    return par[v] < 0 ? v : (par[v] = root(par[v]));
}

void mergeSet(int x, int y) {
    if ((x = root(x)) == (y = root(y)))
        return ;
    if (par[y] < par[x])
        swap(x, y);
    par[x] += par[y];
    par[y] = x;
}

int rand_range(int l, int r) {
    int range = r - l + 1;
    int num = rand() % range + l;
    return num;
}

int main()
{

    srand(842003);

    int n, q, t;
    cin >> n >> q;
    par.assign(n + 1, -1);
    while (q--) {
        cin >> t;
        int a, b, c, d;
        if (t == 1) {
            cin >> a >> b;
            int tmp = b - a + 1;
            for (int i = 0; i < tmp / 2; i++) {
                c = a + i, d = tmp - i - 1 + a;
                mergeSet(c, d);
            }
        } else {
            cin >> a >> b >> c >> d;
            if (b - a != d - c) {
                cout << "Not equal" << endl;
                continue;
            }
            int tmp = b - a + 1, iok = 1;
            for (int i = 0; i < 1e3; i++) {
                int p = rand_range(0, tmp - 1);
                if (root(p + a) != root(p + c)) {
                    iok = 0;
                    break;
                }
            }
            cout << (iok ? "Equal" : "Unknown") << endl;
        }
    }


    return 0;
}
