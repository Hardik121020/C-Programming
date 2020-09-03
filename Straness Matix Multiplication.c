#include<stdio.h>
int n,m;
int main()
{
	n=2;
	m=2;
	int a[n][m],b[n][m],c[n][m],i,j,k;
	int m1,m2,m3,m4,m5,m6,m7;
	printf("Enter The Value in %dx%d Matrix A :\n",n,m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("Enter The Value in row %d and Column %d :",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
	
	printf("\nEnter The Value in %dx%d Matrix B :\n",n,m);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("Enter The Value in row %d and Column %d :",i+1,j+1);
			scanf("%d",&b[i][j]);
		}
	}
	
	printf("\nMatrix A :");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
	}
	
	printf("\nMatrix B :");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			printf("%d\t",b[i][j]);
		}
	}	
	
	m1= (a[0][0] + a[1][1])*(b[0][0]+b[1][1]);
  	m2= (a[1][0]+a[1][1])*b[0][0];
  	m3= a[0][0]*(b[0][1]-b[1][1]);
  	m4= a[1][1]*(b[1][0]-b[0][0]);
  	m5= (a[0][0]+a[0][1])*b[1][1];
  	m6= (a[1][0]-a[0][0])*(b[0][0]+b[0][1]);
  	m7= (a[0][1]-a[1][1])*(b[1][0]+b[1][1]);

  	c[0][0]=m1+m4-m5+m7;
  	c[0][1]=m3+m5;
  	c[1][0]=m2+m4;
  	c[1][1]=m1-m2+m3+m6;

	printf("\nMatrix C :");
	for(i=0;i<n;i++)
	{
		printf("\n");
		for(j=0;j<n;j++)
		{
			printf("%d\t",c[i][j]);
		}
	}
	
	return 0;
}
