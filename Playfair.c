#include<stdio.h>
int main()
{
	int i,j;
	char al[26]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char mat[5][5];
	int n1, n2;
    printf("Enter the length(even) of the string(If length of string is odd than take last letter x):");
    scanf("%d", &n1);
    char word[n1];
    printf("Enter the string to be encrypted:");
	scanf("%s",word);
    printf("Enter the length of the key:");
    scanf("%d", &n2);
    char key[n2];
    printf("Enter the key to be encrypt:");
	scanf("%s",key);
	
	int m=0,l=0,z;
	for(i=0;i<5;i++)
	{
        for(j=0;j<5;j++)
		{
            if(m<n2)
			{
                mat[i][j]=key[m];
                m++;
            } 
            else 
			{
                for(z=0;z<n2;z++)
				{
                    if(al[l]==key[z])
					{
                        l++;
                        continue;
                    }
                }
                mat[i][j]=al[l];
				l++;   
            }        
        }
    }
/*	
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%c ",mat[i][j]);
		}
		printf("\n");
	}
*/	
	int pos[n1][2];
	int k=0;
	for(k=0;k<n1;k++)
	{
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				if(mat[i][j]==word[k])
				{
					pos[k][0]=i;
					pos[k][1]=j;
				}
			}
		}
	}
	/*
	for(i=0;i<n1;i++)
	{
		for(j=0;j<2;j++)
		{
			printf("%d ",pos[i][j]);
		}
		printf("\n");
	}
	*/
	//Encryption Starts
	char ency[n1];
	for(i=0;i<n1-1;i++)
	{
		//Same row
		if(pos[i][0] == pos[i+1][0])
		{
			ency[i]=mat[i][(pos[i][1]+1)%5];
			ency[i+1]=mat[i+1][(pos[i][1]+1)%5];
		}
		//Same column
		else if (pos[i][1] == pos[i+1][1])
		{
			ency[i]=mat[(pos[i][0]+1)%5][i];
			ency[i+1]=mat[(pos[i][0]+1)%5][i+1];
		}
		//Different row different column
		else
		{
			ency[i]=mat[pos[i][0]][pos[i+1][1]];
			ency[i+1]=mat[pos[i+1][0]][pos[i][1]];
		}
	}
	printf("Plain Text:%s",word);
	printf("\nEncrypted word:%s",ency);
	return 0;
}
