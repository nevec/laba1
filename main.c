#include <stdio.h>
#include <math.h>

int main()
{
	double c, d, x1, x2, R, D;
	scanf("%lf%lf", &c, &d);
	
	D = 9.0 + 4*c*d;
	
	if (D < 0) {
		printf("Roots don\'t exist\n");
		return 0;
	}
	
	
	x1 = (3.0 + sqrt(D))/2.0;
	x2 = (3.0 - sqrt(D))/2.0;
	
	R = fabs(pow(sin(fabs(c*pow(x1, 3) + d* pow(x2, 2) - c*d)), 3.0) / sqrt( pow(c*pow(x1, 3) + d* pow(x2, 2) - x1, 2)+ 3.14) ); 
	
	printf("result = %.9lf\n", R);
	
	return 0;
}
