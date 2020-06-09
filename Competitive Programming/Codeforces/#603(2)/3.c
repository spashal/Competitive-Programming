#include<stdio.h>
#include<math.h>

int main()
{
	long long int t,n;
	scanf("%I64d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%I64d",&n);
		long long int s=sqrt(n);
		if(n==1) printf("2\n");
		else if(n==2 || n==3) printf("3\n");
		else if(s==n/s) printf("%I64d\n",2*s);
		else printf("%I64d\n",2*s+1);
		for(int j=0;j<=s;j++) printf("%d ",j);
		if(s!=n/s) printf("%I64d ",n/s);
		for(int j=s-1;j>0;j--)
			{
				
				printf("%I64d ",n/j);
			}
			printf("\n");
	}
	return 0;
}