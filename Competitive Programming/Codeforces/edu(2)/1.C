#include<iostream>
#include<cmath>

long long int ceiling(long long int a,long long int b)
{
	if(a%b!=0) return (1+a/b);
	return a/b;
}
using namespace std;

int main()
{
	long long int t,z,j,d,n;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		z=0;
		cin>>n>>d;
		int r=sqrt(d);
	//	cout<<r<<"8";
		if(r<10) r=10;
		if(n>=d) z=1;
		else
		for(j=r-8;j<r+10;j++)
		{
			if(n>=(j-1+ceiling(d,j)))
			{
				z=1;
				break;
			}
		}
		if(z==1) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return(0);
}