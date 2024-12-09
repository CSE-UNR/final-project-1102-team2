//Authors: Shota Nakaoji, Brayden Harper, Leilany Delgado
//Date: 12/10/2024

#include<stdio.h>
#define COLUMN_MAX 150
#define ROW_MAX 50
#define FILENAME_LENGTH_MAX 20

//Function Prototypes(at least five)
int stringLength(char[]);
int punctuationCheck(char);
int openFile(FILE **fp, char *filename, char *mode);
void display(char partsofSpeech);

int main(){
//declare variables
    int row = 0;
    char string[ROW_MAX][COLUMN_MAX] = {0};
    char input[ROW_MAX/2][COLUMN_MAX] = {0};
    char filename[FILENAME_LENGTH_MAX] = {0};
//Open the file
    printf("Enter the name of a file: ");
    scanf("%s", filename);
    FILE *fp;
    if(openFile(&fp, filename, "r") == 1){
        return 1; //errors in the program
    }
//Store each line from the file, (string[even numbers or 0] = sentenses, string[even numbers] = 'A', 'V' or 'N')
    while(fgets(string[row], sizeof(string[row]), fp) != NULL){
        string[row][stringLength(string[row]) - 1] = '\0'; /*replace the newline character with the null character*/
        row++;
    }
    fclose(fp); //Close the file
//Get user input
    for(int index = 0; index < row/2; index++){
        switch(string[2 * index + 1][0]){
            case 'A':
            display('A');
            scanf("%s", input[index]);
            break;
            case 'N':
            display('N');
            scanf("%s", input[index]);
            break;
            case 'V':
            display('V');
            scanf("%s", input[index]);
            break;
            default:
            display('0');
            return 1; //errors in the program
        }
    }
//Display the sentences on the screen
    printf("%s", string[0]); //No space at the beginning of the sentence
    printf(" %s", input[0]); //first user input
    for(int index = 1; index < row/2; index++){
        if(punctuationCheck(string[2 * index][0])){
            printf("%s", string[2 * index]); //Remove a space before punctuation
        }else{
            printf(" %s", string[2 * index]); //add a space between each word
        }
        printf(" %s", input[index]); //add the user input
    }
    printf(" %s\n", string[row - 1]);
    return 0; //program exectuted successfully
}
//Count the length of a string
int stringLength(char str[]){
	int count = 0;
	for(int index = 0; str[index] != '\0'; index++){
		count+=1;
	}
	return count;
}

//Detect punctuation
int punctuationCheck(char punctuation){
    if(punctuation == '.' || punctuation == ',' || punctuation == '!' || punctuation == '?' || punctuation == ';' || punctuation == ':'){
        return 1; //Ture
    }else{
        return 0; //False
    }
}

//Open a file
int openFile(FILE **fp, char *filename, char *mode){
    *fp = fopen(filename, mode);
    if (*fp == NULL) {
        printf("Could not open the file\n");
        return 1; //errors in the program
    }
    return 0;
}

//Prompt users
void display(char partsofSpeech){
    switch(partsofSpeech){
        case 'A':
        printf("Please enter an adjective: ");
        break;
        case 'N':
        printf("Please enter a noun: ");
        break;
        case 'V':
        printf("Please enter a verb: ");
        break;
        default:
        printf("No such part of speech in the file\n");
    }
}
