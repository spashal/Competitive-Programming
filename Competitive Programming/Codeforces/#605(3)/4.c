#include<stdio.h>

int main()
{
	long long int a[100005],m[100005];
	int i,maxa=0,z=0,n,max=0,r[2];
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%lld",&m[i]);
	for(i=0;i<n-1;i++) a[i]=m[i+1]-m[i];

	r[0]=-1;
	r[1]=-1;
	i=0;
	while(r[0]<n-1 && i<n-1)
	{
		z=0;
		max=0;
		i=r[1]+1;
		while(a[i]>0 && i<n-1) i++;
		max=i-r[1];
		r[0]=r[1];
		r[1]=i;
		printf("%d=r\n",i); 
		if(a[i]==0 && a[i+1]>0 && i<n-2) max++;
		else if(a[i]<0 && (a[i]+a[i+1])<0 && i<n-2)
			while(a[i+1]>0 && i<n-2) 
				{
	//	printf("*max=%d\n",max);
					max++;
					i++;
				}
		if(max>maxa) maxa=max;
	//	printf("max=%d\n",max);
	}
	printf("%d\n",maxa);
}