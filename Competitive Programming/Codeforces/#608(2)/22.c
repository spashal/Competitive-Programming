#include<stdio.h>

int main()
{
	int temp,r,t,n,a[203],b[1003];
	char s;
	scanf("%d",&n);
	scanf("%c",&s);
	if(s=='B') a[0]=0;
	else a[0]=1;
	int z=0;
	if(n%2==0)
	{
		r=0;
		for(int i=1;i<n;i++)
		{
			scanf("%c",&s);
			if(s=='B') a[i]=0;
			else a[i]=1;

			if(z==-1)
			{
				a[i]=t;
				z=0;
			}
			if(a[i]!=a[i-1] && z==0)
			{
				b[r]=i-1;
				a[i]=a[i-1];
				z=-1;
				t=a[i];
				r++;
			}
		}
		if(a[n-2]!=a[n-1])
			printf("-1\n");
		else
		{
			printf("%d\n",r);
			for(int i=0;i<r;i++) printf("%d ",b[i]);
				printf("\n");
		}
		for(int i=0;i<n;i++) printf("%d#",a[i]);
	}
	else
	{
		for(int i=1;i<n;i++)
		{
			scanf("%c",&s);
			if(s=='B') a[i]=0;
			else a[i]=1;
		}
		r=0;
		if(a[0]!=a[1])
		{
			temp=a[0];
			a[0]=a[1];
			a[1]=temp;
			b[r]=0;
			r++;
		}
		for(int i=1;i<n-1;i++)
		if(a[i]!=a[i-1])
		{
			b[r]=i;
			temp=a[i+1];
			a[i+1]=a[i];
			a[i]=temp;
			r++;
		}
		if(a[n-2]!=a[n-1])
		{
			for(int i=n-2;i>=0;i-=2)
			{
				b[r]=i;
				r++;
			}
		}
		printf("%d\n",r);
		for(int i=0;i<r;i++) printf("%d ",b[i]);
			printf("\n");
		for(int i=0;i<n;i++) printf("%d#",a[i]);

	}
	return 0;
}