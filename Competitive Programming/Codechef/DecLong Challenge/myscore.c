#include<stdio.h>

int main()
{
	int t,a,b,n,maxi;
	int max[9];
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		maxi=0;
		for(int j=0;j<9;j++) max[j]=0;
		scanf("%d",&n);
		for(int j=0;j<n;j++)
		{
			scanf("%d %d",&a,&b);

			if(a<9)
			{
				if(b>max[a]) max[a]=b;
			}
		}
		for(int j=1;j<9;j++) maxi+=max[j];
		printf("%d\n",maxi);
	}
	return 0;
}