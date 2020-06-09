#include<stdio.h>

int max(int a,int b)
{
	if(a>b) return a;
	return b;
}

int main()
{
	int a[4];
	long long int x,y,n,sx,sy;
	a[0]=0;
	a[1]=0;
	a[2]=0;
	a[3]=0;
	scanf("%lld%lld%lld",&n,&sx,&sy);
	for(int i=0;i<n;i++)
	{
		scanf("%lld%lld",&x,&y);
		if((x-sx)>=1) a[0]++;
		if((x-sx)<=-1) a[1]++;
		if((y-sy)>=1) a[2]++;
		if((y-sy)<=-1) a[3]++;
	}

	int s=max(max(a[0],a[1]),max(a[2],a[3]));
	if(s==a[0])
	{
		printf("%d\n%lld %lld\n",s,sx+1,sy);
	}
	else if(s==a[1])
	{
		printf("%d\n%lld %lld\n",s,sx-1,sy);
	}
	else if(s==a[2])
	{
		printf("%d\n%lld %lld\n",s,sx,sy+1);
	}
	else if(s==a[3])
	{
		printf("%d\n%lld %lld\n",s,sx,sy-1);
	}
	return 0;
}