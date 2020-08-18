#include<stdio.h>
#include<math.h>
int main()
{
	int p,q;
	printf("Enter public number for user 1:");
	scanf("%d",&p);
	printf("Enter public number for user 2:");
	scanf("%d",&q);
	
	int a,b;
	printf("Private key for user 1:");
	scanf("%d",&a);
	printf("Private key for user 2:");
	scanf("%d",&b);
	
	int x,y;
	x = (pow(q,b));
	y = (pow(q,a));
	x = x%p;
	y = y%p;
	
	int k_a,k_b;
	k_a = pow(x,a);
	k_b = pow(y,b);
	k_a = k_a%p;
	k_b = k_b%p;
	printf("Secret Key of user 1:%d",k_a);
	printf("\nSecret Key of user 2:%d",k_b);
}
