#include<stdio.h>
#include<string.h>
void main(){	//start of main
	int i=0,j=0;
	char msg[50]={},encryptedMsg[sizeof(msg)]={},decryptedMsg[sizeof(msg)]={},key[]={'w','f','r','e','c','v','s','k','l','d','t','u','a','x','n','y','o','q','b','z','m','g','i','h','p','j'};	//key array contains all 26 alphabatic characters in random order
	printf("\nEnter message : ");	//Asking for message
	gets(msg);	//Scanning message in msg array
	for(i=0;i<strlen(msg);i++){	//start of for loop
		if(msg[i]>='A' && msg[i]<='Z')	//start of if, Checking whether the character is between A-Z
			encryptedMsg[i]=toupper(key[msg[i]-'A']);	//end of if, If between the range then substracting 'staring character of range' from given character and treating as an index to get character from key array then converting to upper case
		else if(msg[i]>='a' && msg[i]<='z')	//start of else if, Checking whether the character is between a-z
			encryptedMsg[i]=key[msg[i]-'a'];	//end of else if, If between the range then substracting 'staring character of range' from given character and treating as an index to get character from key array
		else if(msg[i]=' ')	//start of else if, Checking whether the character is space
			encryptedMsg[i]=msg[i];	//end of else if, Putting as it is in encryptedMsg array
		encryptedMsg[i+1]='\0';	//Putting null character at the i+1 index
	}	//end of for loop
	printf("\nEncrypted message : %s\n",encryptedMsg);	//Priting encrypted message
	for(i=0;i<strlen(encryptedMsg);i++){	//start of for loop
		while(encryptedMsg[i]!=key[j] && encryptedMsg[i]!=toupper(key[j]))	//start of while loop, Searching character of encrypted message in key array and getting its index
			j++;	//end of while loop, Getting index of character
		if(encryptedMsg[i]>='A' && encryptedMsg[i]<='Z')	//start of if, Checking whether the character is between A-Z
			decryptedMsg[i]='A'+j;	//end of if, If between the range then adding 'staring character of range' with j
		else if(encryptedMsg[i]>='a' && encryptedMsg[i]<='z')	//start of else if, Checking whether the character is between a-z
			decryptedMsg[i]='a'+j;	//end of if, If between the range then adding 'staring character of range' with j
		else if(encryptedMsg[i]=' ')	//start of else if, Checking whether the character is space
			decryptedMsg[i]=encryptedMsg[i];	//end of else if, Putting as it is in decryptedMsg array
		decryptedMsg[i+1]='\0';	//Putting null character at the i+1 index
		j=0;	//Assigning 0 to j for further use
	}	//end of for loop
	printf("\nDecrypted message : %s\n",decryptedMsg);
}	//end of main