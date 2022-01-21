#include<bits/stdc++.h>
using namespace std;
int X,N,p[10],d;
int main()
{
	double E,W,S;
	scanf("%lf%lf%lf",&E,&W,&S);
	printf("%lf",(E*E-S*S-E*(E-W))/S + S);
	return 0;
}
