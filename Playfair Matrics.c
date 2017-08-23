#include<stdio.h>
#include<string.h>
int i,j,flag=0,position=0;
char matrics[6][6]={},encryptedMsg[20]={},decryptedMsg[20]={};
void matricsEnter(char ch){	//start of function
	for(i=0;i<(sizeof(matrics)/sizeof(matrics[i]));i++){	//start of outer for loop, This will checks whether the passed argument character is in matrics or not
		for(j=0;j<sizeof(matrics[i]);j++){	//start of inner for loop
			if(ch!=matrics[i][j])	//start of if, Set flag=1 if character is not in matrics
				flag=1;	//end of if
			else {	//start of else, Set flag=0 means the character is already inside the matrics
				flag=0;
				break;
			}	//end of else
		}	//end of inner for loop
		if(flag==0)	//start of if
			break;	//end of if
	}	//end of outer for loop
	if(flag==1){	//start of if, Putting character in matrics if flag=1
		matrics[(position/(sizeof(matrics)/sizeof(matrics[i])))][(position%(sizeof(matrics)/sizeof(matrics[i])))]=ch;	//Here one time position is divided with (sizeof(matrics)/sizeof(matrics[i]))) and second time it taked remainder of position and (sizeof(matrics)/sizeof(matrics[i]))) this will help to get position in the range of matrics size
		position++;
	}	//end of if
}	//end of function
void encryption(char ithchar,char jthchar){	//start of function
	int p,q,firstpos[2],secondpos[2];
	for(p=0;p<(sizeof(matrics)/sizeof(matrics[p]));p++)	//start of outer for loop
		for(q=0;q<sizeof(matrics[q]);q++){	//start of inner for loop
			if((matrics[p][q]==ithchar)){	//start of if
				firstpos[0]=p;	//Getting row position of ithchar
				firstpos[1]=q;	//Getting column position of ithchar
			} else if(matrics[p][q]==jthchar){	//end of if and start of else
				secondpos[0]=p;	//Getting row position of jthchar
				secondpos[1]=q;	//Getting column position of jthchar
			}	//end of else
		}	//end of inner and outer for loops
	if(firstpos[0]==secondpos[0]){	//start of if, Checks whether both character are in same row
		if((firstpos[1]+1)<sizeof(matrics[p-1]))	//start of if, If column position+1 of ithchar is in column range of matrics then it will put value of the same row and next column in encryptedMsg array
			encryptedMsg[position++]=matrics[firstpos[0]][firstpos[1]+1];	//end of if
		else	//start of else, If column position+1 of ithchar is not in column range of matrics then it will put value of the same row and 0th column in encryptedMsg array
			encryptedMsg[position++]=matrics[firstpos[0]][0];	//end of else
		if((secondpos[1]+1)<sizeof(matrics[p-1]))	//start of if, If column position+1 of jthchar is in column range of matrics then it will put value of the same row and next column in encryptedMsg array
			encryptedMsg[position++]=matrics[secondpos[0]][secondpos[1]+1];	//end of if
		else	//start of else, If column position+1 of jthchar is not in column range of matrics then it will put value of the same row and 0th column in encryptedMsg array
			encryptedMsg[position++]=matrics[secondpos[0]][0];	//end of else
	} else if(firstpos[1]==secondpos[1]){	//end of if and start of else if, Checks whether both character are in same column
		if((firstpos[0]+1)<sizeof(matrics[p-1]))	//start of if, If row position+1 of ithchar is in row range of matrics then it will put value of the same column and next row in encryptedMsg array
			encryptedMsg[position++]=matrics[firstpos[0]+1][firstpos[1]];	//end of if
		else	//start of else, If row position+1 of ithchar is not in row range of matrics then it will put value of the same column and 0th row in encryptedMsg array
			encryptedMsg[position++]=matrics[0][firstpos[1]];	//end of else
		if((secondpos[0]+1)<sizeof(matrics[p-1]))	//start of if, If row position+1 of jthchar is in row range of matrics then it will put value of the same column and next row in encryptedMsg array
			encryptedMsg[position++]=matrics[secondpos[0]+1][secondpos[1]];	//end of if
		else	//start of else, If row position+1 of jthchar is not in row range of matrics then it will put value of the same column and 0th row in encryptedMsg array
			encryptedMsg[position++]=matrics[0][secondpos[1]];	//end of else
	} else {	//end of else if and start of else
		encryptedMsg[position++]=matrics[firstpos[0]][secondpos[1]];	//Putting value of same row as ithchar and same column as jthchar in encryptedMsg array
		encryptedMsg[position++]=matrics[secondpos[0]][firstpos[1]];	//Putting value of same row as jthchar and same column as ithchar in encryptedMsg array
	}	//end of else
}	//end of function
void decryption(char ithchar,char jthchar){	//start of function
	int p,q,firstpos[2],secondpos[2];
	for(p=0;p<(sizeof(matrics)/sizeof(matrics[p]));p++)	//start of outer for loop
		for(q=0;q<sizeof(matrics[q]);q++){	//start of inner for loop
			if((matrics[p][q]==ithchar)){	//start of if
				firstpos[0]=p;	//Getting row position of ithchar
				firstpos[1]=q;	//Getting column position of ithchar
			} else if(matrics[p][q]==jthchar){	//end of if and start of else
				secondpos[0]=p;	//Getting row position of jthchar
				secondpos[1]=q;	//Getting column position of jthchar
			}	//end of else if
		}	//end of inner and outer for loops
	if(firstpos[0]==secondpos[0]){	//start of if, Checks whether both character are in same row
		if((firstpos[1]-1)>=0)	//start of if, If column position-1 of ithchar is in column range of matrics then it will put value of the same row and previous column in encryptedMsg array
			decryptedMsg[position++]=matrics[firstpos[0]][firstpos[1]-1];	//end of if
		else	//start of else, If column position-1 of ithchar is not in column range of matrics then it will put value of the same row and last column in encryptedMsg array
			decryptedMsg[position++]=matrics[firstpos[0]][0];	//end of else
		if((secondpos[1]-1)>=0)	//start of else, If column position-1 of jthchar is in column range of matrics then it will put value of the same row and previous column in encryptedMsg array
			decryptedMsg[position++]=matrics[secondpos[0]][secondpos[1]-1];	//end of if
		else	//start of else, If column position-1 of jthchar is not in column range of matrics then it will put value of the same row and 0th column in encryptedMsg array
			decryptedMsg[position++]=matrics[secondpos[0]][0];	//end of else
	} else if(firstpos[1]==secondpos[1]){	//end of if and start of else if, Checks whether both character are in same column
		if((firstpos[0]-1)>=0)	//start of if, If row position-1 of ithchar is in row range of matrics then it will put value of the same column and previous row in encryptedMsg array
			decryptedMsg[position++]=matrics[firstpos[0]-1][firstpos[1]];	//end of if
		else	//start of else, If row position-1 of ithchar is not in row range of matrics then it will put value of the same column and last row in encryptedMsg array
			decryptedMsg[position++]=matrics[0][firstpos[1]];	//end of else
		if((secondpos[0]-1)>=0)	//start of if, If row position-1 of jthchar is in row range of matrics then it will put value of the same column and previous row in encryptedMsg array
			decryptedMsg[position++]=matrics[secondpos[0]-1][secondpos[1]];	//end of if
		else	//start of else, If row position-1 of jthchar is not in row range of matrics then it will put value of the same column and last row in encryptedMsg array
			decryptedMsg[position++]=matrics[0][secondpos[1]];	//end of else
	} else {	//end of else if and start of else
		decryptedMsg[position++]=matrics[firstpos[0]][secondpos[1]];	//Putting value of same row as ithchar and same column as jthchar in encryptedMsg array
		decryptedMsg[position++]=matrics[secondpos[0]][firstpos[1]];	//Putting value of same row as jthchar and same column as ithchar in encryptedMsg array
	}	//end of else
}	//end of function
void main(){	//start of main
	int length=0,kposition=0,count=0;
	char ch='a',key[20]={},msg[20]={},pairMsg[10][2]={};
	printf("\nEnter key (contains no space): ");	//asking user to enter key value
	scanf("%s",key);	//scanning key value in key array
	while(kposition<=strlen(key))	//start of while loop
		matricsEnter(key[kposition++]);//end of while loop, Calling function for enter key value in playfair matrics
	while((ch>='0' && ch<='9') || (ch>='a' && ch<='z')){	//start of while loop
		matricsEnter(ch++);	//Calling function for enter characters and digits except key value in playfair matrics
		if(ch>'z')	//start of if
			ch='0';	//end of if, Setting ch '0' after getting 'z' for further digit entering in playfair matrics
	}	//end of while loop
	for(i=0;i<(sizeof(matrics)/sizeof(matrics[i]));i++){	//start of outer for loop, It will display playfair matrics
		for(j=0;j<sizeof(matrics[i]);j++)	//start of inner for loop
			printf("%c\t",matrics[i][j]);	//end of inner for loop
		printf("\n");
	}	//end of outer for loop
	printf("\nEnter message (without space) : ");	//Asking user to enter message to be encrypted
	scanf("%s",msg);	//Scanning message in msg array
	for(i=0,position=0;i<(sizeof(pairMsg)/sizeof(pairMsg[i])),position<strlen(msg);i++)	//start of outer for loop, It will generate array of character pair of message to be encrypted
		for(j=0;j<sizeof(pairMsg[i]);j++){	//start of inner for loop
			if((j-1>=0) && (pairMsg[i][j-1]==msg[position])){	//start of if
				pairMsg[i][j]='x';
				count++;
			} else	//end of if and start of else
				pairMsg[i][j]=msg[position++];	//end of else
		}	//end of inner and outer for loops
	if((pairMsg[i-1][j-(sizeof(pairMsg[i-1])-1)]=='\0') && (pairMsg[i-1][j-sizeof(pairMsg[i-1])]!='x')){	//start of if
		pairMsg[i-1][j-(sizeof(pairMsg[i-1])-1)]='x';	//If there is a value either than 'x' on 0th position of last entered row of array and its 1th position is empty then this will put 'x' there
		count++;	//Counting that how many times 'x' is putted
	} else if((pairMsg[i-1][j-(sizeof(pairMsg[i-1])-1)]=='\0')){	//end of if and start of else
		printf("\nInvalid message to encrypt\n");	//If there is a value 'x' on 0th position of last entered row of array and its 1th position is empty then this will print this message
		exit(0);	//This situation is non accepted for this cipher so the program will stop execution from here
	}	//end of else
	for(i=0;i<(strlen(msg)+count)/2;i++){	//start of outer for loop, (strlen(msg)+count)/2=number of rows entered in pairMsg array
		for(j=0;j<sizeof(pairMsg[i]);j++)	//start of inner for loop
			printf("%c\t",pairMsg[i][j]);	//end of inner for loop
		printf("\n");
	}	//end of outer for loop
	for(i=0,position=0;i<(strlen(msg)+count)/2;i++)	//start of outer for loop
		for(j=0;j<sizeof(pairMsg[i]);j+=2)	//start of inner for loop
			encryption(pairMsg[i][j],pairMsg[i][j+1]);	//end of inner and outer for loops, The function called here will take character pair as an argument and apply encryption technique on it
	printf("\nEncrypted message : %s\n",encryptedMsg);	//Printing encrypted message
	for(i=0,position=0;i<strlen(encryptedMsg);i+=2)	//start of for loop
		decryption(encryptedMsg[i],encryptedMsg[i+1]);	//end of for loop, The function called here will take character pair as an argument and apply decryption technique on it
	printf("\nDecrypted message : %s\n",decryptedMsg);	//Printing decrypted message
}	//end of main