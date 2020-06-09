#include<stdio.h>
#include<string.h>

int main()
{
	char s[305][1005];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%s",s[i]);

	for(int i=0;i<n;i++)
	{
		int r=strlen(s[i]);
		if(s[i][r-1]=='o' && s[i][r-2]=='p')
			printf("FILIPINO\n");
		else if((s[i][r-5]=='m' && s[i][r-4]=='n') && s[i][r-3]=='i' && (s[i][r-2]=='d' && s[i][r-1]=='a'))
			printf("KOREAN\n");
		else printf("JAPANESE\n");
	}
	return 0;
}