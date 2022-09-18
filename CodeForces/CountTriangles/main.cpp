#include <bits/stdc++.h>

using namespace std;

int countTriangles(std::vector<int> x, std::vector<int> y)
{
    int c = 0;
    vector <int> vt1, vt2;
    for (int i = 0; i < (x.size() - 2); i++) {
        for (int j = i + 1; j < (x.size() - 1); j++) {
            vt1 = {x[j] - x[i], y[j] - y[i]};
            for (int k = j + 1; k < x.size(); k++) {
                vt2 = {x[k] - x[j], y[k] - y[j]};
                //cout << vt1[0] << "," << vt1[1] << " " << vt2[0] << "," << vt2[1] << endl;
                if (vt1[0] * vt2[1] != vt1[1] * vt2[0])
                    c++;
            }
        }
    }
    return c;
}

int main()
{
    cout << countTriangles({0, 0, 1, 1}, {0, 1, 1, 0});
    return 0;
}
