#include<stdio.h>

int main()
{
	long long int t,a;
	scanf("%lld",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%lld",&a);
		if(a%14<7 && a%14>0 && a>14) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}