#include<stdio.h>
int main()
{
	char al[26]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  	char mat[26][26];
  	int k,i,j;
  	for(i=0;i<26;i++)
  	{
    	k = i;
    	for(j=0;j<26;j++)
    	{
      		mat[i][j] = al[k++];
      		if(k==26)
        		k=0;
    	}		
  	}
  	char key[3] = {"hum"};
  	char word[6] = {"thepep"};
	char ency[6];
	int row[3],col[6];
	int n,m,p;    	
	for(p=0;p<6;p++)
  	{
		for(i=0;i<26;i++)
		{
			if(word[p]==mat[i][0])
			{	
				col[p]=i;
				break;
			}	
		}
	}
	for(k=0;k<3;k++)
	{
		for(i=0;i<26;i++)
		{
			if(key[k]==mat[0][i])
			{
				row[k]=i;
				break;
			}
		}
	}
	k=0;
	for(i=0;i<6;i++)
	{
		ency[i]=mat[row[k]][col[i]];
		if(k==2)
		{
			k=0;
		}
		else
		{
			k++;
		}
	}
	printf("Word:%s",word);
	printf("\nEncrypted word:");
	for(i=0;i<6;i++)
	{
		printf("%c",ency[i]);
	}
	return 0;
}
