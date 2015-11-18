#include "caesar.h"

int main(int argc, char**argv){
	
	int option, status; // doesn't have to be unsigned?
	const char *infile;
	
	FILE *fp;
	
	infile = (char*)malloc(32); // doesn't hurt
	
	printf("\n|===========================|\n");
	printf("\n|      CYPHRA CAESARIS      |\n");
	printf("\n|===========================|\n");
	
	do {
		
		printf("\nWhat would you like to do?\n\n\t1) Encrypt a file\n\t2) Decrypt a file\n\t3) Quit\n");
		scanf("%d", &option);
		
		if (option == 1){
			// encrypt a file
			
			printf("\nPlease enter in the name of the file to be encrypted!\n");
			scanf("%s", infile);			
			fp = fopen(infile, "r");
			
			if (!fp){
				printf("\nError opening up file!");
			} else {
				status = encrypt(fp);
			}
			
			if (status == 1){
				printf("\nFile successfully encrypted!\n");
			} else {
				printf("\nFile encryption unsuccessful.\n");
			}
						
		} else if (option == 2){
			// decrypt a file
			
			printf("\nPlease enter in the name of the file to be decrypted!\n");
			scanf("%s", infile);			
			fp = fopen(infile, "r");
			
			if (!fp){
				printf("\nError opening up file!");
			} else {
				status = decrypt(fp);
			}
			
			if (status == 1){
				printf("\nFile successfully decrypted!\n");
			} else {
				printf("\nFile decryption unsuccessful.\n");
			}
			
		} else if (option == 3) {
			break; // quit
		} else {
			printf("\nInvalid option, try again!\n");
		}
		
	} while (option);
	
	printf("\nExiting program. Vale!\n");
	
	return 0;
	
}

int encrypt(FILE *fp){
	
	char c;
	int modnum, n;
	const char* alphabet, *fout;
	FILE *outfile;
	
	alphabet = (char*)malloc(26);
	fout = (char*)malloc(32);
	alphabet = "abcdefghijklmnopqrstuvwxyz";
	
	printf("\nEnter in an output file.\n");
	scanf("%s", fout);
	outfile = fopen(fout, "w+");
	
	if (!outfile){
		printf("\nError opening file!");
		return 0;
	}
	
	printf("\nEnter in a shift input n.\n\n\t>> ");
	scanf("%d", &n);
	printf("\nYour shift input n is %d.\n", n); 
	
	while ((c = fgetc(fp)) != EOF){
	
		if (c != ' '){
			
			modnum = (tolower(c) - 'a');
			modnum = (modnum + n)%26;
			
			c = alphabet[modnum];		
			fwrite(&c, 1, 1, outfile);
			
		} else if (c == ' '){
			
			fwrite(&c, 1, 1, outfile);

		}
		
    }
		
	return 1;
	
}

int decrypt(FILE *fp){
	
	char c;
	int modnum, n;
	const char* alphabet, *fout;
	FILE *outfile;
	
	alphabet = (char*)malloc(26);
	fout = (char*)malloc(32);
	alphabet = "abcdefghijklmnopqrstuvwxyz";
	
	printf("\nEnter in an output file.\n");
	scanf("%s", fout);
	outfile = fopen(fout, "w+");
	
	if (!outfile){
		printf("\nError opening file!");
		return 0;
	}
	
	printf("\nEnter in a shift input n.\n\n\t>> ");
	scanf("%d", &n);
	printf("\nYour shift input n is %d.\n", n); 
	
	while ((c = fgetc(fp)) != EOF){
	
		if (c != ' '){
			
			modnum = (tolower(c) - 'a');
			modnum = (modnum - n)%26;
			
			c = alphabet[modnum];		
			fwrite(&c, 1, 1, outfile);
			
		} else if (c == ' '){
			
			fwrite(&c, 1, 1, outfile);

		}
		
    }
	
	return 1;
	
}