#include<stdio.h>

int main()
{
	int t;
	long long int n,k;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%lld%lld",&n,&k);
		int f=n/k;
		if((k/2)<(n-k*f))
		{
			printf("%lld\n",(f*k+(k/2)));
		}
		else printf("%lld\n",n);
	}
	return 0;
}