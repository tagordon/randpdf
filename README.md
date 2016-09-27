# randpdf

To use randpdf, include "randpdf.h" in your program file. Before calling getrand(), initialize the generator with 

	init(double (*pdf)(double x), double min, double max, unsigned seed) 

where pdf is a function handle to the (normalized) probability density function, min is the 
lower bound of the pdf's domain and max is the upper bound to the domain. 
Seed is an unsigned integer to seed the random number generator. 

To generate random numbers: 

	getrand(void) 

which returns a random number between min and max from the specified pdf. 

Note that the pdf passed to init needs to be normalized so that the total integrated probability is 1.


