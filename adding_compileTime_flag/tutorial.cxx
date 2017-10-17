// A simple program that computes the square root of a number
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "TutorialConfig.h"

using std::cout;
using std::endl;

 
int main (int argc, char *argv[])
{
#ifdef USE_MY_FLAG
	cout << "Use my flag on\n";
#else
	cout << "Use my flag OFF\n";
#endif
  if (argc < 2)
    {
		
    /*fprintf(stdout,"%s Version %d.%d\n",
            argv[0],
            Tutorial_VERSION_MAJOR,
            Tutorial_VERSION_MINOR);*/
    fprintf(stdout,"Usage: %s number\n",argv[0]);
    return 1;
    }
  double inputValue = atof(argv[1]);
  double outputValue = sqrt(inputValue);
  fprintf(stdout,"The square root of %g is %g\n",
          inputValue, outputValue);
  return 0;
}