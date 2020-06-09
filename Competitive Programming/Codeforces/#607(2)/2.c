#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
int comp(const void *p,const void *q)
{
	char a=*(const char *)p;
	char b=*(const char *)q;
	return (int)(a-b);
}
int main()
{
	int t;
	char s1[5100],s2[5100],s3[5100];
	scanf("%d",&t);
	for(int i=0;i<t;i++)
	{
		scanf("%s%s",s1,s2);
		strcpy(s3,s1);
		qsort(s3,strlen(s1),sizeof(s1[0]),comp);
		int a=strlen(s1);
		int b=strlen(s2);
		for(int j=0;j<a-1;j++)
		{
			if(s1[j]!=s3[j])
			{
				for(int r=a-1;r>=0;r--)
				{
					if(s1[r]==s3[j])
					{
						char temp=s1[r];
						s1[r]=s1[j];
						s1[j]=temp;
						break;
					}
				}
				break;
			}
		}
		if(strcmp(s1,s2)<0) printf("%s\n",s1);
		else printf("---\n");
	}
	return 0;
}