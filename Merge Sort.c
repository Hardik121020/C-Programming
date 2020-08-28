#include<stdio.h>
#include<time.h>
int n;

void merge(int *ms,int s,int e)
{
	int mid;
	mid=(s+e)/2;
	int i=s;
	int j=mid+1;
	int k=s;
	
	int temp[n];
	
	while(i<=mid && j<=e)
	{
		if(ms[i]<ms[j])
		{
			temp[k]=ms[i];
			k++;
			i++;
		}
		else
		{
			temp[k]=ms[j];
			k++;
			j++;
		}
	}
	while(i<=mid)
	{
		temp[k]=ms[i];
		k++;
		i++;
	}
	while(j<=e)
	{
		temp[k]=ms[j];
		k++;
		j++;
	}
	for (i=s;i<=e;i++)
	{
		ms[i]=temp[i];
	}
	
}

void merge_sort(int ms[],int s,int e)
{
	if (s>=e)
	{
		return;
	}
	int mid;
	mid=(s+e)/2;
	merge_sort(ms,s,mid);
	merge_sort(ms,mid+1,e);
	merge(ms,s,e);
}

int main()
{
	float Time_Taken;
	clock_t t;
	t=clock();
	int i=0;
	n=100000;
	FILE *f1;
	f1 =fopen("file.txt","r");
	int ms[n];
	printf("Elements: ");
	for(i=0;i<n;i++)
	{
		fscanf(f1,"%d",&ms[i]);
		printf(" %d ",ms[i]);
	}
	fclose(f1);
	merge_sort(ms,0,n-1);
	printf("\nSorted Elements: ");
	for(i=0;i<n;i++)
	{
		printf("%ld ",ms[i]);
	}
	t=clock()-t;
	Time_Taken=((double)t)/CLOCKS_PER_SEC;
	printf("\nTime Taken: %f",Time_Taken);
	return 0;
}
