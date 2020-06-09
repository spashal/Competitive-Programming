#include<stdio.h>

int b[100005];

int main()
{
	int t,l,r,max[100005],min[100005],a[100005];
	long long int ans=0;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%d%d",&l,&a[0]);
		min[i]=10000000;
		max[i]=0;
		for(int j=1;j<l;j++)
		{
			scanf("%d",&a[j]);
		}
		for(int j=0;j<l;j++)
		{
			if(a[j]<min[i])
			{
				for(int h=j+1;h<l;h++)
				{
					if(a[j]<a[h])
					{
						b[i]=1;
						break;
					}
				}	
			}
			if(a[j]>max[i]) max[i]=a[j];
			if(min[i]>a[j]) min[i]=a[j];
		}
	}
//	for(int i=0;i<t;i++) printf("%d ",b[i]);printf("\n");
	for(int i=0;i<t;i++)
	{
		if(b[i]==1) ans+=t;
		else
		for(int j=0;j<t;j++)
		{
			if(b[j]==1) ans++;
			else if(min[i]<max[j]) ans++;
		}
//		printf("%lld %d %d\n",ans,min[i],max[i]);
	}
	printf("%lld\n",ans);
	return 0;
}