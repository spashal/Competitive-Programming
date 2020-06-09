#include<stdio.h>
#include<stdlib.h>

int comp(const void *p,const void *q)
{
	int a= *(const int *)p;
	int b= *(const int *)q;
	return a-b;
}

int a[2500],b[2500],r[2500],s[2500];

int main()
{
	int n,z;
	long long int m;
	scanf("%d%lld",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) scanf("%d",&b[i]);
	qsort((void*)a,n,sizeof(a[0]),comp);
	qsort((void*)b,n,sizeof(b[0]),comp);
	for(int i=0;i<(n-1);i++)
	{
		r[i]=a[i]-a[i+1];
		s[i]=b[i]-b[i+1];
	}
	r[n-1]=a[n-1]-a[0];
	s[n-1]=b[n-1]-b[0];
//	for(int i=0;i<n;i++) printf("%d ",a[i]);printf("\n");
//	for(int i=0;i<n;i++) printf("%d ",b[i]);printf("\n");

	long long int ans=1e9+1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
				int k=b[j]-a[i];
				if(k<0) k+=m;
				z=0;
				for(int w=0;w<n;w++)
				{
					if((a[(i+w)%n]+k)%m!=b[(j+w)%n])
					{
						z++;
						break;
					}
				}
				if(z==0 && ans>k) ans=k; 
		}
	}
	printf("%lld\n",ans);
}