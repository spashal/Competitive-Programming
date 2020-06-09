#include<stdio.h>
#include<string.h>

int main()
{
	int w,n,k,z;
	char s[200005],t[100];
	long long int sum,count=0;

	scanf("%d %d",&n,&k);
	for(int i=0;i<=n;i++)	scanf("%c",&s[i]);
	for(int i=0;i<(2*k);i++)	scanf("%c",&t[i]);

	for(int i=1;i<=n;i++)
	{
		z=0;
		w=2*k-1;
		while(w>0)
		{
			if(s[i]==t[w])
			{
				z=-1;
				break;
			}
			w-=2;
		}
	
		if(z==-1) count++;
		else
		{
			sum+=(count*(count+1))/2;
			count=0;
		}
	}
	sum+=((count*(count+1))/2);
	printf("%lld\n",sum);
	return 0;
}