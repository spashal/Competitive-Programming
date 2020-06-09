#include<stdio.h>
#include<stdlib.h>

int comp(const void *p,const void *q)
{
	int a=*(const int *)p;
	int b=*(const int *)q;
	return a-b;
}

long long int a[200050],N[200050];

int main()
{
	int n,m,k=0;
	long long int sum=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	qsort((void*)a,n,sizeof(a[0]),comp);
	for(int s=1;k<m;s++)
	{
		if(k<m)
		{
			N[k]=a[0]-s;
			sum+=s;
			k++;
		}
		for(int i=1;i<n && k<m;i++)
		{
			if((a[i]-s)>a[i-1])
			{
				N[k]=a[i]-s;
				sum+=s;
				k++;
			}
		}

		for(int i=0;i<n-1 && k<m;i++)
		{
			if((a[i]+2*s)<a[i+1]) 
			{
				N[k]=a[i]+s;
				sum+=s;
				k++;
			}	
		}
		if(k<m)
		{
			N[k]=a[n-1]+s;
			sum+=s;
			k++;
		}

}
//	qsort((void*)N,m,sizeof(a[0]),comp);
	printf("%lld\n",sum);

	for(int i=0;i<m;i++) printf("%lld ",N[i]);
		printf("\n");
}