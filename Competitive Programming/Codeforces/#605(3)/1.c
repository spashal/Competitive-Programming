#include<stdio.h>
#include<stdlib.h>

long long int max(long long int a,long long int b)
{
	if(a>b) return a;
	return b;
}

long long int min(long long int a,long long int b)
{
	if(a>b) return b;
	return a;
}

int main()
{
	long long int a,b,c,x,y,z,t,sum;
 	scanf("%I64d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%I64d%I64d%I64d",&a,&b,&c);
		if(a==b && b==c)
		{
			sum=0;
		}
		else if(a==b)
		{
			if(llabs(b-c)>1)
			{
				sum=(llabs(b-c)-2)*2;
			}
			else sum=0;
		}
		else if(b==c)
		{
			if(llabs(b-a)>1)
			{
				sum=(llabs(b-a)-2)*2;
			}
			else sum=0;
		}
		else if(a==c)
		{
			if(llabs(b-c)>1)
			{
				sum=(llabs(b-c)-2)*2;
			}
			else sum=0;
		}
		else
		{
			x=max(max(a,b),max(b,c));
			z=min(min(a,b),min(b,c));
			y=a+b+c-x-z;
			sum=(llabs(x-z-2)+llabs(x-y-1)+llabs(y-z-1));
		}
		printf("%I64d\n",sum);
	}
	return 0;
}