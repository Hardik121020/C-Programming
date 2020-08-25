#include<stdio.h>
#include<math.h>
int Euclid(int a,int b,int x,int y)
{
	int gcd;
	if(a==0)
	{
		x=0;
		y=1;
		return b;
	}
	else
	{
		int x1,y1;
		x1=1;
		y1=1;
		gcd = Euclid(b%a,a,x1,y1);
		
		x = y1 - (b/a)*x1;
		y = x1;
		
		return gcd;
	}
}

int main()
{
	int a,b;
	L1 : printf("Enter First Number:");
	scanf("%d",&a);
	printf("Enter Second Number:");
	scanf("%d",&b);
	printf("gcd(%d,%d):%d",a,b,Euclid(a,b,1,1));
	int choose;
	L2 : printf("\n\nPress 1 for enter another number \nPress 2 for Exit\nYour Choise:");
	scanf("%d",&choose);
	switch(choose)
	{
		case 1:
			goto L1;
		case 2:
			break;
		default:
			printf("Invalid Choise");
			goto L2;
	}
	return 0;
}
