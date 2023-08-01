/*
							 ________    _______      _______      _____     _______
							|   _____|  |	__  \    |   __  \    /     \   |   __  \
							|  |_____   |  |__|  |   |	|__|  |  |   _   |  |  |__|  |
							|   _____|  |  	_  	/    |   _   /   |  |_|  |  |   _   /
							|  |_____   |  | \  \    |  | \  \   |       |  |  | \  \
							|________|  |__|  \__\   |__|  \__\   \_____/   |__|  \__\

*/

#include<bits/stdc++.h>
using namespace std;
#define f(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int chuyendoi(const string &s)
{
	int res = 0, p = 1;
    for (int i = s.size() - 1; i > 0; i--) {
        if (s[i] != '.') {
            res += (s[i] - '0') * p;
            p *= 10;
        }
    }
    return res;
}

int checkint(int sum)
{
	return (sum % 100) == 0;
}

int main() {
	int n;
	cin >> n;
	int sum = 0, ans = 0;
	string s;
	cin >> s;
	sum += chuyendoi(s);
	f(i, n)
	{
		cin >> s;
		sum += chuyendoi(s);
		if(!checkint(sum)) ans++;
	}
	cout << ans << endl;
	return 0;
}