#include<stdio.h>

int main()
{
	int
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",&n);
		for(int j=0;j<n;j++) scanf("%d%d",&a[i][0],&a[i][1]);
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n-1-j;k++)
			{
				if(a[k][0]>=a[k+1][0] && a[k][1]>=a[k+1][1])
				{
					temp=a[k][0];
					a[k][0]=a[k+1][0];
					a[k+1][0]=temp;
					temp=a[k][1];
					a[k][1]=a[k+1][1];
					a[k+1][1]=temp;
				}
				else if (a[k][0]>=a[k+1][0] || a[k][1]>=a[k+1][1])
				{
					z=1;
					break;
				}
			}
		}
		if

	}
}