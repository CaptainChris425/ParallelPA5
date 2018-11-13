#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <limits.h>
#include <omp.h> 
#include "dist.c"

int main(int argc, char *argv[]){
	if (argc < 3){
		printf("Useage a.out n numthreads\n");
		return 0;
	}
//	printf("test = %lf\n", euclideanDist(0.5,0.5,0.7,0.2));
	int n;	
	//int numthreads = atoi(argv[2]);
int j = 0;
for (j = 1; j<17; j+=1){
	//omp_set_num_threads(numthreads);
	omp_set_num_threads(j);
	if (atoi(argv[1]) == 0)
		n = INT_MAX;
	else
		n = atoi(argv[1]);
	int hits = 0;
	int i;
	//srand(time(0));
	int seed = 1;
	double x,y,cx = 0.5 ,cy = 0.5;
	double start = omp_get_wtime();	
	#pragma omp parallel for private(x,y) reduction (+:hits)	
	for (i=0;i<n;i++){
			x = ((double)(rand_r(&seed)%1000))/1000;
			y = ((double)(rand_r(&seed)%1000))/1000;
			seed *= 2;
		//	printf("(%lf,%lf)\n", x,y);
		//	printf("dist = %lf\n", euclideanDist(cx,cy,x,y));
			if (euclideanDist(cx,cy,x,y) < 0.5){
				hits++;
			}
	}
	double end = omp_get_wtime();
	printf("hits = %d\n", hits);
	double pi = 4*((double)hits/(double)n);
	printf("pi = %.20lf\n",pi );
	printf("Time for %d loops on %d threads = %.16g\n",n,j,end-start);

}





}
