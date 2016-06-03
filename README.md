# randpdf

To use: include "randpdf.h" in your program file. Before generating random 
numbers, initialize the generator with a call to 

	init(double (*pdf)(double x),double min,double max,unsigned seed) 

where pdf is a function handle to the probability density function, min is the 
lower bound of the pdf's domain and max is the upper bound to the domain. 
Seed is an unsigned integer to seed the random number generator. 

After initializing, you can simply use 

	getrand(void) 

which returns a random number between min and max from the specified pdf. 

It is ESSENTIAL that the pdf passed to init() be properly normalized. The 
total integrated probability under the curve should be 1. Otherwise the 
random numbers returned will not be from the correct distribution. 


