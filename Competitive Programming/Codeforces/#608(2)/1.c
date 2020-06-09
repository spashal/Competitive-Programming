#include<stdio.h>

int min(int a,int b)
{
	if(a>b) return b;
	return a;
}

int main()
{
	int a,b,c,d,e,f;
	long long int ans;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);

	if(f>e)
	{
		ans=e*min(a,d-min(b,min(c,d)))+f*min(b,min(c,d));
	}

	else
	{
		ans=e*min(a,d)+f*min(b,min(c,d-min(a,d)));
	}
	printf("%lld\n",ans);
	return 0;
}