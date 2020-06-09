#include<stdio.h>

int a[300000],b[300000];

int main()
{
	int n,k=1;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		b[a[i]]=-1;
	}

	for(int i=0;i<n;i++)
	{
		if(a[i]==0)
		{
			while(b[k]==-1) k++;
			a[i]=k;
			b[k]=i+1;
			k++;
		}
	}
//	for(int i=0;i<n;i++) printf("%d ",a[i]);
//	printf("\n");
	int v=1;
	for(int i=0;i<n;i++)
	{
			//	printf("%d@",i);

		if(a[i]==i+1)
			{
			//	printf("%d#",i);
				for(int g=v;;g=(g+1)%(n+1)) if(b[g]!=-1 && g!=i+1)
				{
					int temp=a[i];
					a[b[g]-1]=temp;
					a[i]=g;
					b[temp]=b[g];
					b[g]=-1;
				/*	for(int i=0;i<n;i++) printf("%d ",a[i]);
	printf("\n");		for(int i=0;i<=n;i++) printf("%d ",b[i]);
	printf("\n");*/
					v=g;
					break;
				}
			}
	}
	for(int i=0;i<n;i++) printf("%d ",a[i]);
	printf("\n");
	return 0;
}