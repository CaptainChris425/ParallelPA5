#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double euclideanDist(double x1, double y1, double x2, double y2){
/*
	printf("%lf , %lf , %lf , %lf\n",x1,y1,x2,y2);
	double dx = x2 - x1;
	printf("dx = %lf\n",dx);
	double dy = y2 - y1;
	printf("dy = %lf\n",dy);
	double adx = fabs(dx); 
	printf("adx = %lf\n",adx);
	double ady = fabs(dy); 
	printf("ady = %lf\n",ady);
	double adx2 = pow(adx,2); 
	printf("adx2 = %lf\n",adx2);
	double ady2 = pow(ady,2); 
	printf("ady2 = %lf\n",ady2);
	double sum = adx2 + ady2;
	printf("sum = %lf\n",sum);
	double sqsum = sqrt(sum);
	printf("sqsum = %lf\n",sqsum);	
*/
	return sqrt(pow(fabs(x2-x1),2) + pow(fabs(y2-y1),2));
}


