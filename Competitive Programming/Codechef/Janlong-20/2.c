#include<stdio.h>

long long int po(int a)
{
	long long int b=1,c=10;
	while((--a)>=0) b*=c;
	return b;
}

int main()
{
	int t,n,h;
	long long int a,b,d;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d%lld",&n,&a);
		long long int k=po(n);
		long long int l=k*2+a;
		printf("%lld\n",l);
		scanf("%lld",&b);
		printf("%lld\n",k-b);
		scanf("%lld",&d);
		printf("%lld\n",k-d);
		scanf("%d",&h);
				if(h==-1) return 0; 
	}
	return 0;
}