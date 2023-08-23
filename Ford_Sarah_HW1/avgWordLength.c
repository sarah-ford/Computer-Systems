// Sarah Ford
// HW1 Problem 2
// count.c  Count the number of lines and chars in the input.

#include <stdio.h>

int main() {
  int lineCount = 0;
  double totalLength = 0; // initialize variable counting total non-space characters
  double avgLength = 0.00;
  int numWords = 0; // initialize variable for number of words
  int spaceCount = 0; // initialize variable for number of spaces in a row
  int numLines = 0;
  int numChars = 0;
  printf("Enter text.  Use an empty line to stop.\n");
  
  while (1) {
      int ic = getchar();
      if (ic < 0)    //EOF encountered
          break;
      char c = (char) ic;
      if (c == '\n' && lineCount == 0) //Empty line
          break; 

	numChars ++;
	totalLength++;

	  if (isspace(c) && c!='\n') { // check if c is a space and not a line break
		  spaceCount++;
		  totalLength--; // decrease total length by one to account for white spaces in numChars
	  }

	  if ((!isspace(c) && spaceCount >= 1)||(!isspace(c) && lineCount == 0 && spaceCount == 0)){
		  numWords++;
		// increase numWords by one if c is not a space and there has just been at least one 			space OR increase numWords by one if c is not a space and there has just been a line 			break and there has not just been a space
	  }
	  if (!isspace(c)) {
		  spaceCount = 0;;
		// return the spaceCount to zero if c is a character
	  }

      if (c == '\n') { // check if c is a line break
          numLines ++;
          lineCount = 0; // return lineCount to zero if c is a line break
	  totalLength--; // decrease total length by one to account for line breaks in numChars
      } 
      else
          lineCount ++;
  }
 
  avgLength = totalLength / numWords;

  printf("Your text has %d characters and %d lines.\n", numChars, numLines);

  printf("Your text has %d words with an average length of %.2f.\n", numWords, avgLength);

  return 0;
}
