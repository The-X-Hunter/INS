#include<stdio.h>
#include<string.h>
void main(){	//start of main
	int key=0,i=0,j=0;	//key variable for scanning integer key value
	char msg[20]={},encryptedMsg[20]={},decryptedMsg[20]={};	//Character arrays for storing original message, encrypted message and decrypted message, respectively
	printf("\nEnter message : ");	//Asking for message to encrypt
	gets(msg);	//Scanning message to msg array
	printf("\nEnter integer key value (1-25) : ");	//Asking for integer key value between 1-25
	scanf("%d",&key);	//Scanning key value
	while(!(key>=1 && key<=25)){	//start of while loop, Checking whether the key value is betenn 1-25 range or not
		printf("\nEnter key between 1-26 : ");	//If key value is out of the range then re-asking to enter key value between 1-25
		scanf("%d",&key);	//Re-scanning key value
	}	//end of while loop
	for(i=0;i<strlen(msg);i++){	//start of for loop
		if(msg[i]>='A' && msg[i]<='Z'){	//start of outer if, Checking whether character at i index is between A-Z
			if(!(msg[i]+key>'Z'))	//start of inner if, Checking whether character+key>the last character of range(Z)
				encryptedMsg[i]=msg[i]+key;	//end of inner if, If character+key is not out of range then putting it into encryptedMsg array
			else	//start of inner else, If character+key is out of range then
				encryptedMsg[i]='A'+(((msg[i]+key)-'Z')-1);	//end of inner else, Putting 'starting character of range'+(((character+key)-'ending character of range')-1) into encryptedMsg array
		} else if(msg[i]>='a' && msg[i]<='z'){	//end of outer if and start of outer else if, Checking whether character at i index is between a-z
			if(!(msg[i]+key>'z'))	//start of inner if, Checking whether character+key>the last character of range(z)
				encryptedMsg[i]=msg[i]+key;	//end of inner if, If character+key is not out of range then putting it into encryptedMsg array
			else	//start of inner else, If character+key is out of range then
				encryptedMsg[i]='a'+(((msg[i]+key)-'z')-1);	//end of inner else, Putting 'starting character of range'+(((character+key)-'ending character of range')-1) into encryptedMsg array
		} else if(msg[i]>='0' && msg[i]<='9'){	//end of outer else if and start of outer else if, Checking whether character at i index is between 0-9
			if(!(msg[i]+key>'9'))	//start of inner if, Checking whether character+key>the last character of range(9)
				encryptedMsg[i]=msg[i]+key;	//end of inner if, If character+key is not out of range then putting it into encryptedMsg array
			else	//start of inner else, If character+key is out of range then
				encryptedMsg[i]='0'+(((msg[i]+key)-'9')-1);	//end of inner else, Putting 'starting character of range'+(((character+key)-'ending character of range')-1) into encryptedMsg array
		} else	//end of outer else if and start of else
			encryptedMsg[i]=msg[i];	//end of else, Putting original character as it is into encryptedMsg array
		encryptedMsg[i+1]='\0';	//Putting null character on next index of encryptedMsg array
	}	//end of for loop
	printf("\nEncrypted message : %s\n",encryptedMsg);	//Printing encrypted message
	for(i=0;i<strlen(encryptedMsg);i++){	//start of for loop
		if(encryptedMsg[i]>='A' && encryptedMsg[i]<='Z'){	//start of outer if, Checking whether character at i index is between A-Z
			if(!(encryptedMsg[i]-key<'A'))	//start of inner if, Checking whether character-key<the first character of range(A)
				decryptedMsg[i]=encryptedMsg[i]-key;	//end of inner if, If character-key is not out of range then putting it into decryptedMsg array
			else	//start of inner else, If character-key is out of range then
				decryptedMsg[i]='Z'-(('A'-(encryptedMsg[i]-key))-1);	//end of inner else, Putting 'ending character of range'-(('starting character of range'-(character-key))-1) into decryptedMsg array
		} else if(encryptedMsg[i]>='a' && encryptedMsg[i]<='z'){	//end of outer if and start of outer else if, Checking whether character at i index is between a-z
			if(!(encryptedMsg[i]-key<'a'))	//start of inner if, Checking whether character-key<the first character of range(a)
				decryptedMsg[i]=encryptedMsg[i]-key;	//end of inner if, If character-key is not out of range then putting it into decryptedMsg array
			else	//start of inner else, If character-key is out of range then
				decryptedMsg[i]='z'-(('a'-(encryptedMsg[i]-key))-1);	//end of inner else, Putting 'ending character of range'-(('starting character of range'-(character-key))-1) into decryptedMsg array
		} else if(encryptedMsg[i]>='0' && encryptedMsg[i]<='9'){	//end of outer else if and start of outer else if, Checking whether character at i index is between 0-9
			if(!(encryptedMsg[i]-key<'0'))	//start of inner if, Checking whether character-key<the first character of range(0)
				decryptedMsg[i]=encryptedMsg[i]-key;	//end of inner if, If character-key is not out of range then putting it into encryptedMsg array
			else	//start of inner else, If character-key is out of range then
				decryptedMsg[i]='9'-(('0'-(encryptedMsg[i]-key))-1);	//end of inner else, Putting 'ending character of range'-(('starting character of range'-(character-key))-1) into decryptedMsg array
		} else	//end of outer else if and start of else
			decryptedMsg[i]=encryptedMsg[i];	//end of else, Putting original character as it is into decryptedMsg array
		decryptedMsg[i+1]='\0';	//Putting null character on next index of decryptedMsg array
	}	//end of for loop
	printf("\nDecrypted message : %s\n",decryptedMsg);	//Printing decrypted message
}