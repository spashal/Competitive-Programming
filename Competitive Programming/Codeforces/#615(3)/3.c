#include<stdio.h>
#include<math.h>

int main()
{
	int t,n,e,z;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		z=0;
		scanf("%d",&n);
		int s=sqrt(n);
		for(int j=2;j<=s;j++)
		{
			if(n%j==0)
			{
				e=n/j;
				int w=sqrt(e);
				for(int k=j+1;k<=w;k++)
					if(e%k==0)
						
							if(e/k>k && e/k!=k)
							{
								printf("YES\n%d %d %d\n",j,k,e/k);
								z=1;
								break;
							}
							
						}
						if(z==1) break;
			}
		
		if(z==0) printf("NO\n");
	}
	return 0;
}