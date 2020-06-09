#include<stdio.h>

int main()
{
	int a[100005],c[100005],b[100005];
	int j,z,t,k,l,n;
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		z=0;
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[j]);
			c[j]=j;
		}
		c[n]=n;

		for(j=0;j<n;j++) b[j]=0;

		b[0]=a[0];
		c[a[0]]=-1;
		for(j=1;j<n;j++)
		{
			if(a[j-1]!=a[j])
			{
				b[j]=a[j];
				c[a[j]]=-1;
			}
			
		}
		for(j=1;j<n;j++)
		{
			if(b[j]!=0) break; 
		}
		int s=0;
		for(int h=j;h<n;h++)
		{
			if(b[h]!=0)
			{
				k=h-1;
				l=1;
				while(b[k]==0)
				{
					while((c[b[h]-l]<1 || c[b[h]-l]>=b[s]) && b[h]-l>-1) l++;
					b[k]=c[b[h]-l];
					c[b[h]-l]=-1;
					k--;
				}
				s=h;
			}
		}

		int y=n;
		k=n-1;
		l=1;
		while(k!=s)
		{
			while(c[n-l]<1) l++;
			b[k]=c[n-l];
			c[n-l]=-1;
			k--;
		}

		for(j=0;j<y;j++)
		{
			if(b[j]<1 || b[j]>n)
				z=-1;
		}

		for(j=1;j<=y;j++) if(c[j]>0) z=-1;

		if(z==-1) printf("-1");
		else for(j=0;j<y;j++) printf("%d ",b[j]);
		printf("\n");
	}
	return 0;
}