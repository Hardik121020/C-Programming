#include<stdio.h>
int main()
{
	int k,i,x=1;
	printf("Enters the length of array:");
	scanf("%d",&k);
	
	int num[k],rem[k];
	for(i=0;i<k;i++)
	{
		printf("Enter Number %d:",i+1);
		scanf("%d",&num[i]);
	}
	
	for(i=0;i<k;i++)
	{
		printf("Enter Reminder %d:",i+1);
		scanf("%d",&rem[i]);
	}
	
	int j;
	while(1)
	{
		for(j=0;j<k;j++)
		{
			if(x%num[j] != rem[j])
			{
				break;
			}
			else
			{
				continue;
			}
		}
		if(j == k)
		{
			printf("x is %d",x);
			break;
		}
		else
		{
			x++;
		}
	}
	return 0;
	
}
