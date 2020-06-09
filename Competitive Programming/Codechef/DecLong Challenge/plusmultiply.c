#include<stdio.h>

int main()
{
	long long int t,n,l,aha;
	long long int a[2];
	scanf("%lld",&t);
	for(int i=0;i<t;i++)
	{
		a[0]=0;
		a[1]=0;
		scanf("%lld",&n);
		for(int j=0;j<n;j++)
		{
			scanf("%lld",&aha);

			if(aha==0) a[0]++;
			else if(aha==2) a[1]++;
		}
		l=0;
		if(a[0]!=0)
		{
			l=(a[0]*(a[0]-1))/2;
		}
		if(a[1]!=0) l+=(a[1]*(a[1]-1))/2;

		printf("%lld\n",l);
	}
	return 0;
}