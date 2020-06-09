#include<stdio.h>

int main()
{
	int t,a,c,b,k,ans;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d%d%d%d",&k,&a,&b,&c);
		if((a+b)<=k)
		{
			if((a+b+c)<=k) ans=1;
			else ans=2;
		}
		else
		{
			if((b+c)<=k) ans=2;
			else ans=3;
		}
		printf("%d\n",ans);
	}
	return 0; 
}