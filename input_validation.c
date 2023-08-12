#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

//35 47  		\tcat  \n

bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
  bool formatIsGood = numArgsRead == numArgsNeed;
  char character;
  do{
    scanf("%c", &character); //45  bob  \n
		if(!isspace(character)){ //found a non whitespace character on the way to the end of the line
			formatIsGood = false;
		}
	}while(character != '\n'); //read characters until the end of the line
  return formatIsGood;
}


int getValidInt(const char* prompt){
  int num;
  const int numArgsNeeded = 1;
  int numArgsRead;
  do{
    printf("%s", prompt);
    numArgsRead = scanf(" %d", &num); // waffles 45\n
  }while(!isValidFormat(numArgsRead, numArgsNeeded));

  return num;
}

double getValidDouble(const char* prompt){
  double num;
  const int numArgsNeeded = 1;
  int numArgsRead;
  do{
    printf("%s", prompt);
    numArgsRead = scanf(" %lf", &num); //waffles\n
  }while(!isValidFormat(numArgsRead, numArgsNeeded));

  return num;
}

bool inbetween(int val, int lowerBound, int upperBound){
  return val >= lowerBound && val <= upperBound;
}

int getValidIntInRange(int lowerBound, int upperBound){
  int num;
  do{
    printf("Enter a number between %d-%d: ", lowerBound, upperBound);
    num = getValidInt("");
  }while(!(inbetween(num, lowerBound, upperBound)));

  return num;
}

int getPosInt(){
	int num;
  do{
    num = getValidInt("Enter a positive number: ");
  }while(!(num > 0));

  return num;
}
