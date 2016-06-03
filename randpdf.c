#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "randpdf.h"

double getrand(){
	double x = (double)rand()/(double)RAND_MAX;
	struct Point p = search(cdf,0,divi-1,x);
	return min+dx*(p.x+p.y)/2;
}

int inst(double (*pdf)(double x), double minx, double maxx, int divisions, unsigned seed){
	srand(seed);
	int i;
	divi = divisions;
	max = maxx;
	min = minx;
	dx = (maxx-minx)/divisions;
	double integral = 0;
	cdf = (double *)malloc(divisions*sizeof(double));
	for(i=0;i<divisions;i++){
		integral = integral + pdf(minx+i*dx)*dx;
		cdf[i] = integral;
	}
	return 0;
}

struct Point search(double *array, int start, int end, double value){
	int key = (start+end)/2;
	if(value<array[start] || value>array[end]){
		struct Point p;
		p.x = 0;
		p.y = 0;
		return p;
	}
	if(end-start<=1){
		struct Point p;
		p.x = start;
		p.y = end;
		return p;
	}
	if(array[key]==value){
		struct Point p;
		p.x = key;
		p.y = key+1;
		return p;
	}
	if(array[key]>value){
		return search(array,start,key,value);
	}	
	if(array[key]<value){
		return search(array,key,end,value);
	}
	else{
		struct Point p;
		p.x = 0;
		p.y = 0;
		return p;
	}

}
