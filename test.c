#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "randpdf.h"

double pdf(double x){
	double A = 3.0/8.0;
	return A*x*x;
}

int main(int argc, char **argv){
	inst(pdf,0,2,100000000,987654321);	
	int i;
	for(i=0;i<1000;i++){
		printf("%f\n",getrand());
	}
}
