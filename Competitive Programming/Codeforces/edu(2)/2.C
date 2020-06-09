#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int a,b,t,u,e,ans;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>a>>b;
		int r=log10(b)+1;
		u=r;
		e=1;
		while(r--)
		{
			e*=10;
		}
		if(b<e-1) ans=a*(u-1);
		else ans=u*a;
		cout<<ans<<endl;
	}
	return 0;
}