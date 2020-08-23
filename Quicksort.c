#include<stdio.h>
#include<time.h>
int n;
void quicksort(long int sort[n],int first,int last)
{
	int i, j, pivot, temp;
	if(first<last)
	{
		pivot=first;
		i=first;
		j=last;
		while(i<j)
		{
			while(sort[i]<=sort[pivot]&&i<last)
			{
				i++;
			}	
			while(sort[j]>sort[pivot])
			{
				j--;
			}
			if(i<j)
			{
				temp=sort[i];
				sort[i]=sort[j];
				sort[j]=temp;
			}
		}
		temp=sort[pivot];
		sort[pivot]=sort[j];
		sort[j]=temp;
		quicksort(sort,first,j-1);
		quicksort(sort,j+1,last);
	}
}

int main()
{
	float Time_Taken;
	clock_t t;
	t=clock();
	n=100000;
	int i;
	int sort[n];
	FILE *f1;
	f1=fopen("file.txt","r");
	printf("Elements: ");
	for(i=0;i<n;i++)
	{
		fscanf(f1,"%ld",&sort[i]);
		printf("%ld ",sort[i]);
	}
	quicksort(sort,0,n-1);
	printf("\nSorted Elements: ");
	for(i=0;i<n;i++)
	{
		printf("\t%d",sort[i]);
	}
	t=clock()-t;
	Time_Taken=((double)t)/CLOCKS_PER_SEC;
	printf("\nTime Taken: %f",Time_Taken);
	return 0;
}
