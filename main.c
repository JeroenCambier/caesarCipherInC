#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

char alphabet[] =
{
    'a','b','c','d','e','f','g','h','i','j',
    'k','l','m','n','o','p','q','r','s','t',
    'u','v','w','x','y','z',          
    'A','B','C','D','E','F','G','H','I','J',
    'K','L','M','N','O','P','Q','R','S','T',
    'U','V','W','X','Y','Z'           
};


char shiftLetter(char letter, int shiftAmount){
	int newLetterIndex = 0;
	
	for(int i = 0; i < sizeof(alphabet); i++){
		
		if(letter == ' '){
			return letter;
		}
		
		if(letter == alphabet[i]){
			newLetterIndex = i + shiftAmount;
			
			if(i <= 25 && newLetterIndex > 25){
				return alphabet[newLetterIndex - 26];
			}
			else if(i <= 25 && newLetterIndex <= 25){ // könnte man mit in das else unten packen aber erst testen
				return alphabet[newLetterIndex];
			}

			else if( i > 25 && newLetterIndex >= 52 ){
				return alphabet[newLetterIndex - 26];
			}
			else{
				return alphabet[newLetterIndex];
			}
		}
	}
}

void encrypt(){
	printf("\n");
	printf("How many letters to you want the output to be shifted?\n");

	int shiftAmount;
	scanf("%d", &shiftAmount);
	getchar(); 	

	printf("Enter text to be encrypted\n");
	char textToEncrypt[4096];
	fgets(textToEncrypt, sizeof(textToEncrypt), stdin);

	char encryptedText[sizeof(textToEncrypt)];
	for(int i = 0; i < sizeof(textToEncrypt); i++){
		if(textToEncrypt[i] == '\n'){
			break;
		}
		encryptedText[i] = shiftLetter(textToEncrypt[i], shiftAmount);
	}
	
	printf("Your encrypted text is:\n");
	printf("%s\n\n", encryptedText);

	// free(textToEncrypt);
	// free(encryptedText);
}

void decrypt(){
	printf("\n");
	printf("How many letters is the Text shifted?\n");

	int shiftAmount;
	scanf("%d", &shiftAmount);
	getchar();
	shiftAmount = 26 - shiftAmount;	

	printf("Enter text to be Decrypted\n");
	char textToDecrypt[4096];
	fgets(textToDecrypt, sizeof(textToDecrypt), stdin);

	char decryptedText[sizeof(textToDecrypt)];
	for(int i = 0; i < sizeof(textToDecrypt); i++){
		if(textToDecrypt[i] == '\n'){
			break;
		}
		decryptedText[i] = shiftLetter(textToDecrypt[i], shiftAmount);
	}
	
	printf("Your Decrypted text is:\n");
	printf("%s\n\n", decryptedText);

	// free(textToDecrypt);
	// free(decryptedText);
}

bool mainMenu(){
	printf("Casear Cipher Tool\n");
	printf("1. Encrypt\n");
	printf("2. Decrypt\n");
	printf("3. Quit\n");

	int selection;

	scanf("%d", &selection);

	switch (selection)
	{
		case 1:
			encrypt();
			break;
		
		case 2:
			decrypt();
			break;

		case 3:
			return false;
		
		default:
			printf("Input not recognized.");
			break;
	}
	
}

int main() {
	bool keepRunning = true;
	do{
		keepRunning = mainMenu();
	}while(keepRunning);

	return 0;
}