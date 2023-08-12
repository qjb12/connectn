#ifndef INPUT_VALIDATION_H
	#define INPUT_VALIDATION_H
	#include <stdbool.h>
	bool isValidFormat(const int numArgsRead, const int numArgsNeed);
	int getValidInt(const char* prompt);
	double getValidDouble(const char* prompt);
	bool inbetween(int val, int lowerBound, int upperBound);
	int getValidIntInRange(int lowerBound, int upperBound);
	int getPosInt();

#endif
