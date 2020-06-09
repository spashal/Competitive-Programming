#include<stdio.h>
#include<string.h>
#include<conio.h>

void change(char a[],int l)
{
	if(a[l]==10){
		a[l]=0;
		a[l-1]++;
		change(a,l-1);
	}
}

char a[200005],c[200005];

int main()
{
	int z=0,n,k;
	scanf("%d%d",&n,&k);
	scanf("%s",a);
	strcpy(c,a);
	for(int i=0;i<n;i++) a[i]=a[i]-48;
	for(int i=0;i<n;i++) c[i]=c[i]-48;

	for(int i=0;i<n-k;i++)
	{
		if(a[i]!=a[i+k] && z==0)
		{
			if(a[i]>c[i]) z=1;	
			if(a[i+k]<a[i]) a[i+k]=a[i];
			else if(i>0)
			{
				a[i]++;
				a[i+k]=a[i];
				z=1;
			}
			else
			{
				a[i+k]=a[i];
				a[i+k-1]++;
				z=1;
				change(a,i+k-1);
			}
		}
		else if(a[i]!=a[i+k]) a[i+k]=a[i];
	}
	for(int i=0;i<n;i++) a[i]=a[i]+48;
	printf("%d\n",n);
	printf("%s\n",a);
	return 0;
}