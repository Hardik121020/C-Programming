#include <stdio.h>
#include <ctype.h>


int anagram_checker(char s1[], char s2[])
{
 	int j = 0;
	char ch,ch1[100],ch2[100];
	while (s1[j]) 
	{ 
        ch = s1[j];  
        ch1[j] = tolower(ch); 
        j++; 
    }
    
    j = 0;
    while (s2[j]) 
	{ 
        ch = s2[j]; 
        ch2[j] = tolower(ch); 
        j++; 
    }
	
	
	
		
	int first[26] = {0}, second[26] = {0}, c=0;

  
  	while (ch1[c] != '\0') 
	{
    	first[ch1[c]-'a']++;
    	c++;
  	}

  	c = 0;

  	while (ch2[c] != '\0') 
	{
    	second[ch2[c]-'a']++;
    	c++;
  	}

  	for (c = 0; c < 26; c++)
  	{
    	if (first[c] != second[c])
    	{
      		return 0;
      	}
	}
  	return 1;
}

int main() {
	char string1[100], string2[100];

	scanf("%s",string1);
	scanf("%s",string2);

	


	if (anagram_checker(string1, string2) == 1)
		printf("Given Strings are anagrams\n");
	else
		printf("Given Strings are not anagrams\n");

	return 0;
}
