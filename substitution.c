#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	int n,i,j,ch,k;
	char word[n],temp;
	L1:printf("\nEnter the lenght of string:");
	scanf("%d",&n);
	printf("Enter the word(in Upper case):");
	scanf("%s",word);
	char al[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	char replace[6] = {'B','H','J','X','W','T'};
	
	L2 :printf("\n1)Encnyption\n2)Decryption(Only Enter 3 length string)\n3)Enter New String\n4)Exit");
	printf("\nYour Choise:");
	scanf("%d",&ch);
	int table[n][2];
	switch(ch)
	{
		case 1:
			time_t t;
			srand((unsigned)time(&t));
			for (i=0;i<n;i++)
			{
				temp = word[i];
				temp = replace[rand()%6];
				table[i][1] = temp;
			}

			for (i=0;i<n;i++)
			{
				table[i][0] = word[i];
			}
			printf("\n\t  Table\nCharacter\tReplace Character\n");
			for(i=0;i<n;i++)
			{
				for(j=0;j<2;j++)
				{
					printf("%c",table[i][j]);
					printf("\t\t");
				}
				printf("\n");
			}
			goto L2;
		case 2:	
			for(i=0;i<27;i++)
			{
				for(j=0;j<27;j++)
				{
					for(k=0;k<27;k++)
					{
						printf("%c%c%c",al[i],al[j],al[k]);
						printf(",");
					}
					printf("\n");
				}
			}
			goto L2;
		case 3:
			goto L1;
		case 4:
			break;
		default:
			printf("Wrong Input");
			goto L2;
	}
	return 0;
}
