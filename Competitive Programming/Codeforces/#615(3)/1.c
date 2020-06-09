#include<stdio.h>

int main()
{
	int a,b,c,d,n,t;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&n);
		long long int r=n+a+b+c;
		int e=r/3;
		if(r%3==0 && e>=a && e>=b && e>=c) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}