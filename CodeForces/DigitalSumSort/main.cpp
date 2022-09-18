#include <bits/stdc++.h>

using namespace std;

bool cp(int a1, int a2) {
    int t1 = 0, t2 = 0;
    bool t3 = a1 < a2;
    while (a1 > 0) {
        t1 += (a1 - (a1 / 10) * 10);
        a1 /= 10;
    }
    while (a2 > 0) {
        t2 += (a2 - (a2 / 10) * 10);
        a2 /= 10;
    }
    //cout << t1 << " " << t2 << endl;
    if (t1 == t2)
        return t3;
    return t1 < t2;
}
std::vector<int> digitalSumSort(std::vector<int> a)
{
    sort(a.begin(), a.end(), cp);
    return a;
}

int main()
{
    vector <int> test = digitalSumSort({13, 20, 7, 4});
    for (int i = 0; i < test.size(); i++)
        cout << test[i] << " ";
    cout << endl;
    return 0;
}
