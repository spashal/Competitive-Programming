#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int comp(void const *a,void const *b)
{
	int p=*(const int *)a;
	int q=*(const int *)b;
	return p-q;
}

int main()
{
	int t,w,a[150006];
	char s[150006];
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		w=0;
		scanf("%s",s);
		int r=strlen(s);
		for(int j=0;j<(r-2);j++)
		{
			if(s[j]=='t')
			{
				if(s[j+1]=='w') if(s[j+2]=='o')
				{
					if(s[j+3]=='o')
					{
						a[w]=j+1;
						w++;
						s[j+1]=113;
					}
					else
					{
						a[w]=j+2;
						w++;
						s[j+2]=113;
					}
				}
			}
		}
		for(int j=0;j<r-2;j++)
		{
			if(s[j]=='o') if(s[j+1]=='n') if(s[j+2]=='e')
			{
				if(s[j-1]=='o')
					{
						a[w]=j+1;
						w++;
						s[j+1]=113;
					}
					else
					{
						a[w]=j;
						w++;
						s[j]=113;
					}
			}
		}
		qsort(a,w,sizeof(a[0]),comp);
		printf("%d\n",w);
		for(int j=0;j<w;j++) printf("%d ",a[j]+1);
		printf("\n");
	}
	return 0;
}