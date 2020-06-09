#include<stdio.h>
#include<math.h>

long long int binexpo(int s)
{
	long long int k=1,l=10;
	while(s>0)
	{
		if(s%2)
		k=k*l;
		l=l*l;
		s=s/2;
	}
	return k;
}

int main()
{
	long long int t,min,e,s,y;
	long long int sum=0,k,n;
	scanf("%lld",&t);
	for(int i=0;i<t;i++)
	{
		y=0;
		min=0;
		scanf("%lld",&n);
		long long int p=n;
		while(n>0)
		{
			y++;
			n=n/10;
		}
	//	printf("%d=y\n",y);
		sum=(y-1)*9;
		n=p;
		e=0;
		while(e<10)
		{
			e++;
			k=0;
			s=0;
			while(s<y)
			{
				k+=e*binexpo(s);
				s++;
			}
			if(k<=n) min++;
		}
		sum+=min;
		printf("%lld\n",sum);
	}
	return 0;
}