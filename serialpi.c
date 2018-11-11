#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#include "dist.c"

int main(int argc, char *argv[]){
	if (argc < 2){
		printf("Useage a.out n\n");
		return 0;
	}
//	printf("test = %lf\n", euclideanDist(0.5,0.5,0.7,0.2));
	int n;	
	if (atoi(argv[1]) == 0)
		n = INT_MAX;
	else
		n = atoi(argv[1]);
	int hits = 0;
	int i;
	srand(time(0));
	double x,y,cx = 0.5 ,cy = 0.5;
	for (i=0;i<n;i++){
			x = ((double)(rand()%1000))/1000;
			y = ((double)(rand()%1000))/1000;
		//	printf("(%lf,%lf)\n", x,y);
		//	printf("dist = %lf\n", euclideanDist(cx,cy,x,y));
			if (euclideanDist(cx,cy,x,y) < 0.5){
				hits++;
			}
	}
	printf("hits = %d\n", hits);
	double pi = 4*((double)hits/(double)n);
	printf("pi = %lf\n",pi );





}
