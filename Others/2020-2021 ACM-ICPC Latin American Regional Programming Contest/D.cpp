/*
							 ______    _____      _____      ___     _____
							|   ____|  |	_  \    |   _  \    /     \   |   _  \
							|  |_____   |  |__|  |   |	|__|  |  |   _   |  |  |__|  |
							|   _____|  |  	_  	/    |   _   /   |  |_|  |  |   _   /
							|  |_____   |  | \  \    |  | \  \   |       |  |  | \  \
							|________|  |__|  \__\   |__|  \__\   \_____/   |__|  \__\

*/

#include<bits/stdc++.h>
using namespace std;
#define f(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
	int n;
	cin >> n;
	int a[n];
	map<int, int> mp;
	f(i, n)
	{
		cin >> a[i];
		mp[a[i]]++;
	}
	if(n == 1) cout << "N" << endl;
	else
	{
		vector<int> vt;
		f(i, 2e5)
		{
			if(mp[i] != 0)
			{
				if(mp[i]%2 == 0)
				{
					mp[i + 1] += mp[i]/2;
					mp[i] = 0;
				}else
				{
					mp[i + 1] += mp[i]/2;
					vt.push_back(i);
				}
			}
		}
		if(vt.size() > 2) cout << "N" << endl;
		else cout << "Y" << endl;
	}
	
	return 0;
}